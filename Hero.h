#ifndef _Hero_h
#define _Hero_h

#include <vector>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "Soldier.h" 
#include "DivineKnight.h"
#include "Viera.h"
#include "Monk.h"

class Hero {
private:
	short HP;					//Vari�vel que armazena o HP do heroi
	short MP;					//Vari�vel que armazena o MP do heroi
	short pos_x;				//Vari�vel que controla a posi��o x do heroi
	short pos_y;				//Vari�vel que controla a posi��o y do heroi
	char Name[9];				//Vari�vel que recebe o nome do heroi
	short classe;				//Vari�vel que controla as classes escolhidas pelo jogador
	bool Defend;				//Vari�vel que controla se o personagem est� em modo de defesa ou n�o

	Soldier soldier;			//Cria um objeto do tipo Soldier
	DivineKnight divineknight;	//Cria um objeto do tipo DivineKnight
	Viera viera;				//Cria um objeto do tipo Viera
	Monk monk;					//Cria um objeto do tipo Monk

public:
	Hero();
	void setHP(short hp);
	short getHP();	
	 
	void setMP(short mp);
	short getMP();

	short getpos_x();

	void setpos_y(short pos_Y);
	short getpos_y();

	void setName(char n[12]);
	char *getName();

	short getclass();

	void putHero(short C, short pos_X, short pos_Y);	//M�todo para adicionar heroi no grupo

//M�todos das a��es dos her�is
	  short basicAttack(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, ALLEGRO_FONT *font2);			//M�todo do ataque b�sico

	        short magic(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font);		//M�todo da magia 01

	       short summon(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait, 
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font, ALLEGRO_BITMAP *update);			//M�todo da magia 02
		 
	void recover(ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
			     ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
			     ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
			     ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
			     ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font,
			     short hp0, short hp1, short hp2, short hp3) ;		//M�todo da magia de cura

	 void drawReceiveDamage(short pos_x0, short pos_y0, 
        ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	    ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	    ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);			//M�todo da anima��o do personagem levando dano
	 
	         void death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//M�todo da anima��o do personagem morrendo

	void setDefend(bool d);				//M�todo do modo de defesa

	void receiveDamage(short damage, ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
									 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
									 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
									 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
									 ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, short target);	//M�todo que aplica o dano do boss nos personagens

	ALLEGRO_BITMAP *drawPerson();						//M�todo para desenhar os personagens nas posi��es padr�es
	
	ALLEGRO_BITMAP *getStop();  
	ALLEGRO_BITMAP *getStopInverse();
	ALLEGRO_BITMAP *getVictory();
	ALLEGRO_BITMAP *getVictoryInverse();

	ALLEGRO_BITMAP *drawPortrait();						//M�todo para desenhar o portrait do personagem 
	ALLEGRO_BITMAP *drawMagicsMenu01();					//M�todo para desenhar o menu de magias do personagem

	void destroy();										//M�todo para desalocar a mem�ria
};

#endif