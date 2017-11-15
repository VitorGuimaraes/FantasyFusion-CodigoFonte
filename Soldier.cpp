#include "Soldier.h"

void Soldier::loadSprites() {						//Carrega os bitmaps
	Hero_sprite[0] = al_load_bitmap("Characters/Soldier/SStop.png");
	Hero_sprite[1] = al_load_bitmap("Characters/Soldier/SGoAttack.png");
	Hero_sprite[2] = al_load_bitmap("Characters/Soldier/SAttack01.png");
	Hero_sprite[3] = al_load_bitmap("Characters/Soldier/SAttack02.png");
	Hero_sprite[4] = al_load_bitmap("Characters/Soldier/Attack03.png");
	Hero_sprite[5] = al_load_bitmap("Characters/Soldier/BackAttack.png");
	Hero_sprite[6] = al_load_bitmap("Characters/Soldier/SReceiveDamage01.png");
	Hero_sprite[7] = al_load_bitmap("Characters/Soldier/SReceiveDamage02.png");
	Hero_sprite[8] = al_load_bitmap("Characters/Soldier/SReceiveDamage03.png");
	Hero_sprite[9] = al_load_bitmap("Characters/Soldier/Magic01.png");
	Hero_sprite[10] = al_load_bitmap("Characters/Soldier/Magic02.png");
	Hero_sprite[11] = al_load_bitmap("Characters/Soldier/Firaja01.png");
	Hero_sprite[12] = al_load_bitmap("Characters/Soldier/Firaja02.png");
	Hero_sprite[13] = al_load_bitmap("Characters/Soldier/SDefense.png");
	Hero_sprite[14] = al_load_bitmap("Characters/Soldier/SVictory.png");
	Hero_sprite[15] = al_load_bitmap("Characters/Soldier/SVictoryInverse.png");
	Hero_sprite[16] = al_load_bitmap("Characters/Soldier/SDeath01.png");
	Hero_sprite[17] = al_load_bitmap("Characters/Soldier/SDeath02.png");
	Hero_sprite[18] = al_load_bitmap("Characters/Soldier/SUpdateScreen01.png");
	Hero_sprite[19] = al_load_bitmap("Characters/Soldier/SUpdateScreen02.png");
	Hero_sprite[20] = al_load_bitmap("Characters/Soldier/SUpdateScreen03.png");
	Hero_sprite[21] = al_load_bitmap("Characters/Soldier/SUpdateScreen04.png");
	Hero_sprite[22] = al_load_bitmap("Characters/Soldier/BackGround_Ifrit.png");
	Hero_sprite[23] = al_load_bitmap("Characters/Soldier/Ifrit.png");
	Hero_sprite[24] = al_load_bitmap("Characters/Soldier/SPortrait.png");
	Hero_sprite[25] = al_load_bitmap("Characters/Soldier/DialogFiraja.png");
	Hero_sprite[26] = al_load_bitmap("Characters/Soldier/DialogIfrit.png");
	Hero_sprite[27] = al_load_bitmap("Characters/Soldier/SStop Inverse.png");
}

void Soldier::loadSamples() {			//Carrega os samples, cria instances para eles e anexa com o mixer padrão 
	sample[0] = al_load_sample("Sounds/Attack/AttackSword.ogg");
	sample[1] = al_load_sample("Sounds/Magick/CrossSlash.ogg");
	sample[2] = al_load_sample("Sounds/Magick/Firaja.ogg");
	sample[3] = al_load_sample("Sounds/Summon/Ifrit.ogg");

	for(short attach = 0; attach < 4; attach++) {		
		sampleinstance[attach] = al_create_sample_instance(sample[attach]);
		al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
	}	
}

void Soldier::basicAttack(short pos_x0, short pos_y0, 
						  ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
						  ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						  ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
						  ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 392; x--) {				//ANIMAÇÃO INDO ATACAR
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);	//Go Attack
		al_rest(0.0005);
		al_flip_display();
	}//Fim da animação de indo atacar
			
	for(int i = 2; i < 5; i++) {						//Animação do golpe com a espada
		al_play_sample_instance(sampleinstance[0]);
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[i], 287, pos_y0 - 34, 0);
		al_flip_display();
		al_rest(0.15);
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 393, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.15);
		
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 393, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.15);
	}//Fim da animação do Boss levando dano

	for(int x = 392; x < pos_x0 + 1; x++) {			//ANIMAÇAO VOLTANDO DO ATAQUE
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);	//Back Attack
		al_rest(0.0005);
		al_flip_display();
	}//Fim da animação voltando do ataque
	
	al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_flip_display();
}//Fim da animação do Ataque Básico
//====================================================================================================================

