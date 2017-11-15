#include "Viera.h"

void Viera::loadSprites() {
	Hero_sprite[0] = al_load_bitmap("Characters/Viera/VStop.png");
	Hero_sprite[1] = al_load_bitmap("Characters/Viera/VAttack01.png");
	Hero_sprite[2] = al_load_bitmap("Characters/Viera/VAttack02.png");
	Hero_sprite[3] = al_load_bitmap("Characters/Viera/Arrow.png");
	Hero_sprite[4] = al_load_bitmap("Characters/Viera/VMagic.png");
	Hero_sprite[5] = al_load_bitmap("Characters/Viera/Thundaja00.png");
	Hero_sprite[6] = al_load_bitmap("Characters/Viera/Thundaja01.png");
	Hero_sprite[7] = al_load_bitmap("Characters/Viera/Thundaja02.png");
	Hero_sprite[8] = al_load_bitmap("Characters/Viera/Thundaja03.png");
	Hero_sprite[9] = al_load_bitmap("Characters/Viera/VDefense.png");
	Hero_sprite[10] = al_load_bitmap("Characters/Viera/VConjuring.png");
	Hero_sprite[11] = al_load_bitmap("Characters/Viera/VVictoryInverse.png");
	Hero_sprite[12] = al_load_bitmap("Characters/Viera/VDeath01.png");
	Hero_sprite[13] = al_load_bitmap("Characters/Viera/VDeath02.png");
	Hero_sprite[14] = al_load_bitmap("Characters/Viera/VUpdateScreen01.png");
	Hero_sprite[15] = al_load_bitmap("Characters/Viera/VUpdateScreen02.png");
	Hero_sprite[16] = al_load_bitmap("Characters/Viera/VUpdateScreen03.png");
	Hero_sprite[17] = al_load_bitmap("Characters/Viera/VUpdateScreen04.png");
	Hero_sprite[18] = al_load_bitmap("Characters/Viera/VUpdateScreen05.png");
	Hero_sprite[19] = al_load_bitmap("Characters/Viera/UpdateScreen06.png");
	Hero_sprite[20] = al_load_bitmap("Characters/Viera/BackGround_Ramuh.png");
	Hero_sprite[21] = al_load_bitmap("Characters/Viera/VReceiveDamage01.png");
	Hero_sprite[22] = al_load_bitmap("Characters/Viera/VReceiveDamage02.png");
	Hero_sprite[23] = al_load_bitmap("Characters/Viera/VReceiveDamage03.png");
	Hero_sprite[24] = al_load_bitmap("Characters/Viera/Ramuh.png");
	Hero_sprite[25] = al_load_bitmap("Characters/Viera/Ramuh02.png");
	Hero_sprite[26] = al_load_bitmap("Characters/Viera/Ramuh03.png");
	Hero_sprite[27] = al_load_bitmap("Characters/Viera/Ramuh04.png");
	Hero_sprite[28] = al_load_bitmap("Characters/Viera/UpdateScreen07.png");
	Hero_sprite[29] = al_load_bitmap("Characters/Viera/VPortrait.png");
	Hero_sprite[30] = al_load_bitmap("Characters/Viera/DialogThundaja.png");
	Hero_sprite[31] = al_load_bitmap("Characters/Viera/DialogRamuh.png");
	Hero_sprite[32] = al_load_bitmap("Characters/Viera/VStop Inverse.png");
	Hero_sprite[33] = al_load_bitmap("Characters/Viera/VVictory.png");
}

void Viera::loadSamples() {
	sample[0] = al_load_sample("Sounds/Attack/ArrowShot.ogg");
	sample[1] = al_load_sample("Sounds/Magick/Thundaja.ogg");
	sample[2] = al_load_sample("Sounds/Summon/Ramuh.ogg");
	sample[3] = al_load_sample("Sounds/Attack/CriticalShot.ogg");

	for(short attach = 0; attach < 4; attach++) {		
	sampleinstance[attach] = al_create_sample_instance(sample[attach]);
	al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
	}
}

void Viera::basicAttack(short pos_x0, short pos_y0, 
						ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
						ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
						ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {	

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[1], pos_x0 - 32, pos_y0, 0);		//Desenha "Attack 01"	
	al_flip_display();
	al_rest(0.3);

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[2], pos_x0 - 32, pos_y0, 0);		//Desenha "Attack 02"
	al_flip_display();
	al_rest(0.2);

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);		//Desenha "Viera Stop"
	al_flip_display();

	for(float f = pos_x0 - 97; f > 205; f -= 1.5) {		
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);		//Desenha "Viera Stop"
		al_draw_bitmap(Hero_sprite[3], f, pos_y0, 0);	//Desenha "Arrow"
		al_flip_display();
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano
}

void Viera::magic(short pos_x0, short pos_y0, 
				  ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
				  ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
				  ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
				  ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

al_play_sample_instance(sampleinstance[1]);

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[4], pos_x0 - 26, pos_y0, 0);	//Desenha Viera "Magic"
	al_flip_display();
	al_rest(2.3);

	al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);	//Desenha Viera "Victory"
	al_flip_display();

		float alpha = 0.9;
		for(int j = 0; j < 5; j++) {
			for(int i = 6; i < 9; i++) {
				al_draw_bitmap(Hero_sprite[20], 0, 0, 0);
				al_draw_bitmap(H1, pos_x1, pos_y1, 0);
				al_draw_bitmap(H2, pos_x2, pos_y2, 0);
				al_draw_bitmap(H3, pos_x3, pos_y3, 0);
				al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

				al_draw_bitmap(Hero_sprite[i], 0, 0, 0);
				al_draw_tinted_bitmap(Hero_sprite[5], al_map_rgba_f(1, 1, 1, alpha), 0, 0, 0);
				al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);	//Desenha Viera "Victory"
				al_flip_display();
				al_rest(0.3);

				alpha -= 0.1;
				if(alpha <= 0.4)
					alpha = 0.8;
			}
		}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);
	al_flip_display();
}

