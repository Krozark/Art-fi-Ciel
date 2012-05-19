#ifndef ENTITY_MODIFICATION_HPP
#define ENTITY_MODIFCATION_HPP

#include <QtGui>
#include <SFML/Graphics.hpp>

#include "EnvironementViewer.hpp"

class EntityModification : public QDialog
{
    Q_OBJECT
    public :
        EntityModification() : QDialog()
        {
            init();
        };

        ~EntityModification();

        void ChangeEntity(Entity* E){CurrentEntity=E;Initialise();};
        void SetEnvironementViewer(EnvironementViewer * E){EnvViewer = E;};

    public slots:
        void Save();
        void SetColor();
        void SetImage();
    signals :
        void HasSave();

    private:
        void init();
        void InitialiseParent();
        void Initialise();

        QLabel * L_nom, // pour afficher les légendes
               * L_Parent,
               * L_Parent2,
               * L_deplacement,
               * L_DemieVie,
               * L_description;

        QSpinBox * S_00, // pour gérer les déplacements
                 * S_01,
                 * S_02,
                 * S_10,
                 * S_12,
                 * S_20,
                 * S_21,
                 * S_22,
                 * S_DemieVie;

        QTextEdit * T_Description; //description de l'entitées

        QComboBox * B_Parent,
                  * B_Parent2; // selection du parent

        QLineEdit * T_Nom;

        QPushButton * B_Color,
                    * B_Image,
                    * B_Save;

        QGridLayout * Layout;

        Entity* CurrentEntity;
        EnvironementViewer* EnvViewer;

        string FileName;
};

#endif
