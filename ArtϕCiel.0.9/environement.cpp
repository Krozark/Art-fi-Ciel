#include "environement.hpp"
#include <algorithm>
#include <sstream>

unsigned int SizeX,SizeY;
Map<Entity_Aff> Carte;
Entity_Aff*** CarteCpy ;
vector<Entity*> EntityIndexed;

Entity* Environement::GetEntityOnIndex(int i){return EntityIndexed[i];};


Environement::Environement(const unsigned int X, const unsigned int Y)
{
    SizeX=X;
    SizeY=Y;
    Carte.SetSize(SizeX,SizeY);
    initialise=false;
    contour=true;
    CarteCpy = new (Entity_Aff**[SizeY]);
    for (unsigned int y=0;y<SizeY;++y)
        CarteCpy[y]=new (Entity_Aff*[SizeX]);
};

Environement::~Environement()
{
    for (unsigned int y=0;y<SizeY;++y)
        delete CarteCpy[y];
    delete CarteCpy;
};

void Environement::JustDraw(sf::RenderTarget * APP)
{
    if (!initialise)
    {
        Save();
        init();
    }
    Entity_Aff* e=NULL;
    for (unsigned int j=0;j<SizeY;++j)
        for(unsigned int i=0;i<SizeX;++i)
            if ((e=Carte.Get(i,j))!=NULL)
                e->Draw(APP);

};

void Environement::Draw(sf::RenderTarget * APP)
{
    if (!initialise)
        JustDraw(APP);
    else
    {
        for (unsigned int i=0;i<EntityNb;++i)
            Comptage_entity[Entites[i].GetIndex()]=0;

        for (unsigned int y=0;y<SizeY;++y)
            Carte.Copy(y,CarteCpy[y]);

        Entity_Aff* e=NULL;
        for (unsigned int j=0;j<SizeY;++j)
            for(unsigned int i=0;i<SizeX;++i)
                if ((e=CarteCpy[j][i])!=NULL)
                {
                    e->Draw(APP);
                    Entity* parent= e->GetParent();
                    if (parent!=NULL)
                    {
                        Comptage_entity[parent->GetIndex()]++;
                        const unsigned int size_Semi=parent->Reactions.size();
                        for (unsigned int k=0;k<size_Semi && CarteCpy[j][i] != NULL;++k)
                            parent->Reactions[k]->Run(i,j);

                    }
                }
        NextStep();
    }
};

void Environement::NextStep()
{
   Entity_Aff* e=NULL;
    for (unsigned int j=0;j<SizeY;++j)
        for(unsigned int i=0;i<SizeX;++i)
             if ((e=Carte.Get(i,j))!=NULL)
                e->Move();
};

void Environement::Save()
{
    Entity_Aff* E;
    SavePoint s;
    SavePile.Clear();
    for (unsigned int Y=0;Y<SizeY;Y++)
        for (unsigned int X=0;X<SizeX;++X)
            if ((E=Carte.Get(X,Y))!=NULL)
            {
                s.E=E->GetParent()->GetNom();
                s.X=X;
                s.Y=Y;
                SavePile.Push(s);
            }
}

void Environement::Exchange(std::string original,std::string nouveau)
{
    SavePoint s;
    Pile<SavePoint> P;
    const unsigned int _size = SavePile.Size();

    for (unsigned int i=0;i<_size;++i)
    {
        s=SavePile.Pop();
        if (s.E == original)
            s.E=nouveau;
        P.Push(s);
    }

    for (unsigned int i=0;i<_size;++i)
        SavePile.Push(P.Pop());

    for (unsigned int entity_cpt=0;entity_cpt<EntityNb;++entity_cpt)//pour toutes les entitées,
    {
        if (Entites[entity_cpt].parents[0]== original)
            Entites[entity_cpt].parents[0] = nouveau;

        if (Entites[entity_cpt].parents[1]== original)
            Entites[entity_cpt].parents[1] = nouveau;
    }
}

void Environement::Restore()
{
    SavePoint s;
    Entity* E;
    Carte.Clear();
    const unsigned int _size = SavePile.Size();

    for (unsigned int i=0;i<_size;++i)
    {
        s=SavePile.Pop();
        if ((E=GetEntityByName(s.E))!= NULL)
            AddEntity(E,s.X,s.Y);
    }
};

