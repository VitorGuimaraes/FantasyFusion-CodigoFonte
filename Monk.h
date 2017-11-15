#ifndef _MONK_h
#define _MONK_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>			
#include <allegro5/allegro_acodec.h>

class Monk {
private:
	ALLEGRO_BITMAP *Hero_sprite[42];
	ALLEGRO_SAMPLE *sample[3];
	ALLEGRO_SAMPLE_INSTANCE *sampleinstance[3];

public:
	void loadSprites();					//Método para carregar os sprites
	void loadSamples();					//Método para carregar os samples
	
	   void basicAttack(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage);		//Método do ataque básico

	         void magic(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage);		//Método da magia 01

	       void summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font);			//Método da magia 02

		void receiveDamage(short pos_x0, short pos_y0, 
       ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
       ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
       ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//Método da animação do personagem levando dano

		     void death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//Método da animação do personagem morrendo

	ALLEGRO_BITMAP *getStop();			//Método que retorna o sprite de Monk parado
	ALLEGRO_BITMAP *getStopInverse();
	ALLEGRO_BITMAP *getVictory();
	ALLEGRO_BITMAP *getVictoryInverse();

	ALLEGRO_BITMAP *getPortrait();		//Método que retorna o sprite do portrait de Monk
	ALLEGRO_BITMAP *getDefend();		//Método que retorna o sprite de Monk em modo de defesa
	ALLEGRO_BITMAP *getDeath01();		//Método que retorna o sprite do personagem quase morto
	ALLEGRO_BITMAP *getDeath();			//Método que retorna o sprite do personagem morto
	ALLEGRO_BITMAP *text01();			//Método que retorna o sprite de texto
	ALLEGRO_BITMAP *text02();			//Método que retorna o sprite de texto

	void destroy();						//Método para desalocar a memória
};

#endif