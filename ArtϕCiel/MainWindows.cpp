#include "MainWindows.hpp"

MainWindows::~MainWindows()
{
    //delete ScrollArea;
    delete Layout;
    delete environement;
};

void MainWindows::OnInit()
{
    setWindowTitle(QString::fromUtf8("ArtϕCiel - Maxime Barbier"));
    Layout=new QGridLayout();
    /************** ENVIRONEMENT *************************************/
    EnvViewer=new EnvironementViewer();
    environement=new Environement(MAP_SIZE,MAP_SIZE);
    environement->SetContour(false);
    EnvViewer->SetEnvironement(environement);
    /********************** COURBES **********************************/
    Courbes = new CourbesViewer();
    Courbes->SetMap(&(EnvViewer->Courbes));
    Courbes->SetYMax(&(EnvViewer->YMax));

    /******************** SELCTOR ENTITY ********************************/
    entitySelector= new EntitySelector();
    entitySelector->SetViewer(EnvViewer);
    /*******************  Entity Modification ***************************/
    entityModification = new EntityModification();
    entityModification->SetEnvironementViewer(EnvViewer);

    /******************* CONNECTION *************************************/
    QObject::connect(entitySelector,SIGNAL(EmitSelectedEntity(Entity*)),this,SLOT(SlotSelectedEntity(Entity*)));// a changer
    QObject::connect(entityModification,SIGNAL(HasSave()),entitySelector,SLOT(Maj()));// a changer



     /****************** comportementSelector *****************************/
    comportementSelector = new ComportementSelector();
    comportementSelector->SetSemieSitue(EnvViewer->GetSemieSitues());
    //comportementSelector->SetAbsolue(EnvViewer->GetAbsolues());


    /******************* Comportement Absolue Modification ****************/
    /*absolueModification = new AbsolueModification();
    absolueModification->SetEnvironementViewer(EnvViewer);*/
    /******************* Comportemeznt Semi Situe Modification ************/
    semieSitueModification= new SemieSitueModification();
    semieSitueModification->SetEnvironementViewer(EnvViewer);
    /****************** Connection ****************************************/
    //QObject::connect(comportementSelector,SIGNAL(EmitAbsolueSelected(Absolue*)),this,SLOT(SlotSetComportement(Absolue*)));
    QObject::connect(comportementSelector,SIGNAL(EmitSemiSitueSelected(SemieSitue*)),this,SLOT(SlotSetComportement(SemieSitue*)));
    //QObject::connect(absolueModification,SIGNAL(HasSave()),comportementSelector,SLOT(Maj()));// a changer
    QObject::connect(semieSitueModification,SIGNAL(HasSave()),comportementSelector,SLOT(Maj()));// a changer

    comportementSelector->Maj();
    entitySelector->Maj();

    /************************* MISE EN PALCE DANS LE LAYOUT *******************/
    Select_entity_ScrollArea=new QScrollArea();
    Select_entity_ScrollArea->setWidget(entitySelector);

    Select_Comportements_ScrollArea = new QScrollArea();
    Select_Comportements_ScrollArea->setWidget(comportementSelector);

    Map_ScrollArea = new QScrollArea();
    Map_ScrollArea->setMinimumSize(QSize(800,800));
    Map_ScrollArea->setMaximumSize(QSize(EnvViewer->size().width()+20,EnvViewer->size().height()+20));
    Map_ScrollArea->setWidget(EnvViewer);


    Layout2 = new QHBoxLayout();
    Layout2->addWidget(Map_ScrollArea);

    Layout->addWidget(Courbes,0,1,1,2);
    Layout->addWidget(Select_entity_ScrollArea,1,1,2,1);
    Layout->addWidget(Select_Comportements_ScrollArea,1,2,2,1);


    QWidget* conteneur=new QWidget();
    conteneur->setLayout(Layout);
    conteneur->setMaximumWidth(450);
    Layout2->addWidget(conteneur);


    QWidget* conteneur2 = new QWidget();
    conteneur2->setLayout(Layout2);
    setCentralWidget(conteneur2);

    /********************** DOCK ************************************/
   Dock = new WindowDock(tr("Tool Bar"),false,this);
   addDockWidget(Qt::TopDockWidgetArea, Dock);

   QObject::connect(Dock,SIGNAL(EmitPlay()),this,SLOT(SlotPlay()));
   QObject::connect(Dock,SIGNAL(EmitChangeFrameTime (int)),this,SLOT(SlotChangeFrameTime(int)));
   QObject::connect(Dock,SIGNAL(EmitOneStepMore()),this,SLOT(SlotOneStepMore()));
   QObject::connect(Dock,SIGNAL(EmitStop()),this,SLOT(SlotStop()));
        ///entre Dock et la map
   QObject::connect(Dock,SIGNAL(EmitAddEntityPoint()),EnvViewer,SLOT(SlotAddEntityPoint()));
   QObject::connect(Dock,SIGNAL(EmitAddEntityALot()),EnvViewer,SLOT(SlotAddEntityALot()));
   QObject::connect(Dock,SIGNAL(EmitAddEntityLine()),EnvViewer,SLOT(slotAddEntityLine()));
   QObject::connect(Dock,SIGNAL(EmitRemoveOne()),EnvViewer,SLOT(SlotRemoveOne()));
   QObject::connect(Dock,SIGNAL(EmitSelect()),EnvViewer,SLOT(SlotSelect()));
   QObject::connect(Dock,SIGNAL(EmitClear()),EnvViewer,SLOT(SlotClear()));
   QObject::connect(Dock,SIGNAL(EmitSave()),this,SLOT(SlotWrite()));
   QObject::connect(Dock,SIGNAL(EmitOpen()),this,SLOT(SlotOpen()));
   QObject::connect(Dock,SIGNAL(EmitNew()),this,SLOT(SlotNew()));
   QObject::connect(Dock,SIGNAL(EmitContour(bool)),this,SLOT(SlotContour(bool)));
};

