#include "entity.hpp"
#include <sstream>
static int Nombre;

int Entity::GetMaxIndex(){return Nombre;};

Entity::Entity(string parent,string parent2)
{
    //initialiser les parents
    parents=new string[2];
    parents[0]=parent,
    parents[1]=parent2;

    not_initialise=true;
    SetDemieVie(0);
    SumDep=0;

    for (unsigned int i=0;i<SIZE_MATRIX_DEP;++i)
        for (unsigned int j=0;j<SIZE_MATRIX_DEP;++j)
        {
            if (i !=1 || j != 1)
            {
                deplacement[i][j]=100;
                SumDep+=deplacement[i][j];
            }
            else
                deplacement[i][j]=0;
            deplacementCumule[i][j]=SumDep;
        }
    SetImage("images/1.png");
    stringstream out;
    out<<"Entity_"<<Nombre;
    nom=out.str();
    description="Description";

    couleur=sf::Color((int)randMax(255),(int)randMax(255),(int)randMax(255),255);

    Index=Nombre++;
};

void Entity::SetImage(const string& img)
{
    texture.loadFromFile(img);
    FileName=img;
    not_initialise=true;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,10,10));
};

void Entity::Write(FILE* F)
{
    if (F)
    {
        stringstream out;
        out<<"\t<Entity Nom=\""<<nom<<"\" DemieVie=\""<<demie_vie<<"\" >\n";
            out<<"\t\t<Description>"<<description<<"</Description>\n";
            out<<"\t\t<Image>"<<FileName<<"</Image>\n";
            out<<"\t\t<Couleur R=\""<<(int)couleur.r<<"\" G=\""<<(int)couleur.g<<"\" B=\""<<(int)couleur.b<<"\"/>\n";

            out<<"\t\t<Parent>\n";
            for(unsigned int i=0;i<2;++i)
                if (parents[i]!= "")
                    out<<"\t\t\t<Nom>"<<parents[i]<<"</Nom>\n";
            out<<"\t\t</Parent>\n";

            out<<"\t\t<Deplacement>\n";
            for (unsigned int i=0;i<SIZE_MATRIX_DEP;++i)
                for (unsigned int j=0;j<SIZE_MATRIX_DEP;++j)
                    out<<"\t\t\t<Case X=\""<<j<<"\" Y=\""<<i<<"\" Val=\""<<deplacement[i][j]<<"\" />\n";
            out<<"\t\t</Deplacement>\n";

        out<<"\t</Entity>\n";

        fprintf(F,"%s",out.str().c_str());
    }
    else
        cout<<"Fichier foireux pour l'enregistrement de l'entitée "<<nom<<endl;
}



