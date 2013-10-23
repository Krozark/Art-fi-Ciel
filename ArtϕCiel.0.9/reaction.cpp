#include "reaction.hpp"
#include <sstream>

bool contour;
static int nb;
////////////////////////////////////// REACTION ///////////////////////////////////////////////////////
Reaction::Reaction(string n,double prob, string desc)
{
    if (n=="")
    {
        stringstream out;
        out<<"Reaction_"<<nb;
        nom=out.str();
    }
    else
        nom=n;
    probabilite=prob;
    description=desc;
    Type=REACTION;
    initialise=false;
    ++nb;
};

//////////////////////////////////////////// SEMIE SITUEE //////////////////////////////////////////////
SemieSitue::SemieSitue(string n,double prob, string desc) : Reaction (n,prob,desc)
{
    Type=SEMIESITUE;
};

#define React(x,ymin) if ((E=CarteCpy[ymin][x])!=NULL) \
{\
    if ((P=E->GetParent())!=NULL) \
    { \
        if (find(Reactifs.begin(),Reactifs.end(),P) != Reactifs.end())\
        {\
            int index = P->GetIndex();\
            if (FindNb[index].NonRecursif < Reactif_Nb[index].NonRecursif) \
            { \
                ToPop.push_back(Vector2<unsigned int> (x,ymin));\
                ++(FindNb[index].NonRecursif);\
            }\
            else if (FindNb[index].Recursif < Reactif_Nb[index].Recursif)\
            {\
                ToPop.push_back(Vector2<unsigned int> (x,ymin));\
                ++(FindNb[index].Recursif);\
            }\
        }\
        else\
        {\
            bool implique = false;\
            const unsigned int _size=Reactifs.size();\
            for (unsigned int i=0;i<_size && !implique;++i)\
            {\
                int index = Reactifs[i]->GetIndex();\
                if (FindNb[index].Recursif < Reactif_Nb[index].Recursif)\
                    if (Reactifs[i]->IsOrIsParentOf(P))\
                    {\
                        implique = true;\
                        ToPop.push_back(Vector2<unsigned int> (x,ymin));\
                        ++(FindNb[index].Recursif);\
                    }\
            }\
        }\
    }\
}\
else\
{\
    Dispo.push_back(Vector2<unsigned int>(x,ymin));\
}


void SemieSitue::Run(const unsigned int X,const unsigned int Y)
{
    if (!initialise)
        init();
    if (rand100()<probabilite)
    {
        vector<sf::Vector2<unsigned int> > ToPop;
        vector<Vector2<unsigned int> > Dispo;

        Entity_Aff* E=NULL;
        Entity* P=NULL;

        vector< rea > FindNb;
        FindNb.resize(Entity::GetMaxIndex());
        /*for (unsigned int i=0;i<Entity::GetMaxIndex();++i)
        {
            FindNb[i].Recursif=0;
            FindNb[i].NonRecursif=0;
        }*/

        int ymin=Y-PROFONCDEUR_REATION/2;
        int xmin=X-PROFONCDEUR_REATION/2;
        int ymax=Y+PROFONCDEUR_REATION/2;
        int xmax=X+PROFONCDEUR_REATION/2;

        if (contour)
        {
            if (xmax>=(int)SizeX) xmax=SizeX-1;
            if (ymin<0)ymin=0;
            if (xmin<0) xmin=0;
            if (ymax>=(int)SizeY) ymax=SizeY-1;


            while (ymin<=ymax)
            {
                for (unsigned int x=(unsigned int)xmin;x<=(unsigned int)xmax;++x)//on parcout les voisins
                {
                    React(x,ymin);
                }
                ++ymin;
            }
        }
        else // si il y a pas de contour
        {
            if (xmax>=(int)SizeX) xmax-=SizeX;
            if (xmin<0) xmin+=SizeX;
            if (ymin<0)ymin+=SizeY;
            if (ymax>=(int)SizeY) ymax-=SizeY;

            while (ymin!=ymax)
            {
                int x=xmin;
                while(x != xmax)
                {
                    React(x,ymin);

                    if (++x >= (int)SizeX)
                        x-=SizeX;
                }
                if(++ymin>=(int)SizeY)
                    ymin-=SizeY;
            }
        }

        //si on a tout
        const unsigned int size_prod=Produits.size();
        const unsigned int size_ToPop=ToPop.size();
        unsigned int size_Dispo= Dispo.size();
        if (size_prod <= size_ToPop + size_Dispo) // si il y a assez de place pour tous les produits
        {
            bool ok = true;
            for (int i = FindNb.size()-1;ok && i>=0;--i)
            {
                ok = FindNb[i].NonRecursif >= Reactif_Nb[i].NonRecursif && FindNb[i].Recursif >= Reactif_Nb[i].Recursif;
            }
            if (ok)
            { // si on a tout se qu'il faut
                random_shuffle(Dispo.begin(),Dispo.end());
                for (unsigned int i=0;i<size_ToPop;++i)
                {
                    Carte.Pop(ToPop[i].x,ToPop[i].y);
                    CarteCpy[ToPop[i].y][ToPop[i].x]=NULL;
                    Dispo.push_back(ToPop[i]);
                }
                size_Dispo += size_ToPop -1;
                for (unsigned int i=0;i<size_prod;++i)//pour tous les resultat
                {
                    ///TODO Remplacer un element (lapin) par le type exacte qui à été pris parmis l'arbre d'héritage (bébé lapin)
                    Carte.Push(Entity_Aff(Produits[i]),Dispo[size_Dispo-i].x,Dispo[size_Dispo-i].y);
                    CarteCpy[Dispo[size_Dispo-i].y][Dispo[size_Dispo-i].x]=NULL;
                }
            }
        }
    }
};

void SemieSitue::init()
{
    const unsigned int _size=Reactifs.size();
    Reactif_Nb.clear();
    Reactif_Nb.resize(Entity::GetMaxIndex());

    for (int i=0;i<Entity::GetMaxIndex();++i)
    {
        Reactif_Nb[i].Recursif=0;
        Reactif_Nb[i].NonRecursif=0;
    }

    for (unsigned int i=0;i<_size;++i)
        if (Reactif_use_parent[i])
            ++(Reactif_Nb[Reactifs[i]->GetIndex()].Recursif);
        else
            ++(Reactif_Nb[Reactifs[i]->GetIndex()].NonRecursif);


    initialise=true;
};

void SemieSitue::Write(FILE* F)
{
    if (F)
    {
        stringstream out;
        out<<"\t<Reaction Nom=\""<<nom<<"\" Type=\""<<Type<<"\" Proba=\""<<probabilite<<"\" >\n";
            out<<"\t\t<Description>"<<description<<"</Description>\n";

            out<<"\t\t<Reactifs>\n";
                for(unsigned int i=0,_size=Reactifs.size();i<_size;++i)
                    out<<"\t\t\t<Entity Nom=\""<<Reactifs[i]->GetNom()<<"\" UseEnfants=\""<<(bool)Reactif_use_parent[i]<<"\" />\n";
            out<<"\t\t</Reactifs>\n";

            out<<"\t\t<Produits>\n";
                for(unsigned int i=0,_size=Produits.size();i<_size;++i)
                    out<<"\t\t\t<Entity Nom=\""<<Produits[i]->GetNom()<<"\" />\n";
            out<<"\t\t</Produits>\n";

        out<<"\t</Reaction>\n";

        fprintf(F,"%s",out.str().c_str());
    }
    else
        cout<<"Erreur dans l'écriture de la réaction Semie Située "<<nom<<" Fichier foireux"<<endl;
}
