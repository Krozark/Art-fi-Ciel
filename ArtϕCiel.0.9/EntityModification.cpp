#include "EntityModification.hpp"
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

EntityModification::~EntityModification()
{
    delete L_nom;
    delete L_Parent;
    delete L_deplacement;
    delete L_DemieVie;
    delete L_description;

    delete S_00;
    delete S_01;
    delete S_02;
    delete S_10;
    delete S_12;
    delete S_20;
    delete S_21;
    delete S_22;
    delete S_DemieVie;

    delete T_Description;

    delete B_Parent;

    delete T_Nom;

    delete B_Color;
    delete B_Image;
    delete B_Save;
};


void EntityModification::Save()
{
    string original = CurrentEntity->GetNom();
    if (original != T_Nom->text().toStdString())
        if (EnvViewer->GetEntityByName(T_Nom->text().toStdString()) != NULL)
        {
            QMessageBox::critical(this, "Erreur", "Le nom de l'entitée existe déjà, veuiller le changer.",QMessageBox::Ok);
            return;
        }
    CurrentEntity->SetNom(T_Nom->text().toStdString());
    CurrentEntity->SetDemieVie(S_DemieVie->value());
    CurrentEntity->SetDescription(T_Description->toPlainText().toStdString());

    if (B_Parent->currentIndex() >0)
            CurrentEntity->parents[0]=B_Parent->currentText().toStdString();

    if (B_Parent2->currentIndex() >0)
            CurrentEntity->parents[1]=B_Parent2->currentText().toStdString();

    unsigned int d[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP];


    d[0][0] = S_00->value();
    d[0][1] = S_01->value();
    d[0][2] = S_02->value();

    d[1][0] = S_10->value();
    d[1][1] = 0;
    d[1][2] = S_12->value();

    d[2][0] = S_20->value();
    d[2][1] = S_21->value();
    d[2][2] = S_22->value();

    CurrentEntity->SetDeplacement(d);

    if (FileName != "")
        CurrentEntity->SetImage(FileName);

    emit HasSave();
    EnvViewer->Exchange(original,CurrentEntity->GetNom());
    hide();
};

void EntityModification::init()
{
    setWindowTitle(QString::fromUtf8("ArtϕCiel - Modification D'entitées"));
    EnvViewer=NULL;

    L_nom = new QLabel("Nom"); // pour afficher les légendes
    L_Parent = new QLabel("Parent1");
    L_Parent2 = new QLabel("Parent2");
    L_deplacement = new QLabel(QString::fromUtf8("Déplacement"));
    L_DemieVie = new QLabel("Demie Vie");
    L_description =new QLabel("Description");

    S_00 = new QSpinBox(); // pour gérer les déplacements
    S_00->setRange(0,500);

    S_01 = new QSpinBox();
    S_01->setRange(0,500);

    S_02 = new QSpinBox();
    S_02->setRange(0,500);

    S_10 = new QSpinBox();
    S_10->setRange(0,500);

    S_12 = new QSpinBox();
    S_12->setRange(0,500);

    S_20 = new QSpinBox();
    S_20->setRange(0,500);

    S_21 = new QSpinBox();
    S_21->setRange(0,500);

    S_22 = new QSpinBox();
    S_22->setRange(0,500);

    S_DemieVie = new QSpinBox();
    S_DemieVie->setRange(0,9999);

    QWidget * Conteneur = new QWidget();
    QGridLayout * LayoutConteneur = new QGridLayout();

    LayoutConteneur->addWidget(S_00,0,0);
    LayoutConteneur->addWidget(S_01,0,1);
    LayoutConteneur->addWidget(S_02,0,2);

    LayoutConteneur->addWidget(S_10,1,0);
    LayoutConteneur->addWidget(S_12,1,2);

    LayoutConteneur->addWidget(S_20,2,0);
    LayoutConteneur->addWidget(S_21,2,1);
    LayoutConteneur->addWidget(S_22,2,2);
    Conteneur->setLayout(LayoutConteneur);

    T_Description = new QTextEdit(); //description de l'entitées

    B_Parent = new QComboBox(); // selection du parent
    B_Parent2 = new QComboBox(); // selection du parent

    T_Nom = new QLineEdit();

    B_Color = new QPushButton("Couleur");
    QObject::connect(B_Color,SIGNAL(clicked()),this,SLOT(SetColor()));
    B_Image = new QPushButton("Image");
    QObject::connect(B_Image,SIGNAL(clicked()),this,SLOT(SetImage()));
    B_Save = new QPushButton("Enregistrer");
    QObject::connect(B_Save,SIGNAL(clicked()),this,SLOT(Save()));
        //QColorDialog * F_ColorSelector;
        //QFileDialog * F_ImageSelector;
    int i=0;
    Layout = new QGridLayout();
    Layout->addWidget(L_nom,i,0);
    Layout->addWidget(T_Nom,i,1);++i;
    Layout->addWidget(L_Parent,i,0);
    Layout->addWidget(B_Parent,i,1);++i;
    Layout->addWidget(L_Parent2,i,0);
    Layout->addWidget(B_Parent2,i,1);++i;
    Layout->addWidget(B_Color,i,0);
    Layout->addWidget(B_Image,i,1);++i;
    Layout->addWidget(L_deplacement,i,0);
    Layout->addWidget(Conteneur,i,1,3,3);i+=3;
    Layout->addWidget(L_DemieVie,i,0);
    Layout->addWidget(S_DemieVie,i,1);++i;
    Layout->addWidget(L_description,i,0);
    Layout->addWidget(T_Description,i,1,2,2);++i;
    Layout->addWidget(B_Save,i,0);
    setLayout(Layout);

    CurrentEntity = NULL;
};

