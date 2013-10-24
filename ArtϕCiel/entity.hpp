#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define SIZE_MATRIX_DEP 3
#define DEMIE_SIZE_MATRIX_DEP SIZE_MATRIX_DEP/2
#define PAS_DEPLACEMENT 10

extern unsigned int SizeX,SizeY;

using namespace sf;
using namespace std;

/*inline double randRange(double fMin, double fMax)
{
    return fMin + ((double)rand() / RAND_MAX)*(fMax - fMin);
};*/

inline double randMax(double fMax)
{
    return ((double)rand() / RAND_MAX)*fMax;
};

inline double rand100()
{
    return ((double)rand() / RAND_MAX)*100.0L;
};

inline double rand1()
{
    return ((double)rand() / RAND_MAX);
};
class SemieSitue;
class Reaction;


class Entity
{
    public:
        Entity(string parent="",string parent2 ="");

        inline void SetDeplacement(const unsigned int dep[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP])
        {
            SumDep=0;
             memcpy(deplacement,dep,sizeof(unsigned int)*SIZE_MATRIX_DEP*SIZE_MATRIX_DEP);
             for (unsigned int i=0;i<SIZE_MATRIX_DEP;++i)
                for (unsigned int j=0;j<SIZE_MATRIX_DEP;++j)
                {
                    if (i != DEMIE_SIZE_MATRIX_DEP ||  j != DEMIE_SIZE_MATRIX_DEP)
                        SumDep+=deplacement[i][j];
                    else
                        deplacement[i][j]=0;
                    deplacementCumule[i][j]=SumDep;
                }
        };

        inline void SetDemieVie(const unsigned int dv=0){demie_vie=dv; ProbaPassage = (demie_vie<=0)?1.0L:pow(2.0,((double)demie_vie-1.0L)/((double)demie_vie))/2.0;};
        //graphic
        //inline void SetColor(const Color& c){ sprite.SetColor(c);};
        void SetImage(const string& img);
        //affichage
        inline void SetNom(const string name){nom=name;};
        inline void SetDescription(const string desc){description=desc;};
        inline int GetIndex(){return Index;};

        static int GetMaxIndex();

        inline void GetDeplacement(unsigned int d[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP])
        {
            memcpy(d,deplacement,sizeof(unsigned int)*SIZE_MATRIX_DEP*SIZE_MATRIX_DEP);
        };
        inline void GetDeplacementCumule(unsigned int d[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP])
        {
            memcpy(d,deplacementCumule,sizeof(unsigned int)*SIZE_MATRIX_DEP*SIZE_MATRIX_DEP);
        };

        inline unsigned int GetSumDeplacement()const{return SumDep;};
        inline unsigned int GetDemieVie()const{return demie_vie;};
        inline double GetProbaPassage()const{return ProbaPassage;};
        //graphic
        //inline const Color GetColor(){return sprite.GetColor();};
        //affichage
        inline const string GetNom()const{return nom;};
        inline const string GetDescription()const{return description;};
        inline void HaveToBeInit(){not_initialise=true;};

        inline void Draw(sf::RenderTarget* App,const unsigned int x,const unsigned int y)
        {
            if (not_initialise)
            {
                SetTexture();
            }
            sprite.setPosition(x*PAS_DEPLACEMENT,y*PAS_DEPLACEMENT);
            App->draw(sprite);
        };

        Color couleur;
        vector<Entity*> enfants;
        vector<Reaction*> Reactions;
        string* parents;

        inline bool IsOrIsParentOf(Entity* E)
        {
            if (this == E)
                return true;

            bool enfant = false;
            const unsigned int _size = enfants.size();
            for (unsigned int i=0; i<_size && !enfant;++i)
                enfant = enfants[i]->IsOrIsParentOf(E);

            return enfant;
        }
        void Write(FILE* F);

    private:
        bool not_initialise;
        double ProbaPassage;
        int Index;
        unsigned int demie_vie;
        unsigned int deplacement[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP];
        unsigned int deplacementCumule[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP];
        unsigned int SumDep;

        void SetTexture();

        //graphic
        Texture texture;
        Sprite sprite;
        string FileName;
        //donnée d'informations
        string nom;
        string description;
};
#endif