Entity* Environement::GetEntityByName(const string& name)
{
    Entity* res=NULL;
    EntityNb=Entites.size();
    for (unsigned int i=0;i<EntityNb;++i)
        if (Entites[i].GetNom()==name)
            return &(Entites[i]);

    return res;
};

void Environement::SetSize(const unsigned int X, const unsigned int Y)
{
    SizeX=(X>0)?X:1;
    SizeY=(Y>0)?Y:1;
    Carte.SetSize(SizeX,SizeY);
};

void Environement::init() //initialise le tableau des comportement, pour aller plus vite lors de l'execution
{
    EntityNb=Entites.size();
    const unsigned int _size2= SemieSitue_tab.size();

    Comptage_entity.clear();
    Comptage_entity.resize(Entity::GetMaxIndex());

    ///mis a jour des enfants
    ResetEnfants();
    for (unsigned int entity_cpt=0;entity_cpt<EntityNb;++entity_cpt)//pour toutes les entitées,
        for (unsigned int parent_cpt=0; parent_cpt<2;++parent_cpt)
            if (Entites[entity_cpt].parents[parent_cpt]!= "" && Entites[entity_cpt].parents[parent_cpt] != Entites[entity_cpt].GetNom()) // il a un parent
            {
                Entity* Parent=GetEntityByName(Entites[entity_cpt].parents[parent_cpt]);
                if (Parent != NULL)
                {
                    if (!Entites[entity_cpt].IsOrIsParentOf(Parent)) //si l'entitée en cour n'est pas un parent du parent (ça serrasi débile)
                        Parent->enfants.push_back(&(Entites[entity_cpt]));
                    else
                        Entites[entity_cpt].parents[parent_cpt]="";
                }
                else
                    Entites[entity_cpt].parents[parent_cpt]="";
            }
    /// ajout des différents comportements associés à chaque entités
    for (unsigned int entity_cpt=0;entity_cpt<EntityNb;++entity_cpt)//pour toutes les entitées,
    {
        Entites[entity_cpt].HaveToBeInit();
        Entites[entity_cpt].Reactions.clear();

        for (unsigned int semi_cpt=0;semi_cpt<_size2;++semi_cpt)//pour toutes les semie situés;
        {
            const unsigned int _size3=SemieSitue_tab[semi_cpt].Reactifs.size();

            for (unsigned int prod_cpt=0;prod_cpt<_size3;prod_cpt++) //on parcourt tous les reactif de la semie situé
                if (SemieSitue_tab[semi_cpt].Reactif_use_parent[prod_cpt])
                {//si on utilise les desendants

                    if (SemieSitue_tab[semi_cpt].Reactifs[prod_cpt]->IsOrIsParentOf(&(Entites[entity_cpt]))) ///si l'entité demmendé est/ou fait partis des des parent de l'entitée en cour
                    {//et qu'elle ne l'a pas déjà de lié a elle
                        if (find(Entites[entity_cpt].Reactions.begin(),Entites[entity_cpt].Reactions.end(),&(SemieSitue_tab[semi_cpt])) == Entites[entity_cpt].Reactions.end())
                        {//on lui ajoute
                            Entites[entity_cpt].Reactions.push_back(&(SemieSitue_tab[semi_cpt]));
                            SemieSitue_tab[semi_cpt].HaveToBeInit();
                        }
                    }
                }
                else if (SemieSitue_tab[semi_cpt].Reactifs[prod_cpt] == &(Entites[entity_cpt]) )
                {//si on utilise que l'entitée en quetion et pas ces enfants
                    if (find(Entites[entity_cpt].Reactions.begin(),Entites[entity_cpt].Reactions.end(),&(SemieSitue_tab[semi_cpt])) == Entites[entity_cpt].Reactions.end())
                    {//on lui ajoute
                        Entites[entity_cpt].Reactions.push_back(&(SemieSitue_tab[semi_cpt]));
                        SemieSitue_tab[semi_cpt].HaveToBeInit();
                    }
                }
        }
    }
    initialise=true;
};

