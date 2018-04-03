#include "Graphe.h"
using namespace std;
Graphe::Graphe(std::string fichier)
{
    m_fichier=fichier;
    Charger_Graphe(fichier);
    m_box_outils.set_frame(1, 1, 200, 766);
    m_box_outils.set_bg_color(BLEUCLAIR);
    m_box_outils.add_child(m_bouton_sauvegarder);
    m_bouton_sauvegarder.set_frame(1,1,198,198);
    m_bouton_sauvegarder.set_bg_color(FUCHSIA);
    m_bouton_sauvegarder.add_child(m_bouton_sauvegarder_image);
    m_bouton_sauvegarder_image.set_pic_name("sauvegarder.jpg");
}
Graphe::~Graphe()
{

}
void Graphe::Charger_Graphe(std::string fichier)
{
    int nbr;
    string nom_animal, nom_image;int couleur, x, y,pop;
    int s1,s2;
    std::ifstream fic(fichier,ios::in);
    fic>>nbr;
    for(int i=0;i<nbr;i++)
    {
        fic>>nom_animal>>nom_image>>couleur>>x>>y>>pop;
        Sommets.push_back(new Sommet(nom_animal,nom_image,couleur,x,y,pop));
    }
    fic>>nbr;
    for(int i=0;i<nbr;i++)
    {
        fic>>s1>>s2;
        Aretes.push_back(new Arete(Sommets[s1]->get_box(),Sommets[s2]->get_box(),s1,s2));
    }

}
void Graphe::update()
{
    m_box_outils.update();
    if ( m_bouton_sauvegarder.clicked())
        {
            Sauver_Graphe();
        }
    for(int i=0;i<(signed)Sommets.size();i++)
    {
        Sommets[i]->update();
    }
    for(int i=0;i<(signed)Aretes.size();i++)
    {
        Aretes[i]->update();
    }
}
void Graphe::Sauver_Graphe()
{
    std::ofstream fichier(m_fichier,ios::out);
    fichier<<Sommets.size()<<endl;
    for(int i=0;i<(signed)Sommets.size();i++)
    {
        fichier<<Sommets[i]->save()<<endl;
    }
    fichier<<Aretes.size()<<endl;
    for(int i=0;i<(signed)Aretes.size();i++)
    {
        fichier<<Aretes[i]->save()<<endl;
    }

}