void MainWindows::SlotChangeFrameTime(int T)
{
    EnvViewer->setFramerateLimit(T);
};
void MainWindows::SlotSelectedEntity(Entity* E)
{
    //EnvViewer->HaveToBeInit();
    if (E == PrecedentSelection)
    {
        entityModification->ChangeEntity(E);
        entityModification->exec();
    }

    EnvViewer->SlotSelectedEntity(E);

    PrecedentSelection=E;
};

/*void MainWindows::SlotSetComportement(Absolue* A)
{
    absolueModification->SetComportement(A);
    //EnvViewer->HaveToBeInit();
    absolueModification->exec();
};*/

void MainWindows::SlotSetComportement(SemieSitue* A)
{
    semieSitueModification->SetComportement(A);
    //EnvViewer->HaveToBeInit();
    semieSitueModification->exec();
};

void MainWindows::SlotWrite()
{
    FILE* F=NULL;
    string f = QFileDialog::getSaveFileName(this, tr("Enregister"),"./save/Environement.art",QString::fromUtf8("ArtϕCiel (*.art)")).toStdString();

    if ((F=fopen(f.c_str(),"w+")) != NULL)
        {
            environement->Write(F);
            fclose(F);
        }
    else
        cout<<"Imposible de creer le fichier "<<f<<endl;
};

void MainWindows::SlotOpen()
{
     string f = QFileDialog::getOpenFileName(this, tr("Ouvrir"),"./save", QString::fromUtf8("ArtϕCiel (*.art)")).toStdString();
     environement->LoadFromFile(f.c_str());

     comportementSelector->Maj();
     entitySelector->Maj();

     EnvViewer->HaveToBeInit();
};

void MainWindows::SlotNew()
{
    int res=QMessageBox::critical(this, QString::fromUtf8("ArtϕCiel Vérification"), "Voulez vous vraiment tout Supprimer?",QMessageBox::Yes | QMessageBox::No);

    if ( res ==QMessageBox::Yes )
    {
        environement->ClearAll();
        comportementSelector->Maj();
        entitySelector->Maj();
    }
};

void MainWindows::SlotContour(bool b)
{
    environement->SetContour(b);
};
