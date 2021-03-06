#ifndef MAINWINDOWS_HPP
#define MAINWINDOWS_HPP

#include <QtGui>
#include "WindowDock.hpp"
#include "EnvironementViewer.hpp"
#include "CourbesViewer.hpp"
#include "EntitySelector.hpp"
#include "EntityModification.hpp"
#include "ComportementsSelector.hpp"
#include "ComportementsModification.hpp"

#include "environement.hpp"
#define FRAME_TIME 15

class MainWindows : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindows(QWidget* Parent=0, unsigned int FrameTime =FRAME_TIME): QMainWindow(Parent)
    {
        OnInit();
        SetFramerateLimit(FrameTime);
        EnvViewer->Stop();
        stop=true;
        PrecedentSelection= NULL;
    };

    inline void LoadFromFile(const char* File){environement->LoadFromFile(File);};
    inline void SetFramerateLimit(int FrameTime){Dock->SetFramerateLimit(FrameTime);};

    ~MainWindows();
    public slots:
        void SlotPlay(){if(EnvViewer->IsPlayed())EnvViewer->Pause();else EnvViewer->Play(); stop=false;};
        void SlotChangeFrameTime(int);
        inline void SlotOneStepMore(){EnvViewer->NextStep();Courbes->NextStep();};
        void SlotStop(){if (!stop){EnvViewer->Stop();Courbes->Stop();}stop=true;};
        void SlotSelectedEntity(Entity*);
        //void SlotSetComportement(Absolue*);
        void SlotSetComportement(SemieSitue*);
        void SlotWrite();
        void SlotOpen();
        void SlotNew();
        void SlotContour(bool);
private:

    void OnInit();
    bool stop;
    QScrollArea* Select_entity_ScrollArea,
               * Select_Comportements_ScrollArea,
               * Map_ScrollArea;
    QGridLayout* Layout;
    QHBoxLayout* Layout2;

    WindowDock* Dock;

    EnvironementViewer* EnvViewer;
    Environement* environement;

    CourbesViewer* Courbes;
    EntitySelector* entitySelector;
    EntityModification * entityModification;

    ComportementSelector* comportementSelector;
    //AbsolueModification* absolueModification;
    SemieSitueModification * semieSitueModification;

    Entity* PrecedentSelection;

};

#endif