void Viera::summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font) {

al_play_sample_instance(sampleinstance[2]);

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[4], pos_x0 - 26, pos_y0, 0);	//Desenha Viera "Magic"
	al_flip_display();
	al_rest(2.3);

	al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);	//Desenha Viera "Victory"
	al_flip_display();

	float ramuhpos_x = 627;
	for(float ramuhpos_y = -285; ramuhpos_y < 47; ramuhpos_y++) {		//Ramuh vai até o centro da tela
		al_draw_bitmap(Hero_sprite[20], 0, 0, 0);					//Desenha o Background de Ramuh
		al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);	//Desenha "Viera Victory"
		al_draw_bitmap(boss, 57, 171, 0);							//Desenha o Boss
		al_draw_bitmap(Hero_sprite[24], ramuhpos_x, ramuhpos_y, 0);	//Desenha Ramuh
		al_flip_display();
		al_rest(0.005);
		ramuhpos_x--;
	} 

	ramuhpos_x = 329;
	float ramuhpos_y = 46;

	for(int i = 0; i < 3; i++) {
		for(float alpha = 0; alpha < 256; alpha += 60)  {
			al_draw_tinted_bitmap(Hero_sprite[28], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);	//Desenha o fundo
			al_draw_bitmap(Hero_sprite[24], 329, 46, 0);											//Desenha Ramuh
			al_draw_bitmap(boss, 57, 171, 0);														//Desenha o Boss
			al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);								//Desenha "Viera Victory"

			for(int raio = 25; raio < 28; raio++) {
				al_draw_bitmap(Hero_sprite[raio], 0, 0, 0);											//Desenha os raios
				al_flip_display();
				al_rest(0.07);
			}
		}
	}

	ramuhpos_x = 329;
	for(float ramuhpos_y = 46; ramuhpos_y > -285; ramuhpos_y --) {		//Ramuh volta do centro da tela
		al_draw_bitmap(Hero_sprite[20], 0, 0, 0);						//Desenha o Background de Ramuh
		al_draw_bitmap(Hero_sprite[10], pos_x0 - 26, pos_y0, 0);				//Desenha "Viera Victory"
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[24], ramuhpos_x, ramuhpos_y, 0);	//Desenha Ramuh
		al_flip_display();
		al_rest(0.005);
		ramuhpos_x ++;
	} 

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[17], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	al_draw_bitmap(Hero_sprite[17], 0, 0, 0);				//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(boss, 57, 171, 0);								//Desenha o Boss
	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);				//Desenha "Viera Stop"
	al_flip_display();
}//Fim de summon

void Viera::receiveDamage(short pos_x0, short pos_y0, 
						  ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
						  ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						  ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for(int i = 21; i < 24; i++) {
		al_draw_bitmap(Hero_sprite[14], 0, 0, 0);			//Atualiza tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);			//Desenha frames da animação
		al_flip_display();
		al_rest(0.3);
	}
}

void Viera::death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for(int i = 12; i < 14; i++) {
		al_draw_bitmap(Hero_sprite[14], 0, 0, 0);	//Atualiza a tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);
		al_flip_display();
		al_rest(1.0);
	}
}

ALLEGRO_BITMAP *Viera:: getStop() {
		return Hero_sprite[0];
}

ALLEGRO_BITMAP *Viera::getStopInverse() {
	return Hero_sprite[32];
}

ALLEGRO_BITMAP *Viera::getVictory() {
	return Hero_sprite[33];
}

ALLEGRO_BITMAP *Viera::getVictoryInverse() {
	return Hero_sprite[11];
}

ALLEGRO_BITMAP *Viera::getPortrait() {
	return Hero_sprite[29];
}

ALLEGRO_BITMAP *Viera::getDefend() {
	return Hero_sprite[9];
}

ALLEGRO_BITMAP *Viera::getDeath01() {
	return Hero_sprite[12];
}

ALLEGRO_BITMAP *Viera::getDeath() {
	return Hero_sprite[13];
}

ALLEGRO_BITMAP *Viera::text01() {
	return Hero_sprite[30];
}

ALLEGRO_BITMAP *Viera::text02() {
	return Hero_sprite[31];
}

ALLEGRO_SAMPLE_INSTANCE *Viera::shot() {
	return sampleinstance[0];
}

ALLEGRO_SAMPLE_INSTANCE *Viera::criticalshot() {
	return sampleinstance[3];
}

void Viera::destroy() {
	for(int i = 0; i < 34; i++) {
		al_destroy_bitmap(Hero_sprite[i]);
	}

	for(int i = 0; i < 4; i++) {
		al_destroy_sample(sample[i]);
	}

	for(int i = 0; i < 3; i++) {
		al_destroy_sample_instance(sampleinstance[i]);
	}
}