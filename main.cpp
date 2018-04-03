#include "grman/grman.h"
#include <iostream>
#include "Graphe.h"


int main()
{
    grman::init();
    grman::set_pictures_path("images");
    Graphe k("dskjgh");
    while ( !key[KEY_ESC] )
    {
        k.update();
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();
