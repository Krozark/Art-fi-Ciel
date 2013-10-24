#ifndef COMPORTEMENT_SELECTOR_HPP
#define COMPORTEMENT_SELECTOR_HPP

#include <QWidget>
#include <QVBoxLayout>
#include "PushButtonIndex.hpp"
#include "reaction.hpp"


class ComportementSelector : public QWidget
{
    Q_OBJECT
    public:
        ComportementSelector(QWidget* parent=0):QWidget(parent)
        {
            SemieSitue_tab=NULL;
            //Absolue_tab=NULL;
            Layout=NULL;
        }

        void SetSemieSitue(vector <SemieSitue>* v){SemieSitue_tab=v;};
        //void SetAbsolue(vector <Absolue>* v){Absolue_tab=v;};

    public slots:
        void SlotSemiSitueSelected(int);
        //void SlotAbsolueSelected(int);
        inline void Maj(){init();};
    signals:
        void EmitSemiSitueSelected(SemieSitue*);
        //void EmitAbsolueSelected(Absolue*);
    private :
        void init();
        vector <SemieSitue>* SemieSitue_tab;
        //vector <Absolue>* Absolue_tab;
        vector<QPushButtonIndex*> Buttons;
        QVBoxLayout* Layout;
};

#endif