void Soldier::magic(short pos_x0, short pos_y0, 
					ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
					ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
					ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
					ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 517; x--) {			//ANIMAÇÃO INDO ATACAR
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);		//Go Attack
		al_rest(0.002);
		al_flip_display();
	}

//Pequena pausa quando chega ao destino
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss


		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);	//Desenha Soldier Parado
		al_flip_display();
		al_rest(0.2);

al_play_sample_instance(sampleinstance[2]);

	for(int i = 0; i < 6; i++) {					//ANIMAÇÃO CONJURANDO MAGIA
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[9], 518, pos_y0, 0);	//Desenha Soldier Magic01
		al_flip_display();
		al_rest(0.2);

		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[10], 518, pos_y0, 0);	//Desenha Soldier Magic02
		al_flip_display();
		al_rest(0.2);
	}

	for(int i = 0; i < 6; i++) {						//Laço que faz com que as explosões repitam 5 vezes, dando um total de 15 explosões
		float dwh = 195;								//Variável que controla o tamanho da explosão 
		float dx = 15 + (int)(400 * rand() / (RAND_MAX + 1.0));					//Variável que controla onde a explosão será desenhada no eixo X
		float dy = (int)(118 * rand() / (RAND_MAX + 1.0));						//Variável que controla onde a explosão será desenhada no eixo Y
	
		for(dwh = 195; dwh < 530; dwh += 1.5) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);			//Tela Vermelha
			al_draw_bitmap(Hero_sprite[14], 518, pos_y0, 0);	//Desenha Soldier Victory
			al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss

			al_draw_tinted_scaled_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, //Desenha Firaja 01
																				      dx, dy, dwh, dwh, 0);
			al_flip_display();	
			dx -= 1.5 / 2;
			dy -= 1.5 / 2;
		}
//=========================================================================================================================
		dwh = 195;										//Variável que controla o tamanho da explosão	
		dx = 15 + (int)(400 * rand() / (RAND_MAX + 1.0));					//Variável que controla onde a explosão será desenhada no eixo X
		dy = (int)(118 * rand() / (RAND_MAX + 1.0));						//Variável que controla onde a explosão será desenhada no eixo Y
	
		for(dwh = 195; dwh < 530; dwh += 1.5) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);			//Tela Vermelha
			al_draw_bitmap(Hero_sprite[14], 518, pos_y0, 0);	//Desenha Soldier Victory
			al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss

			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx, dy, dwh, dwh, 0);
			al_flip_display();
			dx -= 1.5 / 2;
			dy -= 1.5 / 2;	
		}
//========================================================================================================================
		dwh = 195;										//Variável que controla o tamanho da explosão	
		dx = 15 + (int)(400 * rand() / (RAND_MAX + 1.0));					//Variável que controla onde a explosão será desenhada no eixo X
		dy = (int)(118 * rand() / (RAND_MAX + 1.0));						//Variável que controla onde a explosão será desenhada no eixo Y	
	
		for(dwh = 195; dwh < 530; dwh += 1.5) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);			//Tela Vermelha
			al_draw_bitmap(Hero_sprite[14], 518, pos_y0, 0);	//Desenha Soldier Victory
			al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss

			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx, dy, dwh, dwh, 0);
			al_flip_display();	
			dx -= 1.5 / 2;
			dy -= 1.5 / 2;
		}
	}//Fecha o for que repete as explosões
//==========================================================================================================================
	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.15);
		
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.15);
	}//Fim da animação do Boss levando dano

	al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);			
	al_flip_display();
	al_rest(1.0);

	for(int x = 518; x < pos_x0 + 1; x++) {				//ANIMAÇÃO VOLTANDO DO ATAQUE
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);		//Back Attack
		al_flip_display();
		al_rest(0.002);
	}

	al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
	al_flip_display();
}//Fim do método firaja


void Soldier::summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font) {

	for(int x = pos_x0; x > 517; x--) {			//ANIMAÇÃO INDO ATACAR
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);		//Go Attack
		al_rest(0.002);
		al_flip_display();
	}
	
	//Pequena pausa quando chega ao destino
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss


		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);	//Desenha Soldier Parado
		al_flip_display();
		al_rest(0.2);

