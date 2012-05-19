#ifndef MAP_HPP
#define MAP_HPP

#include "entity.hpp"
#include "entity_aff.hpp"
#include "Vector.hpp"

#define MAP_SIZE 100

template <class T>
class Map
{
    public:
        /// constructeur où on spécifie la taille de la carte
        Map(const unsigned int X=MAP_SIZE,const unsigned int Y=MAP_SIZE);
        /// destructeur
        ~Map();
        /// redimensionne la taille
        void SetSize(const unsigned int X,const unsigned int Y);
        /// ajoute un element a la case [y][x] si il n'y a rien dans celle ci
        bool Push(const T& val,const unsigned int X,const unsigned int Y);
        /// supprime l'element dans la case [Y][X]
        void Pop(const unsigned int X,const unsigned int Y);
        /// ajoute un element dans la case [Y][X] et ecrase l'element existant si il y en a un
        void Replace(const T& val,const unsigned int X,const unsigned int Y);
        ///pour récuperer un objet stoquer à la place [Y][X]
        bool MoveTo(const unsigned int X1, const unsigned int Y1, const unsigned int X2,const unsigned intY2);
        inline T* Get(const unsigned int X,const unsigned int Y);
        void Clear();
        void Copy(const unsigned int Y, T** dest){memcpy(dest,entitees[Y],sizeof(T*)*SizeX);};

    private :
        /// fonction intern qui permet de tout supprimer
        inline void destroy();
        /// fonction interne d'initialisation
        void init();
        /// taille de la carte
        unsigned int x,y;
        /// tableau permetant de naviger parmis les entitées contenue dasn tab_entity (deplacement de pointeur + rappide que copy de var)
        T*** entitees;
        /// tableau de pointeur sur entity (va plus vite à bouger un pointeur qu'une valeure)
        Vector<T> tab_entity;
};

//////////////////////////// Obligé de faire dans le même fichier //////////////////////////////////////
template <class T>
Map<T>::Map(unsigned int X,unsigned int Y)
{
    x=(X>0)?X:1;
    y=(Y>0)?Y:1;
    init();
};

template <class T>
Map<T>::~Map()
{
    destroy();
};

template <class T>
void Map<T>::SetSize(unsigned int newx,unsigned int newy)
{
    const int decalage=tab_entity.SetMax(newx*newy); /// on range la taille du vecteur et on recupere le décalage d'adresse
    // on sauvegarde les anciennes données
    T*** entiteesOld=entitees;
    unsigned int oldx=x,
                 oldy=y;
    x=newx;
    y=newy;
    // on cré le nouveau tableau avec la bonne taille
    init();
    //on doit décaler les adresses des pointeurs d'objets de decalage pour tous les ancien objets compris dans la nouvelle taille
    for (unsigned int j=0;j<newy;++j)
        for (unsigned int i=0; i< newx;++i) // dans la nouvelle taille du tableau
            {
                if (j < oldy && i<oldx) // si la case courante est dasn le nouveau tableau et dans l'ancien
                    entitees[j][i]=entiteesOld[j][i]+decalage; // on met l'encienne valeur au nouveau
                else // sino à NULL
                    entitees[j][i]=NULL;
            }
    //on delete les anciennes données
    for (unsigned int j=0;j<oldy;++j)
        delete (entiteesOld[j]);
    delete entiteesOld;
};

template <class T>
bool Map<T>::Push(const T& val,const unsigned int X,const unsigned int Y)
{
    if (X<x && Y<y && entitees[Y][X] == NULL) //si la place est libre
    {
        entitees[Y][X]=tab_entity.Add(val);
        if (entitees[Y][X]!=NULL)
            entitees[Y][X]->SetPosition(X,Y);
        return true;
    }
    return false;
};

template <class T>
void Map<T>::Pop(const unsigned int X,const unsigned int Y)
{
    if (X<x && Y<y && entitees[Y][X] != NULL)//si la place est libre
    {
        tab_entity.Remove(entitees[Y][X]);
        entitees[Y][X]=NULL;
    }
};

template <class T>
void Map<T>::Replace(const T& val,const unsigned int X,const unsigned int Y)
{
     if (X<x && Y<y && entitees[Y][X] != NULL)//si la palce est prise
     {
        tab_entity.Remove(entitees[Y][X]);
     }
    entitees[Y][X]=tab_entity.Add(val);
    entitees[Y][X]->SetPosition(X,Y);
};

template <class T>
bool Map<T>::MoveTo(const unsigned int X1, const unsigned int Y1, const unsigned int X2,const unsigned int Y2)
{
    if (X2<x && Y2<y && X1<x && Y1<y  && entitees[Y2][X2]==NULL)//si la place est libre
    {
        entitees[Y2][X2]=entitees[Y1][X1];
        entitees[Y1][X1]=NULL;
        entitees[Y2][X2]->SetPosition(X2,Y2);
        return true;
    }
    return false;
};

template <class T>
inline T* Map<T>::Get(const unsigned int X, const unsigned int Y)
{
        return entitees[Y][X];
};
///////////////////////////////////////// PRIVATE ///////////////////////////////////////
template <class T>
void inline Map<T>::destroy()
{
    for (unsigned int j=0;j<y;++j)
        delete (entitees[j]);

    delete entitees;
    entitees=NULL;
    tab_entity.Clear();
};

template <class T>
void Map<T>::init()
{
    entitees = new (T**[y]);
    for (unsigned int j=0;j<y;++j)
    {
        entitees[j]= new (T*[x]);
        for (unsigned int i=0;i<x;i++)
            entitees[j][i]=NULL;
    }
    tab_entity.SetMax(x*y);
};

template <class T>
void Map<T>::Clear()
{
    tab_entity.Clear();
    for (unsigned int j=0;j<y;++j)
        for (unsigned int i=0;i<x;i++)
            entitees[j][i]=NULL;
}
#endif
