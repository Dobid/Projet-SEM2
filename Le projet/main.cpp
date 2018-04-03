#include "grman/grman.h"
#include <iostream>
#include "Graphe.h"
#include <fstream>
using namespace std;
int main()
{
    grman::init();
    grman::set_pictures_path("images");
    std::string fichier;int ok=0;
    grman::WidgetButton nouveau;
    grman::WidgetButton charger;
    nouveau.set_frame(100,100,100,100);
    charger.set_frame(100,300,100,100);
    grman::WidgetImage image_nouveau;
    grman::WidgetImage image_charger;
    nouveau.add_child(image_nouveau);
    charger.add_child(image_charger);
    image_nouveau.set_pic_name("singe.jpg");
    image_charger.set_pic_name("lion.jpg");
    int arret=0;
    while(!key[KEY_ESC]&&arret==0)
    {
        ok=0;
        while(ok==0)
        {
            nouveau.update();
            charger.update();
            grman::mettre_a_jour();
            if(nouveau.clicked())
            {
                ok=1;
                cout<<"nom du nouveau graphe?"<<endl;
                cin>>fichier;
                fichier+=".txt";
                std::ofstream fic(fichier,ios::out);
                fic<<"0"<<endl<<"0";

            }
            if(charger.clicked())
            {
                cout<<"nom du graphe a charger?"<<endl;
                cin>>fichier;
                fichier+=".txt";
                ok=1;
            }
            if(key[KEY_ESC])
            {
                ok=1;
                arret=1;
            }
        }
        if(arret!=1)
        {
            Graphe k(fichier);
            while ( !key[KEY_ESC] )
            {
                k.update();
                grman::mettre_a_jour();
            }
            rest(200);
        }
    }
        grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();
