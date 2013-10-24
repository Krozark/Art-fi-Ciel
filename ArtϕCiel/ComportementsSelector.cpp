#include "ComportementsSelector.hpp"

void ComportementSelector::init()
{
    const unsigned int SemieSize = SemieSitue_tab->size();
    //const unsigned int AbsolueSize = Absolue_tab->size();
    const unsigned int _size_Button=Buttons.size();

    if (Layout != NULL)
        delete Layout;
    Layout=new QVBoxLayout;

    for(unsigned int i=0;i<_size_Button;++i)
    {
        Buttons[i]->disconnect();
        delete Buttons[i];
    }
    /************************ SEMIE Situees *********************************/
    Buttons.clear();
    QPushButtonIndex *n=new QPushButtonIndex(-1,"= SemieSituee =");
    n->setStyleSheet("* { background-color: rgb(0,255,0) }");
    Buttons.push_back(n);
    QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotSemiSitueSelected(int)));
    Layout->addWidget(n);

    for (unsigned int i=0;i<SemieSize;++i)
    {

        n=new QPushButtonIndex(i,(*SemieSitue_tab)[i].GetNom().c_str());

        Buttons.push_back(n);
        QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotSemiSitueSelected(int)));
        Layout->addWidget(n);
    }

    /******************* Absolue *******************************/
    /*n=new QPushButtonIndex(-1,"= Absolue =");
    n->setStyleSheet("* { background-color: rgb(0,255,0) }");
    Buttons.push_back(n);
    QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotAbsolueSelected(int)));
//    Layout->addWidget(n);

    for (unsigned int i=0;i<AbsolueSize;++i)
    {

        n=new QPushButtonIndex(i,(*Absolue_tab)[i].GetNom().c_str());

        Buttons.push_back(n);
        QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotAbsolueSelected(int)));
        Layout->addWidget(n);
    }

    resize(200,(SemieSize+AbsolueSize+2)*40);*/
    resize(200,(SemieSize+2)*40);
    setLayout(Layout);
};

void ComportementSelector::SlotSemiSitueSelected(int i)
{
    if (i>=0)
    {
        emit EmitSemiSitueSelected(&((*SemieSitue_tab)[i]));
    }
    else
    {
        //creation de la nouvelle et ajout
        SemieSitue ss;
        SemieSitue_tab->push_back(ss);
        init();
    }
};

/*void ComportementSelector::SlotAbsolueSelected(int i)
{
    if (i>=0)
    {
        emit EmitAbsolueSelected(&((*Absolue_tab)[i]));
    }
    else
    {
        //creation de la nouvelle et ajout
        Absolue abs;
        Absolue_tab->push_back(abs);
        init();
    }
};*/
