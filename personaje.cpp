#include "personaje.h"

Personaje::Personaje(int x,int y,bool volteado)
{
    noSprite=0;
    posX=x;
    posY=y;
    if(volteado==true)
    {
        voltea=1;
    }
    else
    {
        voltea=false;
    }
}

Personaje::~Personaje()
{

}

//void Personaje::agregaEstado(QString nombre)
//{
//    nombres.append(nombre);
//    QList <ALLEGRO_BITMAP*> estado;
//    estados.append(estado);
//}

//void Personaje::agregaSprite(QString nombreEstado,char *dirImagen)
//{
//    for(int i=0;i<estados.length();i++)
//    {
//        if(nombres.at(i)==nombreEstado)
//        {
//            //estados.at[i].append(al_load_bitmap("Terreno/Planta/0.png")));
//            //char *dir= (char*) malloc(dirImagen.data()->toLatin1() * sizeof(char));
//            estados[i].append(al_load_bitmap(dirImagen));
//        }
//    }
//}

//void Personaje::insertar(QString estado)
//{
//    noSprite++;
//    for(int i=0;i<estados.length();i++)
//    {
//        if(nombres.at(i)==estado)
//        {
//            if(noSprite>estados.at(i).length()-1)
//            {
//                noSprite=0;
//            }
//            al_draw_bitmap(estados.at(i).at(noSprite),posX,posY,voltea);
//        }
//    }
//}
