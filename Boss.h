#ifndef _BOSS_h
#define _BOSS_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>			
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <time.h>

class Boss {
private:
	short HP;
	ALLEGRO_BITMAP *Boss_sprite[28];
	ALLEGRO_SAMPLE *sample[3];
	ALLEGRO_SAMPLE_INSTANCE *sampleinstance[3];
	
public:
	Boss();						//M�todo Construtor Padr�o

	void setHP(short hp);
	short getHP();

	void loadSamples();					//M�todo que carrega os sons
	
	short damage();													//M�todo que calcula o dano do Boss
	short target(short hp0,short hp1, short hp2, short hp3);		//M�todo que randomiza o alvo do Boss
	
	short attack(short hp0, short hp1, short hp2, short hp3, short damage);						//M�todo Atacar

	void death();															//M�todo da anima��o do Boss quando morre

	short receiveDamage(short damage);	//M�todo que aplica o dano dos personagens no Boss

	ALLEGRO_BITMAP *getBossStop();			//M�todo que retorna o sprite do boss parado
	ALLEGRO_BITMAP *getBossReceiveDamage();  //M�todo que retorna o sprite do boss levando dano

	void destroy();						//M�todo para desalocar a mem�ria
};

#endif

