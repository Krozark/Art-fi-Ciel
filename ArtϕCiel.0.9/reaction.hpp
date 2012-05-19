#ifndef REACTION_HPP
#define REACTION_HPP

#include "comportements.hpp"

#define PROFONCDEUR_REATION 3

extern bool contour;

class Reaction : public Comportement
{
    public:
        Reaction(string n="",double prob=100.0, string desc="");
        inline void SetProbabilite(const double p){probabilite=(p<0)?0:p;};
        inline double GetProbabilite(){return probabilite;};
        inline void SetNom(const string n){nom=n;};
        inline const string GetNom(){return nom;};
        inline void SetDescription(const string d){description=d;};
        inline string GetDescription(){return description;};
        virtual void Run(const unsigned int x,const unsigned int y) =0;
        inline void HaveToBeInit(){initialise=false;};

    protected:
        bool initialise;
        double probabilite;
        string nom;
        string description;
};

#include <vector>
class SemieSitue : public Reaction
{
    public :
        SemieSitue(string n="",double prob=100.0, string desc="");
        void SetReactif(vector<Entity*> r){ Reactifs=r; initialise=false;};
        void SetProduits(vector<Entity*> p){Produits=p;initialise=false;};
        virtual void Run(const unsigned int x,const unsigned int y);
        vector<Entity*> Reactifs;
        vector<Entity*> Produits;
        vector<bool> Reactif_use_parent;
        void Write(FILE*);
    private:

        class rea
        {
            public :
                rea() {Recursif=NonRecursif=0;};
                unsigned int Recursif;
                unsigned int NonRecursif;
        };

        vector< rea > Reactif_Nb;


        void init();
};

#endif