void EntityModification::Initialise()
{
    if (CurrentEntity != NULL)
    {
        T_Nom->setText(CurrentEntity->GetNom().c_str());
        InitialiseParent();
        S_DemieVie->setValue(CurrentEntity->GetDemieVie());
        T_Description->setText(CurrentEntity->GetDescription().c_str());

        int index;

        if (CurrentEntity->parents[0] != "")
            B_Parent->setCurrentIndex(((index=B_Parent->findText(CurrentEntity->parents[0].c_str()))>0)?index:0);
        else
            B_Parent->setCurrentIndex(0);

        if (CurrentEntity->parents[1] != "")
            B_Parent2->setCurrentIndex(((index=B_Parent->findText(CurrentEntity->parents[1].c_str()))>0)?index:0);
        else
            B_Parent2->setCurrentIndex(0);

        unsigned int d[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP];
        CurrentEntity->GetDeplacement(d);
        S_00->setValue(d[0][0]);
        S_01->setValue(d[0][1]);
        S_02->setValue(d[0][2]);

        S_10->setValue(d[1][0]);
        S_12->setValue(d[1][2]);

        S_20->setValue(d[2][0]);
        S_21->setValue(d[2][1]);
        S_22->setValue(d[2][2]);

        FileName="";
    }
};

void EntityModification::InitialiseParent()
{
    B_Parent->clear();
    B_Parent2->clear();
    vector<Entity>* E= EnvViewer->GetEntities();
    B_Parent->addItem("Aucun");
    B_Parent2->addItem("Aucun");
    const unsigned int _size= E->size();
    for (unsigned int i=0;i<_size;++i)
    {
        B_Parent->addItem((*E)[i].GetNom().c_str());
        B_Parent2->addItem((*E)[i].GetNom().c_str());
    }
};

void EntityModification::SetColor()
{

    QColor C(CurrentEntity->couleur.r,CurrentEntity->couleur.g,CurrentEntity->couleur.b);
    C=QColorDialog::getColor (C, this,QString::fromUtf8("ArtϕCiel - Choix de couleur"));
    int r,g,b;
    C.getRgb(&r,&g,&b);
    CurrentEntity->couleur.r=r;
    CurrentEntity->couleur.g=g;
    CurrentEntity->couleur.b=b;

    emit HasSave();
};

void EntityModification::SetImage()
{
    FileName = QFileDialog::getOpenFileName(this, tr("Open File"),"./images", tr("Images (*.bmp *.tga *.png *.jpg *.dds *.psd *.hdr)")).toStdString();
};
