#include "EntitySelector.hpp"
#include <iostream>
#include <sstream>

void EntitySelector::init()
{
    vector <Entity>* entites=EnvViewer->GetEntities();
    const unsigned int _size=entites->size();
    const unsigned int _size_Button=Buttons.size();

    if (Layout != NULL)
        delete Layout;
    Layout=new QVBoxLayout;

    for(unsigned int i=0;i<_size_Button;++i)
    {
        Buttons[i]->disconnect();
        delete Buttons[i];
    }

    Buttons.clear();
    QPushButtonIndex *n=new QPushButtonIndex(-1,"= Entites =");
    n->setStyleSheet("* { background-color: rgb(0,255,0) }");
    Buttons.push_back(n);
    QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotSelectdEntity(int)));
    Layout->addWidget(n);


    for (unsigned int i=0;i<_size;++i)
    {

        n=new QPushButtonIndex(i,(*entites)[i].GetNom().c_str());

        stringstream out;
        out<<"* { background-color: rgb("<<(int)(*entites)[i].couleur.r<<","<<(int)(*entites)[i].couleur.g<<","<<(int)(*entites)[i].couleur.b<<") }";
        n->setStyleSheet(out.str().c_str());

        Buttons.push_back(n);
        QObject::connect(n,SIGNAL(EmitIndex(int)),this,SLOT(SlotSelectdEntity(int)));
        QObject::connect(n,SIGNAL(EmitRemove(int)),this,SLOT(SlotRemove(int)));
        Layout->addWidget(n);
    }

    resize(150,(_size+1)*40);
    setLayout(Layout);
};


void EntitySelector::SlotSelectdEntity(int i)
{
    vector <Entity>* entites=EnvViewer->GetEntities();
    if (i<0)//new
    {
        Entity n;
        EnvViewer->AddEntity(n);

        i= entites->size()-1;

        QPushButtonIndex* b=new QPushButtonIndex(i,(*entites)[i].GetNom().c_str());
        Buttons.push_back(b);

        init();
    }
    emit EmitSelectedEntity(&((*entites)[i]));
};

void EntitySelector::SlotRemove(int i)
{
    EnvViewer->RemoveEntity(i);
    Layout->removeWidget((Buttons[i+1]));
    Buttons[i+1]->setParent(0);
    resize(150,(size().height())-40);
};
