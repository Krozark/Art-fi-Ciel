#ifndef PUSHBUTTONINDEX_HPP
#define PUSHBUTTONINDEX_HPP

#include <QPushButton>
#include <QMenu>
#include <QAction>

//bouton qui renvoie l'index quand il est cliqué
class QPushButtonIndex : public QPushButton
{
  Q_OBJECT

  public:

  QPushButtonIndex(int index,const QString& Name,QWidget * parent=0) : QPushButton(Name,parent)
  {
    this->index=index;
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));

    if (index>=0)
    {
        setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ShowContextMenu(QPoint)));
        menu= new QMenu( this );
        _Remove=new QAction("Supprimer",this);
        menu->addAction(_Remove);
        QObject::connect(_Remove,SIGNAL(triggered()),this,SLOT(SlotRemoveClicked()));
    }
    else
    {
        menu=NULL;
        _Remove= NULL;
    }
  };

  ~QPushButtonIndex();

   public slots:
        inline void slotClicked() {emit EmitIndex(index);};
        void ShowContextMenu(QPoint);
        inline void SlotRemoveClicked(){emit EmitRemove(index);};

        signals:
    void EmitIndex(int index);
    void EmitRemove(int index);

  private:
    int index;
    QMenu* menu;
    QAction* _Remove;

};
#endif
