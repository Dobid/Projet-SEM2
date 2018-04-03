#include "Sommet.h"
#include "string"
using namespace std;
Sommet::Sommet(string nom_animal,string nom_image,int couleur,int x,int y,int pop)
{
    m_nom_animal=nom_animal;m_nom_image=nom_image;m_couleur=couleur;m_x=x;m_y=y;m_popp=pop;
    m_box.set_frame(x, y, 120, 90);
    if(couleur==0)
        m_box.set_bg_color(VERT);
    if(couleur==1)
        m_box.set_bg_color(ROUGE);
    m_box.set_moveable();

    m_box.add_child(m_legende);
    m_legende.set_message(nom_animal);
    m_legende.set_gravity_y(grman::GravityY::Down );

    m_box.add_child(m_img);
    m_img.set_pic_name(nom_image);
    m_img.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Up);

    m_box.add_child(m_regle);
    m_regle.set_bg_color(BLANC);
    m_regle.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Center);
    m_regle.set_range(1, 10, true); // 3ème param true => valeurs entières
    m_regle.set_frame(1,1,15,75);
    m_regle.set_value(pop);

    m_box.add_child(m_pop);
    m_pop.set_message("0");
    m_pop.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Down);
    //ctor
}

Sommet::~Sommet()
{
    //dtor
}
void Sommet::update()
{
    m_pop.set_message(std::to_string((int)m_regle.get_value()));
    m_box.update();
    m_x=m_box.get_posx();
    if(m_x<200)
    {
        m_x=200;
        m_box.set_posx(200);
    }
    m_y=m_box.get_posy();
}
grman::WidgetBox& Sommet::get_box()
{
    return m_box;
}
string Sommet::save()
{
    string chaine;
    chaine=m_nom_animal;
    chaine+=" ";
    chaine+=m_nom_image;
    chaine+=" ";
    chaine+=to_string(m_couleur);
    chaine+=" ";
    chaine+=to_string(m_x);
    chaine+=" ";
    chaine+=to_string(m_y);
    chaine+=" ";
    chaine+=to_string(m_popp);
    return chaine;
}
