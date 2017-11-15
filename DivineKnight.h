#ifndef _DIVINEKNIGHT_h
#define _DIVINEKNIGHT_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>			
#include <allegro5/allegro_acodec.h>

class DivineKnight {
private:
	ALLEGRO_BITMAP *Hero_sprite[48];
	ALLEGRO_SAMPLE *sample[6];
	ALLEGRO_SAMPLE_INSTANCE *sampleinstance[6];

public:
	void loadSprites();					//M�todo para carregar os sprites
	void loadSamples();					//M�todo para carregar os sons

	   void basicAttack(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage);			//M�todo do ataque b�sico

             void magic(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage);			//M�todo da magia 01

		    void summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font);			//M�todo da magia 02
	
	void recover(ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
				 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,   
				 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,   
				 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
				 ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font,
				 short hp0, short hp1, short hp2, short hp3);		//M�todo da magia que recupera HP

	  void receiveDamage(short pos_x0, short pos_y0, 
     ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
     ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
     ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//M�todo da anima��o do personagem levando dano

		     void death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//M�todo da anima��o do personagem morrendo
		
	ALLEGRO_BITMAP *getStop();			//M�todo que retorna o sprite de DivineKnight parado
	ALLEGRO_BITMAP *getStopInverse();
	ALLEGRO_BITMAP *getVictory();
	ALLEGRO_BITMAP *getVictoryInverse();

	ALLEGRO_BITMAP *getPortrait();		//M�todo que retorna o sprite do portrait de DivineKnight
	ALLEGRO_BITMAP *getDefend();		//M�todo que retorna o sprite de DivineKnight em modo de defesa
	ALLEGRO_BITMAP *getDeath01();		//M�todo que retorna o sprite do personagem quase morto
	ALLEGRO_BITMAP *getDeath();			//M�todo que retorna o sprite do personagem morto
	ALLEGRO_BITMAP *getMagics01();		//M�todo que retorna o sprite do menu de magias de DivineKnight
	ALLEGRO_BITMAP *text01();			//M�todo que retorna o sprite de texto
	ALLEGRO_BITMAP *text02();			//M�todo que retorna o sprite de texto
	ALLEGRO_BITMAP *text03();			//M�todo que retorna o sprite de texto
	ALLEGRO_BITMAP *text04();			//M�todo que retorna o sprite de texto

	void destroy();						//M�todo para desalocar a mem�ria
};

#endif