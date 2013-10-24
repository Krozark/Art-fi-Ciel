#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP

#include "entity_aff.hpp"
#include "map.hpp"
#include <stdio.h>

extern Map<Entity_Aff> Carte;
extern Entity_Aff*** CarteCpy ;

enum TypeComportement {COMPORTEMENT=0,REACTION,SEMIESITUE,ABSOLUE,SIZE};

class Comportement
{
    public:
        Comportement();
        TypeComportement GetType(){return Type;};
        virtual void Run(const unsigned int X,const unsigned int Y) =0;
        virtual void Write(FILE*) =0;

    protected:
        TypeComportement Type;
};
#endif
