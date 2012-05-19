#include "CourbesViewer.hpp"

#define MAX_X_COURBE 200

#include <sstream>
#include <iostream>

void CourbesViewer::OnInit()
{

};

void CourbesViewer::OnUpdate()
{
    for (int i=Courbes_pt->size()-1;i>=0;--i) //pour toutes les entitées
    {
        vector <unsigned int >* vec=&((*Courbes_pt)[i]);
        const unsigned int size2=vec->size();

        if (YMax_1<*YMax)
        {
            YMax_1=*YMax;
            sf::View CurrentView(sf::FloatRect(0,0,MAX_X_COURBE,YMax_1));
            SetView(CurrentView);
        }

        if (size2>0)
        {
            Entity* E =Environement::GetEntityOnIndex(i);
            if (E == NULL)
                continue;
            sf::Color C= E->couleur;
            for (unsigned int j=1;j<size2;++j) //pour tous les point
            {
                 sf::ConvexShape Line(4);
                 Line.SetOutlineColor(C);
                 Line.SetFillColor(C);
                 Line.SetOutlineThickness(3);

                 Line.SetPoint(0,sf::Vector2f(j,YMax_1-(*vec)[j]));
                 Line.SetPoint(3,sf::Vector2f(j,YMax_1-(*vec)[j]));
                 Line.SetPoint(1,sf::Vector2f(j-1,YMax_1-(*vec)[j-1]));
                 Line.SetPoint(2,sf::Vector2f(j-1,YMax_1-(*vec)[j-1]));

                 Draw(Line);

            }

            if (size2>MAX_X_COURBE)
                vec->erase(vec->begin(),vec->begin()+1);
        }
    }
};

void CourbesViewer::resizeEvent(QResizeEvent * event)
{
    sf::View CurrentView(sf::FloatRect(0,0,MAX_X_COURBE,YMax_1));
    SetView(CurrentView);
};

