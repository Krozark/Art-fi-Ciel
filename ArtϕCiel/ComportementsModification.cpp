#include "ComportementsModification.hpp"

ComportementModification::~ComportementModification()
{
    delete Layout;
    delete S_Proba;
    delete L_nom;
    delete L_Description;
    delete L_Proba;
    delete L_Reactifs;
    delete L_Produits;
    delete B_Save;
    delete T_Nom;
    delete T_Description;
    delete Reactifs;
    delete Produits;
    delete ReactifContainer;
    delete ProduitContainer;
    delete UseEnfRecatifs;
};

void ComportementModification::init()
{
     setWindowTitle(QString::fromUtf8("ArtϕCiel - Modification De Comportements"));
    Layout=new QGridLayout;

    S_Proba= new QDoubleSpinBox;
    S_Proba->setRange(0.0,100.0);
    S_Proba->setDecimals(5);

    L_nom =new QLabel("Nom");
    L_Description = new QLabel("Description");
    L_Proba = new QLabel("Proba");
    L_Reactifs = new QLabel("Reactifs");
    L_Produits = new QLabel("Produits");

    B_Save = new QPushButton("Enregistrer");

    T_Nom = new QLineEdit;
    T_Description = new QTextEdit;

    Reactifs = new QComboBox[9];
    Produits = new QComboBox[9];
    UseEnfRecatifs = new QCheckBox[9];

    EnvViewer=NULL;

    ReactifContainer = new QWidget;
    ProduitContainer = new QWidget;

    int i=0;
    Layout->addWidget(L_nom,i,0);
    Layout->addWidget(T_Nom,i,1);++i;
    Layout->addWidget(L_Proba,i,0);
    Layout->addWidget(S_Proba,i,1);++i;
    Layout->addWidget(L_Description,i,0);
    Layout->addWidget(T_Description,i,1);++i;
    Layout->addWidget(L_Reactifs,i,0);
    Layout->addWidget(L_Produits,i,1);++i;
    Layout->addWidget(ReactifContainer,i,0);
    Layout->addWidget(ProduitContainer,i,1);++i;
    Layout->addWidget(B_Save,i,0);

    setLayout(Layout);

    QObject::connect(B_Save,SIGNAL(clicked()),this,SLOT(save()));
};

void ComportementModification::InitialiseBox(QComboBox* Box)
{
    for (unsigned int i=0; i<9; ++i)
    {
        Box[i].clear();
        vector<Entity>* E= EnvViewer->GetEntities();
        Box[i].addItem("Aucun");

        const unsigned int _size= E->size();
        for (unsigned int j=0;j<_size;++j)
            Box[i].addItem((*E)[j].GetNom().c_str());
    }
};

/*************************************** SEMIE SITUEE ***************************************/
void SemieSitueModification::init()
{
    CurrentReaction = NULL;

    QGridLayout *ReactifLayout = new QGridLayout;
    QVBoxLayout *ProduitsLayout = new QVBoxLayout;

    for (unsigned int i =0; i<9; ++i)
    {
        ReactifLayout->addWidget(&Reactifs[i],i,0);
        ReactifLayout->addWidget(&(UseEnfRecatifs[i]),i,1);
        ProduitsLayout->addWidget(&Produits[i]);
    }

    ReactifContainer->setLayout(ReactifLayout);
    ProduitContainer->setLayout(ProduitsLayout);
};

void SemieSitueModification::save()
{
    CurrentReaction->SetProbabilite(S_Proba->value());
    CurrentReaction->SetNom(T_Nom->text().toStdString());
    CurrentReaction->SetDescription(T_Description->toPlainText().toStdString());

    CurrentReaction->Reactif_use_parent.clear();

    vector<Entity*> v;
    for (unsigned int i=0;i<9;++i)
        if (Reactifs[i].currentIndex() >0)
        {
            v.push_back(EnvViewer->GetEntityByName(Reactifs[i].currentText().toStdString()));
            CurrentReaction->Reactif_use_parent.push_back(UseEnfRecatifs[i].isChecked());
        }
    CurrentReaction->SetReactif(v);

    v.clear();
    for (unsigned int i=0;i<9;++i)
        if (Produits[i].currentIndex() >0)
            v.push_back(EnvViewer->GetEntityByName(Produits[i].currentText().toStdString()));
    CurrentReaction->SetProduits(v);



    hide();
    emit HasSave();
    EnvViewer->HaveToBeInit();
};

void SemieSitueModification::Initialise()
{
    InitialiseBox(Reactifs);
    InitialiseBox(Produits);

    S_Proba->setValue(CurrentReaction->GetProbabilite());
    T_Nom->setText(CurrentReaction->GetNom().c_str());
    T_Description->setText(CurrentReaction->GetDescription().c_str());

    unsigned int _size=CurrentReaction->Reactifs.size();
    Entity* P;

    for (unsigned int i=0;i<9;++i)
        UseEnfRecatifs[i].setChecked(false);

    for (unsigned int i=0;i<_size;++i)
        if ((P=CurrentReaction->Reactifs[i]) != NULL)
        {
            Reactifs[i].setCurrentIndex(Reactifs[i].findText(P->GetNom().c_str()));
            UseEnfRecatifs[i].setChecked(CurrentReaction->Reactif_use_parent[i]);
        }
        else
            Reactifs[i].setCurrentIndex(0);

    for (unsigned int i =_size;i<9;++i)
        Reactifs[i].setCurrentIndex(0);

    _size=CurrentReaction->Produits.size();

    for (unsigned int i=0;i<_size;++i)
        if ((P=CurrentReaction->Produits[i]) != NULL)
            Produits[i].setCurrentIndex(Produits[i].findText(P->GetNom().c_str()));
        else
            Produits[i].setCurrentIndex(0);
    for (unsigned int i =_size;i<9;++i)
        Produits[i].setCurrentIndex(0);
};
