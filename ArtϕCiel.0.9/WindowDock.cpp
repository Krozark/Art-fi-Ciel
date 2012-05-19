#include "WindowDock.hpp"

WindowDock::~WindowDock()
{
    delete A_Play;
    delete A_OneStepMore,
    delete A_Stop;
    delete A_FrameTime;
    delete A_EntityPoint;
    delete A_EntityALot;
    delete A_EntityLine;
    delete A_Select;
    delete A_RemoveOne;
    delete A_Clear;
    delete A_Size;
    delete A_New;
    delete A_Open,
    delete A_Save;

    delete Nb_Step;
    delete Nb_SizeX;
    delete Nb_SizeY;

    delete conteneur;
};

void WindowDock::init()
{
    setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);

    conteneur=new QWidget(this);

    A_Play = new QPushButton();
     if (Play)
        A_Play->setIcon(QIcon("./data/dock/pause.png"));
    else
        A_Play->setIcon(QIcon("./data/dock/play.png"));
    A_Play->setToolTip(tr("Play/Pause"));

    A_OneStepMore = new QPushButton();
    A_OneStepMore->setIcon(QIcon("./data/dock/step.png"));
    A_OneStepMore->setToolTip(tr("++Step"));

    A_Stop = new QPushButton();
    A_Stop->setIcon(QIcon("./data/dock/stop.png"));
    A_Stop->setToolTip(tr("Stop"));

    A_FrameTime = new QPushButton();
    A_FrameTime->setIcon(QIcon("./data/dock/V.png"));
    A_FrameTime->setToolTip(tr("Change Speed"));

    A_EntityPoint = new QPushButton();
    A_EntityPoint->setIcon(QIcon("./data/dock/crayon.png"));
    A_EntityPoint->setToolTip(tr("Add One Entity"));

    A_EntityALot = new QPushButton();
    A_EntityALot->setIcon(QIcon("./data/dock/alot.png"));
    A_EntityALot->setToolTip(tr("Add Some Entity"));

    A_EntityLine = new QPushButton();
    A_EntityLine->setIcon(QIcon("./data/dock/ligne.png"));
    A_EntityLine->setToolTip(tr("Add a line of Entity"));

    A_Select = new QPushButton();
    A_Select->setIcon(QIcon("./data/dock/select.png"));
    A_Select->setToolTip(tr("Select"));

    A_RemoveOne = new QPushButton();
    A_RemoveOne->setIcon(QIcon("./data/dock/gomme.png"));
    A_RemoveOne->setToolTip(tr("Remove Entity"));

    A_Clear = new QPushButton();
    A_Clear->setIcon(QIcon("./data/dock/annuler.png"));
    A_Clear->setToolTip(tr("Clean the map"));

    A_Size = new QPushButton();
    A_Size->setIcon(QIcon("./data/dock/V.png"));
    A_Size->setToolTip(tr("Change de map size"));

    A_New = new QPushButton();
    A_New->setIcon(QIcon("./data/dock/new.png"));
    A_New->setToolTip(tr("New pyroject"));

    A_Open = new QPushButton();
    A_Open->setIcon(QIcon("./data/dock/open.png"));
    A_Open->setToolTip(tr("Open project"));

    A_Save = new QPushButton();
    A_Save->setIcon(QIcon("./data/dock/save.png"));
    A_Save->setToolTip(tr("Save project"));

    B_Contour = new QCheckBox("Contour");
    B_Contour->setToolTip(tr("Contour?"));

    QObject::connect(A_Play,SIGNAL(clicked()),this,SLOT(SlotPlay()));
    QObject::connect(A_OneStepMore,SIGNAL(clicked()),this,SLOT(SlotOneStepMore()));
    QObject::connect(A_Stop,SIGNAL(clicked()),this,SLOT(SlotStop()));

    QObject::connect(A_FrameTime,SIGNAL(clicked()),this,SLOT(SlotChangeFrameTime()));

    QObject::connect(A_EntityPoint,SIGNAL(clicked()),this,SLOT(SlotAddEntityPoint()));
    QObject::connect(A_EntityALot,SIGNAL(clicked()),this,SLOT(SlotAddEntityALot()));
    QObject::connect(A_EntityLine,SIGNAL(clicked()),this,SLOT(SlotAddEntityLine()));

    QObject::connect(A_RemoveOne,SIGNAL(clicked()),this,SLOT(SlotRemoveOne()));
    QObject::connect(A_Select,SIGNAL(clicked()),this,SLOT(SlotSelect()));
    QObject::connect(A_Clear,SIGNAL(clicked()),this,SLOT(SlotClear()));

    QObject::connect(A_New,SIGNAL(clicked()),this,SLOT(SlotNew()));
    QObject::connect(A_Open,SIGNAL(clicked()),this,SLOT(SlotOpen()));
    QObject::connect(A_Save,SIGNAL(clicked()),this,SLOT(SlotSave()));
    QObject::connect(B_Contour,SIGNAL(stateChanged(int)),this,SLOT(SlotContour(int)));


    Nb_Step = new QSpinBox();
    Nb_Step->setRange(0,999);
    Nb_Step->setValue(1);

    Nb_SizeX = new QSpinBox();
    Nb_SizeX->setRange(1,500);

    Nb_SizeY = new QSpinBox();
    Nb_SizeY->setRange(1,500);

    Layout = new QHBoxLayout();

    Layout->addWidget(A_Play);
    Layout->addWidget(A_OneStepMore);
    Layout->addWidget(A_Stop);
    Layout->addWidget(Nb_Step);
    Layout->addWidget(A_FrameTime);
    Layout->addWidget(B_Contour);
    Layout->addWidget(A_EntityPoint);
    Layout->addWidget(A_EntityALot);
    Layout->addWidget(A_EntityLine);
    Layout->addWidget(A_Select);
    Layout->addWidget(A_RemoveOne);
    Layout->addWidget(A_Clear);
    /*Layout->addWidget(Nb_SizeX);
    Layout->addWidget(Nb_SizeY);
    Layout->addWidget(A_Size);*/
    Layout->addWidget(A_New);
    Layout->addWidget(A_Open);
    Layout->addWidget(A_Save);


    conteneur->setLayout(Layout);
    setWidget(conteneur);
};

void WindowDock::SlotContour(int b)
{
    emit EmitContour((bool)b);
};
