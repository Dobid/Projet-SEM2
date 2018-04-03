#include "Arete.h"
using namespace std;
Arete::Arete(grman::WidgetBox& sommet1,grman::WidgetBox& sommet2,int lsommet1,int lsommet2)
{
    m_sommet1=lsommet1;
    m_sommet2=lsommet2;
    m_top_box.set_frame(500, 600, 0, 0);
    m_top_box.add_child( m_lien );
    m_lien.attach_from(sommet1);
    m_lien.attach_to(sommet2);
    m_lien.reset_arrow_with_bullet();
}
void Arete::update()
{
    m_top_box.update();
}
std::string Arete::save()
{
    string chaine;
    chaine=to_string(m_sommet1);
    chaine+=" ";
    chaine+=to_string(m_sommet2);
    return chaine;
}
Arete::~Arete()
{
    //dtor
}
