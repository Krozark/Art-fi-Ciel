#ifndef ENTITY_AFF_HPP
#define ENTITY_AFF_HPP

#include "map.hpp"
#include "entity.hpp"

#define PRESSISION 1000
#define PRESSISION_INDEX_MAX (PRESSISION/4)
extern bool contour;

class Entity_Aff
{
    public :
        Entity_Aff(Entity* parent=NULL,const unsigned int X=0,const unsigned int Y=0);

        inline Entity* GetParent(){return parent;};
        inline void Draw(sf::RenderTarget* App) {parent->Draw(App,x,y);};
        bool Move();
        void SetPosition(const unsigned int X,const unsigned int Y);
        const unsigned int GetX(){return x;};
        const unsigned int GetY(){return y;};

    private :
        unsigned int x,y;
        unsigned int time;
        Entity *parent;
};

extern Map<Entity_Aff> Carte;
#endif
