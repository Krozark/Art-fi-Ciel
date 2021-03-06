######################################################################
# Automatically generated by qmake (2.01a) mer. nov. 23 18:57:41 2011
######################################################################

TEMPLATE = app
TARGET = ArtϕCiel
DEPENDPATH += .
INCLUDEPATH += . /home/maxime/Developement/SFML2/include/SFML /home/maxime/Developement/SFML2/lib /usr/include/libxml2
LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lxml2 -lm
OBJECTS_DIR   = ./obj/

# Input
HEADERS += comportements.hpp \
           entity.hpp \
           entity_aff.hpp \
           environement.hpp \
           map.hpp \
           Pile.hpp \
           QSFMLCanvas.hpp \
           reaction.hpp \
           Vector.hpp \
           EnvironementViewer.hpp \
           MainWindows.hpp \
           WindowDock.hpp \
           CourbesViewer.hpp \
           EntitySelector.hpp \
           EntityModification.hpp \
		   ComportementsSelector.hpp \
		   PushButtonIndex.hpp \
		   ComportementsModification.hpp 
SOURCES += comportements.cpp \
           entity.cpp \
           entity_aff.cpp \
           environement.cpp \
           main.cpp \
           QSFMLCanvas.cpp \
           reaction.cpp \
           EnvironementViewer.cpp \
           MainWindows.cpp \
           WindowDock.cpp \
           CourbesViewer.cpp \
           EntitySelector.cpp \
           EntityModification.cpp \
           ComportementsSelector.cpp \
           PushButtonIndex.cpp \
           ComportementsModification.cpp