void Environement::AddSemieSitue(const SemieSitue& S)
{
    SemieSitue_tab.push_back(S);
    initialise=false;
};

void Environement::AddEntity(const Entity& E)
{
    //save des pointeur avent changement
    vector<Entity*> Before;
    const unsigned int _size=Entites.size();
    for (unsigned int i=0; i< _size ;++i)
        Before.push_back(&(Entites[i]));

    Save();
    unsigned int i=0;
    Entity n=E;
    const string nom=n.GetNom();
    if (GetEntityByName(nom) != NULL )
    {
        stringstream out;
        out<<nom<<"-"<<(int)i;
        while (GetEntityByName(out.str()))
        {
            ++i;
            out.str("");
            out<<nom<<"-"<<(int)i;
        }
        Entity n=E;
        n.SetNom(out.str());
        Entites.push_back(n);
    }
    else
        Entites.push_back(E);

    Restore();
    initialise=false;

    /****************** MIS A JOUR DES POINTEUR DANS LES COMPORTEMENTS *************************/
    const unsigned int SS_size= SemieSitue_tab.size();

    for (unsigned int i=0;i<SS_size;++i)
    {
        for (unsigned int j=0;j<_size;++j) // pour tous les differents entitées
        {
            //on mes à jour
            replace(SemieSitue_tab[i].Reactifs.begin(),SemieSitue_tab[i].Reactifs.end(),Before[j],&(Entites[j]));
            replace(SemieSitue_tab[i].Produits.begin(),SemieSitue_tab[i].Produits.end(),Before[j],&(Entites[j]));
        }
    }

    EntityIndexed.clear();
    EntityIndexed.resize(Entity::GetMaxIndex());
    for (int i=0;i<=_size;++i)
        EntityIndexed[Entites[i].GetIndex()]=&(Entites[i]);

};


void Environement::Clear()
{
    Carte.Clear();
    SavePile.Clear();
    initialise=false;
};

void Environement::ClearAll()
{
    Carte.Clear();
    Entites.clear();
    SemieSitue_tab.clear();
    SavePile.Clear();
    EntityNb=0;
    initialise= false;
};


void Environement::ResetEnfants()
{
    for (unsigned int entity_cpt=0;entity_cpt<EntityNb;++entity_cpt)//pour toutes les entitées,
        Entites[entity_cpt].enfants.clear();
};

void Environement::RemoveEntity(unsigned int index)
{
    Save();
    string Nom= Entites[index].GetNom();
    vector<Entity*> Before;
    const unsigned int _size=Entites.size();
    for (unsigned int i=0; i< _size ;++i)
        Before.push_back(&(Entites[i]));

    Entites.erase(Entites.begin()+index);
    --EntityNb;
    /********************* Remplacement dans les comportements ********************************/
    const unsigned int SS_size= SemieSitue_tab.size();
    //const unsigned int Abs_size=Absolue_tab.size();

    for (unsigned int i=0;i<SS_size;++i)
    {
        for (unsigned int j=0;j<_size;++j) // pour toutes les differents entitées
        {
            //on mes à jour
            if (j!=index)
            {
                unsigned int new_index = (j<index)?j:j-1;
                replace(SemieSitue_tab[i].Reactifs.begin(),SemieSitue_tab[i].Reactifs.end(),Before[j],&(Entites[new_index]));
                replace(SemieSitue_tab[i].Produits.begin(),SemieSitue_tab[i].Produits.end(),Before[j],&(Entites[new_index]));
            }
            else
            {
                remove(SemieSitue_tab[i].Reactifs.begin(),SemieSitue_tab[i].Reactifs.end(),Before[j]);
                remove(SemieSitue_tab[i].Produits.begin(),SemieSitue_tab[i].Produits.end(),Before[j]);
            }

        }
    }

    /***************************** Remplacement a faire dans les parents des entitées ***************************/
    for (unsigned int entity_cpt=0;entity_cpt<EntityNb;++entity_cpt)//pour toutes les entitées
    {
        if (Entites[entity_cpt].parents[0]==Nom)
            Entites[entity_cpt].parents[0]="";

        if (Entites[entity_cpt].parents[1]==Nom)
            Entites[entity_cpt].parents[1]="";
    }

    init();
    Restore();
};

