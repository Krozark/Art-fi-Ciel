#ifndef COMPORTEMENTS_MODIFICATION
#define COMPORTEMENTS_MODIFICATION

#include <QtGui>
#include "reaction.hpp"
#include "EnvironementViewer.hpp"

class ComportementModification : public QDialog
{
    Q_OBJECT
    public :
        ComportementModification() : QDialog()
        {
            init();
        };
        ~ComportementModification();

        void SetEnvironementViewer(EnvironementViewer * E){EnvViewer = E;};

    public slots:
        virtual void save()=0;
    signals :
        void HasSave();

    protected :
        QDoubleSpinBox* S_Proba;

        QLineEdit * T_Nom;
        QTextEdit * T_Description;

        QComboBox * Reactifs,
                  * Produits;

        QCheckBox * UseEnfRecatifs;

        QWidget * ReactifContainer,
                * ProduitContainer;

        EnvironementViewer* EnvViewer;

        virtual void Initialise()=0;
        void InitialiseBox(QComboBox* Combo);

    private:
        void init();

        QLabel * L_nom,
               * L_Description,
               * L_Proba,
               * L_Reactifs,
               * L_Produits;

        QGridLayout* Layout;
        QPushButton* B_Save;
};

class SemieSitueModification : public ComportementModification
{
    Q_OBJECT
    public :
        SemieSitueModification()
        {
            init();
        }

    public slots:
        void save();
        void SetComportement(SemieSitue* A){CurrentReaction = A;Initialise();};

    private:
        void init();
        void Initialise();

        SemieSitue* CurrentReaction;
};

#endif
