#ifndef GRAPHE_H
#define GRAPHE_H
#include "Sommet.h"
#include "vector"

class Graphe
{
    public:
        Graphe(std::string fichier);
        virtual ~Graphe();
        void Charger_Graphe(std::string fichier);
        void update();

    protected:

    private:
        std::vector<Sommet*> Sommets;
        grman::WidgetBox m_top_box;
        grman::WidgetEdge m_lien2;
};

#endif // GRAPHE_H
