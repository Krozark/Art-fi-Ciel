#ifndef COURBESVIEWER_HPP
#define COURBESVIEWER_HPP

#include "QSFMLCanvas.hpp"
#include "EnvironementViewer.hpp"

class CourbesViewer : public QSFMLCanvas
{
    public:
        CourbesViewer(QWidget* Parent=0,const QPoint& Position=QPoint(0,0), const QSize& Size=QSize(300,200),const unsigned int FrameTime=0) : QSFMLCanvas(Parent,Position,Size,FrameTime)
        {
            Courbes_pt=NULL;
            YMax_1=0;
            setMinimumSize(Size);
        };

        void SetMap(vector< vector<unsigned int> >* C){Courbes_pt=C;};
        void SetYMax(unsigned int* Y){YMax=Y;};
        void Stop(){YMax_1=0;};
        void NextStep(){OnUpdate();};

    private:
        void OnInit();
        void OnUpdate();

        vector <vector<unsigned int> >* Courbes_pt;
        unsigned int* YMax;
        unsigned int YMax_1;

protected:
        void resizeEvent ( QResizeEvent * event );

};

#endif