void Environement::Write(FILE* F)
{
    if (F)
    {
         stringstream out;
         out<<"<?xml version=\"1.0\"?>\n";
         out<<"<Environement SizeX=\""<<SizeX<<"\" SizeY=\""<<SizeY<<"\" PAS_DEPLACEMENT=\""<<PAS_DEPLACEMENT<<"\" >\n";

         fprintf(F,"%s",out.str().c_str());
         out.str(std::string());

            for (unsigned int i=0, max =Entites.size();i<max;++i)
                Entites[i].Write(F);

            for (unsigned int i=0, max =SemieSitue_tab.size();i<max;++i)
                SemieSitue_tab[i].Write(F);

            /*for (unsigned int i=0, max =Absolue_tab.size();i<max;++i)
                Absolue_tab[i].Write(F);*/

            Entity_Aff* E;
            for (unsigned int Y=0;Y<SizeY;Y++)
                for (unsigned int X=0;X<SizeX;++X)
                    if ((E=Carte.Get(X,Y))!=NULL)
                        out<<"\t<EntityAff Nom=\""<<E->GetParent()->GetNom()<<"\" X=\""<<X<<"\" Y=\""<<Y<<"\" />\n";

         out<<"</Environement>\n";
         fprintf(F,"%s",out.str().c_str());
    }
    else
        cout<<"Fichier d'enregistrement foireux pour l'environement"<<endl;
};


#include <libxml/tree.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#define NodeIs(Name,Node) Node->type == XML_ELEMENT_NODE  && !xmlStrcmp(Node->name, (const xmlChar *) Name )
#define ChildrenIs(Name,Parent,Enfant) Parent->type == XML_ELEMENT_NODE  && !xmlStrcmp(Enfant->name, (const xmlChar *) Name)
#define GetProp(Name,dest,Node) dest =(char*)xmlGetProp(Node,(const xmlChar*) Name); if(dest == NULL ){ cout<<"Erreur lors du chargement du fichier"<<endl; return;}

