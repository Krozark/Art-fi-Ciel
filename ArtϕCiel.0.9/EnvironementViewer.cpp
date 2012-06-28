#include "EnvironementViewer.hpp"

EnvironementViewer::~EnvironementViewer()
{

};


void EnvironementViewer::OnInit()
{
    NbBoucles=0;
    YMax=0;
    MoussPoint.x1= MoussPoint.y1= MoussPoint.x2= MoussPoint.y2=0;
};


void EnvironementViewer::OnUpdate()
{
    if (IsPlay)
    {
        environement->Draw(this);
        vector<unsigned int>* cpt =&(environement->Comptage_entity);
        if (Entity::GetMaxIndex() > Courbes.size())
            Courbes.resize(Entity::GetMaxIndex());
         for (int i=Entity::GetMaxIndex() -1; i>=0;--i)
         {
            //on recupere le nombre d'entite pour chaque type
            Courbes[i].push_back((*cpt)[i]);
            if (YMax<(*cpt)[i])
                YMax=(*cpt)[i];

         }
        NbBoucles++;
    }
    else
    {
        environement->JustDraw(this);
        if (MoussPoint.x1 && MoussPoint.y1 && MoussPoint.x2 && MoussPoint.y2)
        {
            if (action ==  ADD_LINE)
            {
                if (CurrentSelectedEntity != NULL)
                {
                    sf::ConvexShape Line(4);
                    Line.setOutlineThickness(1);
                    Line.setPoint(0,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
                    Line.setPoint(3,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
                    Line.setPoint(1,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
                    Line.setPoint(2,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
                    Line.setOutlineColor(sf::Color::Green);
                    Line.setFillColor(sf::Color::Green);
                    draw(Line);
                }
            }
            else  if (action ==  SELECTED)
            {
                sf::ConvexShape shape(4);
                shape.setFillColor(sf::Color::Transparent);
                shape.setOutlineColor(sf::Color::Green);
                shape.setOutlineThickness(1);

                shape.setPoint (0,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
                shape.setPoint (1,sf::Vector2f(MoussPoint.x2,MoussPoint.y1));
                shape.setPoint (2,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
                shape.setPoint (3,sf::Vector2f(MoussPoint.x1,MoussPoint.y2));

                draw(shape);
            }
        }
    }

};

void EnvironementViewer::Stop()
{
    if (!IsPlay)
    {
        environement->Stop();
        Courbes.clear();
        NbBoucles=0;
        YMax=0;
        environement->JustDraw(this);
    }
    action=RIEN;
};


void EnvironementViewer::SlotSelectedEntity(Entity* E)
{
    CurrentSelectedEntity = E;
};

void EnvironementViewer::mousePressEvent ( QMouseEvent * event )//permet de gere les evenement souris lors du click
{
    switch (action)
    {
        case ADD_LINE:
        case SELECTED:
            MoussPoint.x1= event->pos().x();
            MoussPoint.y1= event->pos().y();
         break;



         default:
         break;
    }
};

void EnvironementViewer::mouseReleaseEvent (QMouseEvent *event)        //permet de gerer les evenemetn souris lors du relachement
{
     if (action ==ADD_LINE)
     {
        //ajout des entitées
        //on met les coordonées en coordonées pour les entitées
        if (CurrentSelectedEntity != NULL)
            bresenham(MoussPoint.x1/PAS_DEPLACEMENT,MoussPoint.y1/PAS_DEPLACEMENT,MoussPoint.x2/PAS_DEPLACEMENT,MoussPoint.y2/PAS_DEPLACEMENT);
     }
     else if (action ==SELECTED )
     {


        MoussPoint.x1/=PAS_DEPLACEMENT;
        MoussPoint.y1/=PAS_DEPLACEMENT;
        MoussPoint.x2/=PAS_DEPLACEMENT;
        MoussPoint.y2/=PAS_DEPLACEMENT;

        int incx=(MoussPoint.x1<MoussPoint.x2)?1:-1;
        int incy=(MoussPoint.y1<MoussPoint.y2)?1:-1;

        for (unsigned int j=MoussPoint.y1;j!=MoussPoint.y2 && j >= 0 && j <= SizeY;j+=incy)
            for(unsigned int i=MoussPoint.x1;i!=MoussPoint.x2 && i>=0 && i<= SizeX;i+=incx)
                environement->RemoveEntity(i,j);
     }
     /*else  if (action == REMOVE)
        {
                sf::View CurrentView(sf::FloatRect(0,0,MAP_SIZE*PAS_DEPLACEMENT,MAP_SIZE*PAS_DEPLACEMENT));
                CurrentView.Zoom(5);
                SetView(CurrentView);
        }*/
//    action=RIEN;
    MoussPoint.x1= MoussPoint.y1= MoussPoint.x2= MoussPoint.y2=0;
};

#define max_random 8

void EnvironementViewer::mouseMoveEvent ( QMouseEvent * event )//permet de gere les evenement souris lors de son deplacement
{
    if (IsPlay==false)
    {
        if (action == ADD_ONE)
        {
                if (CurrentSelectedEntity != NULL)
                {
                    QPoint position=event->pos();
                    position.setX(position.x()/PAS_DEPLACEMENT);
                    position.setY(position.y()/PAS_DEPLACEMENT);
                    environement->AddEntity(CurrentSelectedEntity,position.x(),position.y());
                }
        }
        else  if (action ==  ADD_LOT)
        {
            if (CurrentSelectedEntity != NULL)
            {
                QPoint position=event->pos();
                position.setX(position.x()/PAS_DEPLACEMENT -max_random/2);
                position.setY(position.y()/PAS_DEPLACEMENT -max_random/2);

                unsigned int nb=randMax(max_random)+1;

                for (unsigned int i=0;i<nb;++i)
                    environement->AddEntity(CurrentSelectedEntity,position.x()+(int)randMax(max_random),position.y()+randMax(max_random));
            }
        }

        else if (action ==  ADD_LINE)
        {
            if (CurrentSelectedEntity != NULL)
            {
                MoussPoint.x2=event->pos().x();
                MoussPoint.y2=event->pos().y();

                sf::ConvexShape Line(4);
                Line.setOutlineThickness(1);
                Line.setPoint(0,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
                Line.setPoint(3,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
                Line.setPoint(1,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
                Line.setPoint(2,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
                Line.setOutlineColor(sf::Color::Green);
                Line.setFillColor(sf::Color::Green);
                draw(Line);
            }
        }

        else  if (action ==  SELECTED)
        {
            MoussPoint.x2=event->pos().x();
            MoussPoint.y2=event->pos().y();

            sf::ConvexShape shape(4);
            shape.setFillColor(sf::Color::Transparent);
            shape.setOutlineColor(sf::Color::Green);
            shape.setOutlineThickness(1);

            shape.setPoint (0,sf::Vector2f(MoussPoint.x1,MoussPoint.y1));
            shape.setPoint (1,sf::Vector2f(MoussPoint.x2,MoussPoint.y1));
            shape.setPoint (2,sf::Vector2f(MoussPoint.x2,MoussPoint.y2));
            shape.setPoint (3,sf::Vector2f(MoussPoint.x1,MoussPoint.y2));

            draw(shape);
        }
        else  if (action == REMOVE)
        {
            environement->RemoveEntity(event->pos().x()/PAS_DEPLACEMENT,event->pos().y()/PAS_DEPLACEMENT);

        }
    }
};
/*
void EnvironementViewer::keyPressEvent (QKeyEvent * event)
{

};

void EnvironementViewer::keyReleaseEvent ( QKeyEvent * event )
{

};
*/

void EnvironementViewer::bresenham(int x1,int y1,int x2,int y2)
{
    int dx,dy;
    int e;

    if ((dx=x2-x1)!= 0)
    {
        if (dx >0)
        {
            if ((dy = y2-y1) != 0) // vecteur oblique dasn 1er quadran
            {
                if (dy > 0)
                {
                    // vecteur oblique dans le 1er quadran
                    if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
                    {
                        dx = (e = dx) * 2;
                        dy*=2; // e est > 0

                        while (true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (++x1 == x2 || x1 >= SizeX) break;
                            if ((e-=dy)< 0)
                            {
                                ++y1; // déplacement diagonal
                                e+=dx;
                            }
                        }
                    }
                    else
                    {
                        //vecteur oblique proche de la verticale, dans 2nd octant
                        dy = (e = dy) * 2;
                        dx*=2; // e est > 0

                        while(true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (++y1==y2 || y1 >= SizeY) break;
                            if((e-=dx)< 0)
                            {
                                ++x1;
                                e+=dy;
                            }
                        }
                    }
                }
                else // dy < 0 (et dx > 0)
                { // vecteru oblique dasn le 4eme cardan

                    if (dx >= -dy)
                    {  // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
                        dx = (e= dx) *2;
                        dy*=2; // e est positif
                        while (true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (++x1==x2  || x1 >= SizeX ) break;
                            if ((e+=dy) < 0 )
                            {
                                --y1;
                                e+=dx;
                            }
                        }
                    }
                    else
                    {// vecteur oblique proche de la verticale, dans le 7e octant
                        dy = (e = dy ) *2;
                        dx*=2; // e est négatif
                        while (true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (--y1==y2 || y1 < 0) break;
                            if ((e+=dx) >0)
                            {
                                ++x1;
                                e+=dy;
                            }
                        }
                    }
                }
            }
            else // dy = 0 & dx > 0
            {
                do
                {
                    environement->AddEntity(CurrentSelectedEntity,x1,y1);
                }while (++x1!= x2 && x1 <= SizeX);
            }
        }
        else // dx <= 0
        {
            if ((dy = y2 - y1) != 0)
            {
                if (dy > 0)// vecteur oblique dans le 2nd quadran
                {
                    if ( - dx >= dy)// vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
                    {
                        dx = (e=dx) *2;
                        dy*=2; // e est <0
                        while (true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (--x1 == x2 || x1 < 0 ) break;
                            if ((e+=dy)>=0)
                            {
                                ++y1;
                                e+=dx;
                            }
                        }
                    }
                    else // vecteur oblique proche de la verticale, dans le 3e octant
                    {
                        dy = (e = dy) *2;
                        dx*=2; // e > 0
                        while (true)
                        {
                            environement->AddEntity(CurrentSelectedEntity,x1,y1);
                            if (++y1== y2 || y1 >= SizeY) break;
                            if ((e+=dx)<=0)
                            {
                                --x1;
                                e+=dy;
                            }
                        }
                    }
                }
                else
                {// dy <0 et dx < 0
                     // vecteur oblique dans le 3e cadran
                     if (dx <= dy)
                     { // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
                            dx = (e =dx) *2;
                            dy*=2; // e <0
                            while (true)
                            {
                                environement->AddEntity(CurrentSelectedEntity,x1,y1);
                                if (--x1 == x2 || x1 <0) break;
                                if ((e-=dy)>=0)
                                {
                                    --y1;
                                    e+=dx;
                                }
                            }
                     }
                     else
                     {// vecteur oblique proche de la verticale, dans le 6e octant
                         dy = (e = dy)*2;
                         dx*=2; // e < 0
                         while (true)
                         {
                             environement->AddEntity(CurrentSelectedEntity,x1,y1);
                             if ( --y1 == y2 || y1 < 0) break;
                             if ((e-=dx)>=0)
                             {
                                 --x1;
                                 e+=dy;
                             }
                         }
                     }
                }
            }
            else // dy = 0 (et dx < 0)
            {// vecteur horizontal vers la gauche
                do
                {
                    environement->AddEntity(CurrentSelectedEntity,x1,y1);
                } while (--x1 != x2 && x1 >= 0);

            }
        }
    }
    else
    {// dx =0
        if ((dy = y2 - y1) != 0)
        {
            if (dy >0)
            {// vecteur vertical croissant
                do
                {
                    environement->AddEntity(CurrentSelectedEntity,x1,y1);
                }while(++y1 != y2 && y1 <= SizeY);
            }
            else
            {// dy < 0 et dx = 0
                //vertical décroisant
                do
                {
                    environement->AddEntity(CurrentSelectedEntity,x1,y1);
                }while (--y1 != y2 && y1 >=0);
            }
        }
    }
    environement->AddEntity(CurrentSelectedEntity,x2,y2);
};