al_play_sample_instance(sampleinstance[3]);

	for(int i = 0; i < 6; i++) {					//ANIMAÇÃO CONJURANDO MAGIA
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[9], 518, pos_y0, 0);	//Desenha Soldier Magic01
		al_flip_display();
		al_rest(0.2);

		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[10], 518, pos_y0, 0);	//Desenha Soldier Magic02
		al_flip_display();
		al_rest(0.2);
	}

	for(int i = 0; i < 6; i++) {						//Laço que faz com que as explosões repitam 5 vezes, dando um total de 15 explosões	
		float ifrit_y = 23;
		float dwh = 195;								//Variável que controla o tamanho da explosão 
		float dx[8];									//Variável que controla onde a explosão será desenhada no eixo X
		float dy[8]; 									//Variável que controla onde a explosão será desenhada no eixo Y

		for(int i = 0; i < 8; i++) {
			dx[i] = 15 + (int)(700 * rand() / (RAND_MAX + 1.0));
			dy[i] = (int)(118 * rand() / (RAND_MAX + 1.0));
		}

		for(dwh = 195; dwh < 530; dwh += 1.5) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);			//Tela Vermelha
			al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss
			al_draw_bitmap(Hero_sprite[14], 518, pos_y0, 0);	//Desenha Soldier Victory
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[0], dy[0], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[1], dy[1], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[2], dy[2], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[3], dy[3], dwh, dwh, 0);
			
			al_draw_tinted_bitmap(Hero_sprite[23], al_map_rgba_f(1, 1, 1, 0.8), 290, ifrit_y, 0);		//Desenha "Ifrit"
			al_flip_display();	
			
			for(int i = 0; i < 8; i++) {
				dx[i] -= 1.5 / 2;
				dy[i] -= 1.5 / 2;
			}
			ifrit_y += 0.05;
		}
//=========================================================================================================================
		dwh = 195;										//Variável que controla o tamanho da explosão	

		for(dwh = 195; dwh < 530; dwh += 1.5) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Tela Vermelha
			al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss
			al_draw_bitmap(Hero_sprite[14], 518, pos_y0, 0);	//Desenha Soldier Victory
		
			al_draw_tinted_scaled_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[4], dy[4], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[5], dy[5], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[6], dy[6], dwh, dwh, 0);
			
			al_draw_tinted_scaled_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 195, 195, 
																				  dx[7], dy[7], dwh, dwh, 0);
			
			al_draw_tinted_bitmap(Hero_sprite[23], al_map_rgba_f(1, 1, 1, 0.8), 290, ifrit_y, 0);		//Desenha "Ifrit"
			al_flip_display();
			
			for(int i = 0; i < 8; i++) {
				dx[i] -= 1.5 / 2;
				dy[i] -= 1.5 / 2;
			}
			ifrit_y -= 0.05;
		}
	}//Fecha o for que repete as explosões

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.15);
		
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.15);
	}//Fim da animação do Boss levando dano

	al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);			
	al_flip_display();
	al_rest(1.0);

	for(int x = 518; x < pos_x0 + 1; x++) {				//ANIMAÇÃO VOLTANDO DO ATAQUE
		al_draw_bitmap(Hero_sprite[21], 0, 0, 0);	//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);			//Desenha o Boss

		al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);	//Back Attack
		al_flip_display();
		al_rest(0.002);
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[21], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);
	al_flip_display();
}//Fim de Summon

void Soldier::receiveDamage(short pos_x0, short pos_y0, 
							ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
							ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
							ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for(int i = 6; i < 9; i++) {
		al_draw_bitmap(Hero_sprite[18], 0, 0, 0);			//Atualiza tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);			//Desenha frames da animação
		al_flip_display();
		al_rest(0.3);
	}
}

void Soldier::death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for (int i = 16; i < 18; i++) {
		al_draw_bitmap(Hero_sprite[18], 0, 0, 0);	//Atualiza a tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);
		al_flip_display();
		al_rest(1.0);
	}
}

ALLEGRO_BITMAP *Soldier::getStop() {
	return Hero_sprite[0];
}

ALLEGRO_BITMAP *Soldier::getStopInverse() {
	return Hero_sprite[27];
}

ALLEGRO_BITMAP *Soldier::getVictory() {
	return Hero_sprite[14];
}

ALLEGRO_BITMAP *Soldier::getVictoryInverse() {
	return Hero_sprite[15];
}

ALLEGRO_BITMAP *Soldier::getPortrait() {
	return Hero_sprite[24];
}

ALLEGRO_BITMAP *Soldier::getDefend() {
	return Hero_sprite[13];
}

ALLEGRO_BITMAP *Soldier::getDeath01() {
	return Hero_sprite[16];
}

ALLEGRO_BITMAP *Soldier::getDeath() {
	return Hero_sprite[17];
}

ALLEGRO_BITMAP *Soldier::text01() {
	return Hero_sprite[25];
}

ALLEGRO_BITMAP *Soldier::text02() {
	return Hero_sprite[26];
}

void Soldier::destroy() {
	for (int i = 0; i < 28; i++) {
		al_destroy_bitmap(Hero_sprite[i]);
	}

	for (int i = 0; i < 4; i++) {
		al_destroy_sample(sample[i]);
	}

	for (int i = 0; i < 4; i++) {
		al_destroy_sample_instance(sampleinstance[i]);
	}
}