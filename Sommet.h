#ifndef SOMMET_H
#define SOMMET_H
#include "grman/grman.h"
#include <iostream>

class Sommet
{
    public:
        Sommet(std::string nom_animal,std::string nom_image,int couleur,int x,int y);
        virtual ~Sommet();
        void update();
        grman::WidgetBox& get_box();


    protected:

    private:
        grman::WidgetBox m_box;
        grman::WidgetImage m_img;
        grman::WidgetText m_legende;
        grman::WidgetText m_pop;
        grman::WidgetVSlider m_regle;
};

#endif // SOMMET_H
