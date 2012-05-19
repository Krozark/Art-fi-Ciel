#ifndef ENVIRONEMENTVIEWER_HPP
#define ENVIRONEMENTVIEWER_HPP

#include "QSFMLCanvas.hpp"
#include "environement.hpp"

#include <iostream>

enum Action{ADD_ONE=0,ADD_LOT,ADD_LINE,SELECTED,REMOVE,RIEN};

typedef struct Element2Point
{
    unsigned int x1,x2,y1,y2;
}_2Point;

class EnvironementViewer : public QSFMLCanvas
{

    Q_OBJECT
    public:
        EnvironementViewer(QWidget* Parent=0,const QPoint& Position=QPoint(0,0), const QSize& Size=QSize(MAP_SIZE*PAS_DEPLACEMENT,MAP_SIZE*PAS_DEPLACEMENT),const unsigned int FrameTime=0) : QSFMLCanvas(Parent,Position,Size,FrameTime)
        {
            environement=NULL;
            IsPlay=false;
            setMinimumSize(Size);

            action=RIEN;
            CurrentSelectedEntity=NULL;
            //Zoom=1;

        };
        ~EnvironementViewer();

        inline void SetEnvironement(Environement* Env){environement=Env;};
        inline void Play(){IsPlay=true;action=RIEN;};
        inline void Pause(){IsPlay=false;action=RIEN;};
        void Stop();
        inline bool IsPlayed(){return IsPlay;};
        inline bool IsStoped(){return !IsPlay;};
        inline void AddEntity(const Entity& E){environement->AddEntity(E);Courbes.resize(Entity::GetMaxIndex());};
        inline void Exchange(std::string original,std::string nouveau){environement->Exchange(original,nouveau);};
        inline void HaveToBeInit(){environement->HaveToBeInitialise();};
        inline void NextStep(){if (!IsPlay){IsPlay=true;OnUpdate();IsPlay=false;}};
        inline vector<Entity>* GetEntities(){return environement->GetEntities();};
        inline vector<SemieSitue>* GetSemieSitues(){return environement->GetSemieSitues();};
        //inline vector<Absolue>* GetAbsolues(){return environement->GetAbsolues();};

        inline Entity* GetEntityByName(const string& name){return environement->GetEntityByName(name);};
        inline void RemoveEntity(int i){environement->RemoveEntity(i);};

        inline vector<unsigned int>* GetComptage(){return &(environement->Comptage_entity);};

        vector< vector<unsigned int> > Courbes;

        unsigned int YMax;

        void mousePressEvent ( QMouseEvent * event );       //permet de gere les evenement souris lors du click
        void mouseReleaseEvent (QMouseEvent *event);        //permet de gerer les evenemetn souris lors du relachement
        void mouseMoveEvent ( QMouseEvent * event );        //permet de gere les evenement souris lors de son deplacement
      //  void keyPressEvent (QKeyEvent * event);             //permet de gere les evenement clavier (raccourcis)
       // void keyReleaseEvent ( QKeyEvent * event );         //permet de gere les evenement clavier (stop des raccourcis)


    public slots:
        void SlotSelectedEntity(Entity* );
        void SlotAddEntityPoint(){action=ADD_ONE;};
        void SlotAddEntityALot(){action=ADD_LOT;};
        void slotAddEntityLine(){action=ADD_LINE;};
        void SlotRemoveOne(){action= REMOVE;};
        void SlotSelect(){action=SELECTED;};
        void SlotClear(){environement->Clear();};

    private:
        void OnInit();
        void OnUpdate();
        bool IsPlay;
        Environement* environement;
        long unsigned int NbBoucles;
        Entity * CurrentSelectedEntity;
        void bresenham(int,int,int,int);

        Action action;
        //double Zoom; // <0 : eloigne >0 Zoom

        _2Point MoussPoint;
};
#endif
