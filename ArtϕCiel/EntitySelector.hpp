#ifndef ENTITYSELECTOR_HPP
#define ENTITYSELECTOR_HPP

#include <QWidget>
#include <QVBoxLayout>

#include "EnvironementViewer.hpp"
#include <vector>
#include "PushButtonIndex.hpp"

class EntitySelector : public QWidget
{
    Q_OBJECT
    public:
      EntitySelector(QWidget* parent=0) : QWidget(parent)
      {
        Layout=NULL;
      };

    inline void SetViewer(EnvironementViewer* E){EnvViewer=E;};

    public slots:
            void SlotSelectdEntity(int);
            void SlotRemove(int);
            inline void Maj(){init();};
        signals:
            void EmitSelectedEntity(Entity*);

  private :
        void init();
        EnvironementViewer* EnvViewer;
        vector<QPushButtonIndex*> Buttons;
        QVBoxLayout* Layout;

};

#endif
