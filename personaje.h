#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <QList>

class Personaje
{
public:
    Personaje(int x,int y,bool volteado);
    ~Personaje();
    void agregaEstado();
    void agregaSprite(QString nombreEstado, char *dirImagen);
    void insertar(QString estado);
    void insertarEnEstado(int noEstado);
private:
    int posX;
    int posY;
    int voltea;
    bool npc;
    int noSprite;
    QList<QList <ALLEGRO_BITMAP*>> estados;
    QList<QString> nombresEstado;
};

#endif // PERSONAJE_H
