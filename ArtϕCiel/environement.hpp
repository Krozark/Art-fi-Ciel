#ifndef ENVIRONEMENT_HPP
#define ENVIRONEMENT_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "reaction.hpp"

class SavePoint
{
public:
    SavePoint(){};
    SavePoint(const SavePoint& s)
    {
        this->E=s.E;
        this->X=s.X;
        this->Y=s.Y;
    };
string E;
unsigned int X;
unsigned int Y;
};

class Environement
{
    public:
        Environement(const unsigned int X=MAP_SIZE, const unsigned int Y=MAP_SIZE);
        ~Environement();
        void Draw(sf::RenderTarget * APP);
        void JustDraw(sf::RenderTarget * APP);
        void SetSize(const unsigned int X, const unsigned int Y);
        void SetContour(const bool c){contour=c;};
        void Clear();
        void ClearAll();
        inline void Stop(){Restore();Save();initialise=false;};

        inline void HaveToBeInitialise(){initialise=false;};
        Entity* GetEntityByName(const string& name);
        inline vector<Entity>* GetEntities(){return &Entites;};
        inline vector<SemieSitue>* GetSemieSitues(){return &SemieSitue_tab;};
        //inline vector<Absolue>* GetAbsolues(){return &Absolue_tab;};

        void AddSemieSitue(const SemieSitue& S);
        //void AddAbsolue(const Absolue& A);
        inline void AddEntity(const Entity_Aff& E,const unsigned int X, const unsigned int Y){Carte.Push(E,X,Y);/*initialise=false;*/};
        inline void AddEntity(const string& name,const unsigned int X, const unsigned int Y){Carte.Push(Entity_Aff(GetEntityByName(name)),X,Y);/*initialise=false;*/};
        inline void AddEntity(Entity* E,const unsigned int X, const unsigned int Y){Carte.Push(Entity_Aff(E),X,Y);/*initialise=false;*/};
        void AddEntity(const Entity& E);

        void RemoveEntity(unsigned int i);
        inline void RemoveEntity(const unsigned int X, const unsigned int Y){ Carte.Pop(X,Y);};
        void Exchange(std::string original,std::string nouveau);

        vector<unsigned int > Comptage_entity;
        static Entity* GetEntityOnIndex(int i);

        void Write(FILE*);
        void LoadFromFile(const char* FileName);

    private :
        vector<Entity> Entites;
        unsigned int EntityNb;
        // comportements SemieSitue
        vector <SemieSitue> SemieSitue_tab;


        bool initialise;

        void init();//initialise le tableau des comportement, pour aller plus vite lors de l'execution
        void NextStep();
        void Save();
        void Restore();
        void ResetEnfants();

        Pile<SavePoint> SavePile;
};

extern Entity_Aff*** CarteCpy ;


#endif
