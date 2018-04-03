#include "Graphe.h"
using namespace std;
Graphe::Graphe(std::string fichier)
{
    Sommets.push_back(new Sommet ("singe","singe.jpg",0,50,75));
    Sommets.push_back(new Sommet ("lion","lion.jpg",1,70,240));
    Charger_Graphe(fichier);
    m_top_box.set_frame(500, 600, 0, 0);
    m_top_box.add_child( m_lien2 );
    m_lien2.attach_from(Sommets[1]->get_box());
    m_lien2.attach_to(Sommets[0]->get_box());
    m_lien2.reset_arrow_with_bullet();
}
Graphe::~Graphe()
{

}
void Graphe::Charger_Graphe(std::string fichier)
{

}
void Graphe::update()
{
    m_top_box.update();
    for(int i=0;i<Sommets.size();i++)
    {
        Sommets[i]->update();
    }
}
