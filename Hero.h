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
	short HP;					//Variável que armazena o HP do heroi
	short MP;					//Variável que armazena o MP do heroi
	short pos_x;				//Variável que controla a posição x do heroi
	short pos_y;				//Variável que controla a posição y do heroi
	char Name[9];				//Variável que recebe o nome do heroi
	short classe;				//Variável que controla as classes escolhidas pelo jogador
	bool Defend;				//Variável que controla se o personagem está em modo de defesa ou não

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

	void putHero(short C, short pos_X, short pos_Y);	//Método para adicionar heroi no grupo

//Métodos das ações dos heróis
	  short basicAttack(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, ALLEGRO_FONT *font2);			//Método do ataque básico

	        short magic(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font);		//Método da magia 01

	       short summon(short pos_x0, short pos_y0, 
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait, 
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font, ALLEGRO_BITMAP *update);			//Método da magia 02
		 
	void recover(ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
			     ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
			     ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
			     ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
			     ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font,
			     short hp0, short hp1, short hp2, short hp3) ;		//Método da magia de cura

	 void drawReceiveDamage(short pos_x0, short pos_y0, 
        ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
	    ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	    ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);			//Método da animação do personagem levando dano
	 
	         void death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3);				//Método da animação do personagem morrendo

	void setDefend(bool d);				//Método do modo de defesa

	void receiveDamage(short damage, ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
									 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
									 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
									 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
									 ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, short target);	//Método que aplica o dano do boss nos personagens

	ALLEGRO_BITMAP *drawPerson();						//Método para desenhar os personagens nas posições padrões
	
	ALLEGRO_BITMAP *getStop();  
	ALLEGRO_BITMAP *getStopInverse();
	ALLEGRO_BITMAP *getVictory();
	ALLEGRO_BITMAP *getVictoryInverse();

	ALLEGRO_BITMAP *drawPortrait();						//Método para desenhar o portrait do personagem 
	ALLEGRO_BITMAP *drawMagicsMenu01();					//Método para desenhar o menu de magias do personagem

	void destroy();										//Método para desalocar a memória
};

#endif