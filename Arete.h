#ifndef ARETE_H
#define ARETE_H
#include "grman/grman.h"


class Arete
{
    public:
        Arete(grman::WidgetBox& sommet1,grman::WidgetBox& sommet2,int lsommet1,int lsommet2);
        virtual ~Arete();
        void update();
        std::string save();

    protected:

    private:
        int m_sommet1,m_sommet2;
        grman::WidgetBox m_top_box;
        grman::WidgetEdge m_lien;
};

#endif // ARETE_H