void Environement::LoadFromFile(const char* FileName)
{
    xmlDocPtr doc;
    xmlNode *cur_node,*root;
    char* Prop;

    doc = xmlParseFile(FileName); // ON PARSE LE DOCUMENT
    root = xmlDocGetRootElement(doc); // on cherche la racine

    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar*)"Environement") )
    {
         xmlFreeDoc(doc);
         return;
    }

    ClearAll();


    for(cur_node = root->children; cur_node != NULL; cur_node = cur_node->next)
    {
        if (NodeIs("Entity",cur_node))
        {
            Entity n;

            GetProp("Nom",Prop,cur_node);
            n.SetNom(Prop);
            delete Prop;

            GetProp("DemieVie",Prop,cur_node);
            n.SetDemieVie(atoi(Prop));
            delete Prop;

            xmlNode* child_node;
            for(child_node = cur_node->children; child_node != NULL; child_node = child_node->next)
            {
                if (ChildrenIs("Description",cur_node,child_node))
                {
                    Prop = (char*)xmlNodeGetContent(child_node);
                    n.SetDescription(Prop);
                    delete Prop;
                }
                else if (ChildrenIs("Image",cur_node,child_node))
                {
                    Prop = (char*)xmlNodeGetContent(child_node);
                    n.SetImage(Prop);
                    delete Prop;
                }
                else if (ChildrenIs("Couleur",cur_node,child_node))
                {
                    GetProp("R",Prop,child_node);
                    n.couleur.r = atoi(Prop);
                    delete Prop;

                    GetProp("G",Prop,child_node);
                    n.couleur.g = atoi(Prop);
                    delete Prop;

                    GetProp("B",Prop,child_node);
                    n.couleur.b = atoi(Prop);
                    delete Prop;
                }
                else if (ChildrenIs("Parent",cur_node,child_node))
                {
                    xmlNode* child_node2;
                    int i=0;
                    for(child_node2 = child_node->children; child_node2 != NULL && i<2; child_node2 = child_node2->next)
                    {
                        if (ChildrenIs("Nom",child_node,child_node2))
                        {
                            Prop = (char*)xmlNodeGetContent(child_node2);
                            n.parents[i]= string(Prop);
                            delete Prop;
                            ++i;
                        }
                    }
                }
                else if (ChildrenIs("Deplacement",cur_node,child_node))
                {
                    unsigned int dep[SIZE_MATRIX_DEP][SIZE_MATRIX_DEP]={{0,0,0},{0,0,0},{0,0,0}};
                    xmlNode* child_node2;
                    for(child_node2 = child_node->children; child_node2 != NULL; child_node2 = child_node2->next)
                    {
                        if (ChildrenIs("Case",child_node,child_node2))
                        {
                            int X,Y,Val;
                            GetProp("X",Prop,child_node2);
                            X= atoi(Prop);
                            delete Prop;

                            GetProp("Y",Prop,child_node2);
                            Y = atoi(Prop);
                            delete Prop;

                            GetProp("Val",Prop,child_node2);
                            Val=atoi(Prop);
                            delete Prop;

                            if (X >=0 && X < SIZE_MATRIX_DEP && Y >=0 && Y < SIZE_MATRIX_DEP )
                                if (X != DEMIE_SIZE_MATRIX_DEP || Y != DEMIE_SIZE_MATRIX_DEP)
                                    dep[Y][X]=(Val>0)?Val:0;

                        }
                    }
                    n.SetDeplacement(dep);
                }
            }
            AddEntity(n);
        }
        else if (NodeIs("Reaction",cur_node))
        {
            GetProp("Type",Prop,cur_node);
            int Type = atoi(Prop);
            delete Prop;

            if (Type == SEMIESITUE)
            {
                SemieSitue R("");

                GetProp("Nom",Prop,cur_node);
                R.SetNom(Prop);
                delete Prop;

                GetProp("Proba",Prop,cur_node);
                R.SetProbabilite(atof(Prop));
                delete Prop;

                xmlNode* child_node;
                for(child_node = cur_node->children; child_node != NULL; child_node = child_node->next)
                {
                    if (ChildrenIs("Description",cur_node,child_node))
                    {
                        R.SetDescription((char*)xmlNodeGetContent(child_node));
                    }
                    else if (ChildrenIs("Reactifs",cur_node,child_node))
                    {
                        xmlNode* child_node2;
                        vector<Entity*> v;
                        int i=0;
                        for(child_node2 = child_node->children; child_node2 != NULL && i< PROFONCDEUR_REATION*PROFONCDEUR_REATION; child_node2 = child_node2->next)
                        {
                            if (ChildrenIs("Entity",child_node,child_node2))
                            {
                                GetProp("Nom",Prop,child_node2);
                                v.push_back(GetEntityByName(Prop));
                                delete Prop;

                                GetProp("UseEnfants",Prop,child_node2);
                                R.Reactif_use_parent.push_back(atoi(Prop));
                            }
                            ++i;
                        }
                        R.SetReactif(v);
                    }
                    else if (ChildrenIs("Produits",cur_node,child_node))
                    {
                        xmlNode* child_node2;
                        vector<Entity*> v;
                        for(child_node2 = child_node->children; child_node2 != NULL; child_node2 = child_node2->next)
                        {
                            if (ChildrenIs("Entity",child_node,child_node2))
                            {
                                GetProp("Nom",Prop,child_node2);
                                v.push_back(GetEntityByName(Prop));
                                delete Prop;
                            }
                        }
                        R.SetProduits(v);
                    }
               }
                AddSemieSitue(R);
            }
        }
        else if (NodeIs("EntityAff",cur_node))
        {
            int X,Y;
            GetProp("X",Prop,cur_node);
            X=atoi(Prop);
            delete Prop;

            GetProp("Y",Prop,cur_node);
            Y=atoi(Prop);
            delete Prop;

            GetProp("Nom",Prop,cur_node);

            if (X>= 0 && Y>= 0  && X< SizeX && Y < SizeY)
                AddEntity(Prop,X,Y);

            delete Prop;
        }
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();
};
