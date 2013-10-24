#include <stdio.h>

#include "entity_aff.hpp"

Entity_Aff::Entity_Aff(Entity* parent,const unsigned int X,const unsigned int Y)
{
    this->parent=parent;
    time=0.0;
    x=(X<SizeX)?X:SizeX-1;
    y=(Y<SizeY)?Y:SizeY-1;
};

unsigned int d[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP];

bool Entity_Aff::Move()
{
    double r;

    if (parent->GetDemieVie()>0) // si le truc est crevable, on test la demie vie
    {
        r=(rand1());
        if (r>parent->GetProbaPassage()) // si il est mort
        {
            Carte.Pop(x,y);//on le vire
            return false;//on arrete là
        }
        time++;
    }
    unsigned int sum=parent->GetSumDeplacement();

    if (sum)
    {
        r=randMax(sum);
        parent->GetDeplacementCumule(d);

        for (unsigned int j=0;j<SIZE_MATRIX_DEP;++j) // on calcule son future deplacement
            for (unsigned int i=0;i<SIZE_MATRIX_DEP;++i)
                if (d[j][i] >=r) // si c'est la case concernée on calcule le déplacement
                {
                    int X= x+(i-DEMIE_SIZE_MATRIX_DEP);
                    int Y= y+(j- DEMIE_SIZE_MATRIX_DEP);

                    if (contour)
                    {
                        if (X>=0  && Y>=0 ) // verification du max fait à l'appel de fonction
                        {
                         if (Carte.MoveTo(x,y,X,Y)) // si il a bien bougé
                            {
                                x=X;
                                y=Y;
                                j=i=SIZE_MATRIX_DEP; //break;
                            }
                        }
                    }
                    else
                    {
                        if (X<0)//on revien sur le bord droit
                            X+=SizeX;
                        else if (X>=(int)SizeX) //on revien à gauche
                            X-=SizeX;
                        if (Y<0) //on revient en bas
                            Y+=SizeY;
                        else if (Y>=(int)SizeY) // on revien en haut
                            Y-=SizeY;
                        if (Carte.MoveTo(x,y,X,Y)) // si il a bien bougé
                        {
                            x=X;
                            y=Y;
                            j=i=SIZE_MATRIX_DEP; //break;
                        }
                    }
                }
    }
    return true;
};

void Entity_Aff::SetPosition(const unsigned int X,const unsigned int Y)
{
    x=(X<SizeX)?X:SizeX-1;
    y=(Y<SizeY)?Y:SizeY-1;
};
