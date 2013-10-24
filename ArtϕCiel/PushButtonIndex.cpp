#include "PushButtonIndex.hpp"

QPushButtonIndex::~QPushButtonIndex()
{
    if (index >=0)
    {
        _Remove->disconnect();
        delete menu;
        delete _Remove;
    }

    disconnect();
};

void QPushButtonIndex::ShowContextMenu(QPoint pos)
{
    menu->exec(mapToGlobal(pos));
};
