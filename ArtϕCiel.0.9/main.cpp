#include <iostream>
#include <stdlib.h>

#include "MainWindows.hpp"
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
   ///initialiser le random
    srand(time(NULL));
    ///creation de l'aplication Qt
    QApplication App(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    ///creation de la fenettre utilisateur
    MainWindows* Window=new MainWindows(0,FRAME_TIME);

    if (argc > 1)
        Window->LoadFromFile(argv[1]);
    if (argc > 2)
        Window->SetFramerateLimit(atoi(argv[2]));
    ///affichage de la fenettre
    Window->show();
    ///quitter
    return App.exec();

    return 0;

};
