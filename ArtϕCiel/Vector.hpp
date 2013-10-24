#ifndef CONTENEURS_HPP
#define CONTENEURS_HPP

#include <iostream>
#include "Pile.hpp"
/////////////////////////////////// permet de gerder la même adresse d'un element stoqué dans un tableau tant qu'il est en vie ///////////////////////////////////
template <class T>
class Vector
{
    public:
        Vector(const unsigned int m=0);
        ~Vector();

        void Remove(const T* adresse);
        /// ajoute un element et renvoie son adresse
        T* Add(const T& v);
        /// realou la taille nesessaire, et renvoie la différence d'adresse en int*sizeof(T)
        int SetMax(const unsigned int m);
        /// vide tout
        void Clear();
        unsigned int GetMax()const{return max;};
        unsigned int Size()const{return count;};

    private:
        Pile<unsigned int> casesLibres;
        unsigned int count;
        unsigned int max;
        T* values;
};

///////////////////////////////////////////////// Methodes de la classe ////////////////////////////////////////////////////////////
template <class T>
Vector<T>::Vector(const unsigned int m)
{
    max=m;
    values = new T[max];
    for (unsigned int i=max;i>0;--i)
        casesLibres+=i-1; ///on ajoute le numeros des case libres
    count=0;
};

template <class T>
Vector<T>::~ Vector()
{
    delete values;
};

template <class T>
void Vector<T>::Remove(const T* adresse)
{
    if (adresse != NULL)
    {
        int c=adresse-values;
        if (count > 0 && c < (int)max && c >=0)
        {
            casesLibres.Push(c);
            count--;
        }
    }
};
template <class T>
T* Vector<T>::Add(const T& v)
{
    T* res=NULL;
    if (casesLibres.Size()>0)
    {
        res=&(values[casesLibres.Pop()]);
        *res=v;
        count++;
    }
    return res;
};
template <class T>
int Vector<T>::SetMax(const unsigned int m)
{
    T* old=values;
    if (m > max)
    {
        for (max=max;max<m;max++)
            casesLibres+=max; // on ajoute à la pile le nom des nouvelles cases libres
        values=(T*)realloc(values,sizeof(T)*max);
    }
    else if (m<max) //il faut enlever un paquet de values
    {
        for (unsigned int i=m;i<max;++i) //on vire se qui pourrait etre dans la pile
            casesLibres.FindAndRemove(i);

        values=(T*)realloc(values,sizeof(T)*max); //on reduit l'espace memoire
        max=m;
    }
    return values-old; ///difference entre la nouvelle et ancienne adresse
};

template <class T>
void Vector<T>::Clear()
{
    casesLibres.Clear();
    for (unsigned int i=max;i>0;--i)
        casesLibres+=i-1; ///on ajoute le numeros des case libres
    count=0;
    delete values;
    values = new T[max];
}
#endif
