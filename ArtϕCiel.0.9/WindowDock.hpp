#ifndef WINDOWDOCK_HPP
#define WINDOWDOCK_HPP

#include <QDockWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QtWidgets>
#include <QHBoxLayout>
#include <QCheckBox>

class WindowDock : public QDockWidget
{

    Q_OBJECT
    public:
        WindowDock(const QString& title,bool play, QWidget* parent=0) : Play (play),QDockWidget(title,parent){init();};
        ~WindowDock();
    inline void SetFramerateLimit(int FrameTime){Nb_Step->setValue(FrameTime);SlotChangeFrameTime();};

    public slots:
        inline void SlotPlay(){emit EmitPlay();
                                Play=!Play;
                                if (Play)
                                    A_Play->setIcon(QIcon("./data/dock/pause.png"));
                                else
                                    A_Play->setIcon(QIcon("./data/dock/play.png"));
                                };
        inline void SlotOneStepMore(){emit EmitOneStepMore();};
        inline void SlotStop(){emit EmitStop();};
        inline void SlotChangeFrameTime(){emit EmitChangeFrameTime(Nb_Step->value());};
        inline void SlotAddEntityPoint(){emit EmitAddEntityPoint();};
        inline void SlotAddEntityALot(){emit EmitAddEntityALot();};
        inline void SlotAddEntityLine(){emit EmitAddEntityLine();};
        inline void SlotSelect() {EmitSelect();};
        inline void SlotRemoveOne(){EmitRemoveOne();};
        inline void SlotClear(){EmitClear();};
        //void SlotChangeSize(int,int);
        inline void SlotNew(){emit EmitNew();};
        inline void SlotOpen(){emit EmitOpen();};
        inline void SlotSave(){emit EmitSave();};
        void SlotContour(int);
        signals:
        void EmitPlay();
        void EmitOneStepMore();
        void EmitStop();
        void EmitChangeFrameTime(int);
        void EmitAddEntityPoint();
        void EmitAddEntityALot();
        void EmitAddEntityLine();
        void EmitSelect();
        void EmitRemoveOne();
        void EmitClear();
        //void EmitChangeSize(int,int);
        void EmitNew();
        void EmitOpen();
        void EmitSave();
        void EmitContour(bool);

    private:

    bool Play;

        void init();
        QPushButton* A_Play,
               * A_OneStepMore,
               * A_Stop,
               * A_FrameTime,
               * A_EntityPoint,
               * A_EntityALot,
               * A_EntityLine,
               * A_Select,
               * A_RemoveOne,
               * A_Clear,
               * A_Size,
               * A_New,
               * A_Open,
               * A_Save;

        QSpinBox * Nb_Step,
                 * Nb_SizeX,
                 * Nb_SizeY;

        QWidget* conteneur;

        QHBoxLayout* Layout;
        QCheckBox * B_Contour;

};
#endif
