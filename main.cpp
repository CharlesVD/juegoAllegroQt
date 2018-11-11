#include "mijuego.h"

ALLEGRO_DISPLAY *ventana;
ALLEGRO_KEYBOARD_STATE estadoTeclado;

int estadoPersonaje=0;
int posPersonajeX=100;
int posPersonajeY=100;
int personajeVoltea=0;

int estadoEnemigo=0;
int posEnemigoX=300;
int posEnemigoY=300;
int enemigoVoltea=0;

ALLEGRO_BITMAP *terreno[4];
ALLEGRO_BITMAP *torre[2];

ALLEGRO_BITMAP *personaje_parado;
int animHeroeParado=0;

ALLEGRO_BITMAP *enemigo_parado;

ALLEGRO_BITMAP *personaje_camina[9];
int animHeroeCamina=0;

ALLEGRO_BITMAP *enemigo_camina[12];
int animEnemigoCamina=0;

ALLEGRO_BITMAP *personaje_pega[8];
int animHeroePega=0;

ALLEGRO_BITMAP *enemigo_pega[5];
int animEnemigoPega=0;

void dibujaPersonaje();
void dibujaEnemigo();

void dibujaPersonaje()
{
    switch(estadoPersonaje)
    {
        case 0:
            al_draw_bitmap(personaje_parado,posPersonajeX,posPersonajeY,personajeVoltea);
//            animHeroeParado++;
        break;
        case 1:
            al_draw_bitmap(personaje_camina[animHeroeCamina],posPersonajeX,posPersonajeY,personajeVoltea);
            animHeroeCamina++;
        break;
        case 2:
            al_draw_bitmap(personaje_pega[animHeroePega],posPersonajeX,posPersonajeY,personajeVoltea);
            animHeroePega++;
            //al_play_sample(espada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
        break;
    }
}

void dibujaEnemigo()
{
    switch(estadoEnemigo)
    {
        case 0:
            al_draw_bitmap(enemigo_parado,posEnemigoX,posEnemigoY,enemigoVoltea);
        break;
        case 1:
            al_draw_bitmap(enemigo_camina[animEnemigoCamina],posEnemigoX,posEnemigoY,enemigoVoltea);
            animEnemigoCamina++;
        break;
            case 2:
                al_draw_bitmap(enemigo_pega[animEnemigoPega],posEnemigoX,posEnemigoY,enemigoVoltea);
                animEnemigoPega++;
                //al_play_sample(espada, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
            break;
    }
}

