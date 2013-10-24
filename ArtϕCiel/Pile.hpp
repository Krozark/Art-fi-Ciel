///////////////////////////////// Structure permetant de stoquer de element chainés /////////////////////////////////////
template <class T>
class chaine{
    public:
    chaine(chaine* p=NULL,T v=0)
    {
        precedent=p;
        val=v;
    }
    chaine* precedent;
    T val;
};

/////////////////////////////// Remake de la classe Pile de la std en plus siple avec renvoie de valeur lors du POP //////////////////////////////////////

template <class T>
class Pile
{
    public :
        Pile();
        ~Pile();
        /// ajouter un membre
        void Push(const T v);
        ///enlever et recuperer le dernier membre
        const T Pop();
        ///supprime tout
        void Clear();
        /// noubre d'element acctuelement
        unsigned int Size()const{return count;};

        ///renvoie un bool pour savoir si l'element est presente dasn ma pile
        bool Contain(const T& v)const;
        /// cherche le premier element de valeur val et le supprime
        void FindAndRemove(const T& v);
        /// idem que push
        inline void operator +=(const T& v)
        {
            elem=new(chaine<T>)(elem,v);
            count++;
        };
    private:
        struct chaine<T>* elem;
        unsigned int count;
};

//////////////////////////// Metode de la classe /////////////////////////////////////////////////////////////
template <class T>
Pile<T>::Pile()
{
    elem=NULL;
    count=0;
};

template <class T>
Pile<T>::~Pile()
{
    Clear();
    delete elem;
};

template <class T>
void  Pile<T>::Push(const T v)
{
    elem=new(chaine<T>)(elem,v);
    count++;
};

template <class T>
const T Pile<T>::Pop()
{
    T res;
    if (count >0)
    {
        res=elem->val;
        struct chaine<T>* elemold=elem;
        elem=elem->precedent;
        delete (elemold);

        count--;
    }
    else
        cout<<"Plus de pop à faire dans la pile"<<endl;
    return res;
};
template <class T>
void Pile<T>::Clear()
{
    while(count>0)
    {
        struct chaine<T>* elemold=elem;
        elem=elem->precedent;
        delete (elemold);
        count--;
    }
};
template <class T>
bool Pile<T>::Contain(const T& v)const
{
  bool res=false;
  struct chaine<T>* e=elem;
  while(e->precedent != NULL)
  {
      if (e->val==v)
      {
        res=true;
        break;
      }
      e=e->precedent;
  }
  return res;
};
template <class T>
void Pile<T>::FindAndRemove(const T& v)
{
  struct chaine<T>* e=elem,
                    *avent= NULL;
  while(e != NULL)
  {
      if (e->val==v)
      {
        if (avent != NULL)
            avent->precedent=e->precedent;
        else
            elem=e->precedent;
        free(e);
        count--;
        break;
      }
      avent=e;
      e=e->precedent;
  }
};