int main(int argc, char *argv[])
{

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *FuentePuntuacion;
    FuentePuntuacion = al_load_ttf_font("Fuentes/ELEPHNT.TTF", 12,0);

    Personaje Heroe(300,300,false);

    torre[0] = al_load_bitmap("Construccion/Torre/0.png");
    torre[1] = al_load_bitmap("Construccion/Torre/1.png");

    terreno[0] = al_load_bitmap("Terreno/Planta/0.png");
    terreno[1] = al_load_bitmap("Terreno/Planta/1.png");
    terreno[2] = al_load_bitmap("Terreno/Planta/2.png");
    terreno[3] = al_load_bitmap("Terreno/Planta/3.png");

    personaje_parado = al_load_bitmap("Heroe/Caminar/0.png");

    enemigo_parado = al_load_bitmap("Esqueleto/Caminar/0.png");

    personaje_camina[0] = al_load_bitmap("Heroe/Caminar/0.png");
    personaje_camina[1] = al_load_bitmap("Heroe/Caminar/1.png");
    personaje_camina[2] = al_load_bitmap("Heroe/Caminar/2.png");
    personaje_camina[3] = al_load_bitmap("Heroe/Caminar/3.png");
    personaje_camina[4] = al_load_bitmap("Heroe/Caminar/4.png");
    personaje_camina[5] = al_load_bitmap("Heroe/Caminar/5.png");
    personaje_camina[6] = al_load_bitmap("Heroe/Caminar/6.png");
    personaje_camina[7] = al_load_bitmap("Heroe/Caminar/7.png");
    personaje_camina[8] = al_load_bitmap("Heroe/Caminar/8.png");

    enemigo_camina[0] = al_load_bitmap("Esqueleto/Caminar/0.png");
    enemigo_camina[1] = al_load_bitmap("Esqueleto/Caminar/1.png");
    enemigo_camina[2] = al_load_bitmap("Esqueleto/Caminar/2.png");
    enemigo_camina[3] = al_load_bitmap("Esqueleto/Caminar/3.png");
    enemigo_camina[4] = al_load_bitmap("Esqueleto/Caminar/4.png");
    enemigo_camina[5] = al_load_bitmap("Esqueleto/Caminar/5.png");
    enemigo_camina[6] = al_load_bitmap("Esqueleto/Caminar/6.png");

    personaje_pega[0] = al_load_bitmap("Heroe/Atacar/0.png");
    personaje_pega[1] = al_load_bitmap("Heroe/Atacar/1.png");
    personaje_pega[2] = al_load_bitmap("Heroe/Atacar/2.png");
    personaje_pega[3] = al_load_bitmap("Heroe/Atacar/3.png");
    personaje_pega[4] = al_load_bitmap("Heroe/Atacar/4.png");
    personaje_pega[5] = al_load_bitmap("Heroe/Atacar/3.png");
    personaje_pega[6] = al_load_bitmap("Heroe/Atacar/2.png");
    personaje_pega[7] = al_load_bitmap("Heroe/Atacar/1.png");

    enemigo_pega[0] = al_load_bitmap("Esqueleto/Atacar/0.png");
    enemigo_pega[1] = al_load_bitmap("Esqueleto/Atacar/1.png");
    enemigo_pega[2] = al_load_bitmap("Esqueleto/Atacar/2.png");
    enemigo_pega[3] = al_load_bitmap("Esqueleto/Atacar/1.png");
    enemigo_pega[4] = al_load_bitmap("Esqueleto/Atacar/0.png");

    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    unsigned int Mx=800;
    unsigned int My=600;

    QList<int> plantaX;
    QList<int> plantaY;
    QList<int> plantaTipo;
    srand( QTime::currentTime().second() );
    for(int i=0;i<900;i++)
    {
        plantaX.append(rand()%Mx);
        plantaY.append(rand()%My);
        plantaTipo.append((rand()%4));
    }

    ventana = al_create_display(Mx,My);

    QCoreApplication a(argc, argv);

    QTimer *entradas;
    entradas = new QTimer(&a);
    entradas->start(5);

//    QTimer *escenario;
//    escenario = new QTimer(&a);
    //escenario->start(8);

    QTimer *animPersonaje;
    animPersonaje = new QTimer(&a);
    animPersonaje->start(70);

    QObject::connect(entradas, &QTimer::timeout, [&]()
    {
        estadoPersonaje=0;
        estadoEnemigo=0;
        al_get_keyboard_state(&estadoTeclado);
        if (al_key_down(&estadoTeclado, ALLEGRO_KEY_ESCAPE))
        {
            a.exit(0);
        }

        if (al_key_down(&estadoTeclado, ALLEGRO_KEY_SPACE))
        {
            estadoPersonaje=2;
        }
        else
        {
            animHeroePega=0;
            if (al_key_down(&estadoTeclado, ALLEGRO_KEY_LEFT) && posPersonajeX>0)
            {
                estadoPersonaje=1;
                posPersonajeX--;
                personajeVoltea=0;
            }
            if (al_key_down(&estadoTeclado, ALLEGRO_KEY_RIGHT) && posPersonajeX<Mx-80)
            {
                estadoPersonaje=1;
                posPersonajeX++;
                personajeVoltea=1;
            }
            if (al_key_down(&estadoTeclado, ALLEGRO_KEY_UP) && posPersonajeY>0)
            {
                estadoPersonaje=1;
                posPersonajeY--;
            }
            if (al_key_down(&estadoTeclado, ALLEGRO_KEY_DOWN) && posPersonajeY<My-120)
            {
                estadoPersonaje=1;
                posPersonajeY++;
            }
        }

        if(al_key_down(&estadoTeclado, ALLEGRO_KEY_Q))
        {
            estadoEnemigo=2;
        }
        else
        {
            animEnemigoPega=0;
            if(al_key_down(&estadoTeclado, ALLEGRO_KEY_A))
            {
                posEnemigoX--;
                estadoEnemigo=1;
                enemigoVoltea=0;
            }
            if(al_key_down(&estadoTeclado, ALLEGRO_KEY_D))
            {
                posEnemigoX++;
                estadoEnemigo=1;
                enemigoVoltea=1;
            }
            if(al_key_down(&estadoTeclado, ALLEGRO_KEY_S))
            {
                posEnemigoY++;
                estadoEnemigo=1;
            }
            if(al_key_down(&estadoTeclado, ALLEGRO_KEY_W))
            {
                posEnemigoY--;
                estadoEnemigo=1;
            }
        }

    });

//    QObject::connect(escenario, &QTimer::timeout, [&]()
//    {
//        al_flip_display();
//        al_clear_to_color(al_map_rgb(255,255,255));
//    });

    QObject::connect(animPersonaje, &QTimer::timeout, [&]()
    {
        if(animHeroeCamina>7)
        {
            animHeroeCamina=0;
        }
        if(animHeroePega>7)
        {
            animHeroePega=0;
        }
        if(animEnemigoCamina>6)
        {
            animEnemigoCamina=0;
        }
        if(animEnemigoPega>4)
        {
            animEnemigoPega=0;
        }

        if(posPersonajeY+5>posEnemigoY)
        {
            dibujaEnemigo();
            dibujaPersonaje();
        }
        else
        {
            dibujaPersonaje();
            dibujaEnemigo();
        }

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,150,0));
        for(int i=0;i<900;i++)
        {
            al_draw_bitmap(terreno[plantaTipo.at(i)],plantaX.at(i),plantaY.at(i),0);
        }
        al_draw_bitmap(torre[1],500,100,0);
        al_draw_bitmap(torre[0],500,100,0);
        al_draw_bitmap(torre[1],300,100,0);
        al_draw_bitmap(torre[0],300,100,0);
        char texto[3];
        itoa(posPersonajeX,texto,10);
        al_draw_text(FuentePuntuacion,al_map_rgb(0,0,0), 50, 50,ALLEGRO_ALIGN_LEFT,texto);
    });

    return a.exec();
}
