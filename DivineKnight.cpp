#include "DivineKnight.h"

void DivineKnight::loadSprites() {
	Hero_sprite[0] = al_load_bitmap("Characters/DivineKnight/DStop.png");
	Hero_sprite[1] = al_load_bitmap("Characters/DivineKnight/GoAttack01.png");
	Hero_sprite[2] = al_load_bitmap("Characters/DivineKnight/GoAttack02.png");
	Hero_sprite[3] = al_load_bitmap("Characters/DivineKnight/DAttack01.png");
	Hero_sprite[4] = al_load_bitmap("Characters/DivineKnight/DAttack02.png");
	Hero_sprite[5] = al_load_bitmap("Characters/DivineKnight/DBackAttack01.png");
	Hero_sprite[6] = al_load_bitmap("Characters/DivineKnight/DBackAttack02.png");
	Hero_sprite[7] = al_load_bitmap("Characters/DivineKnight/GoMagic.png");
	Hero_sprite[8] = al_load_bitmap("Characters/DivineKnight/DMagic.png");
	Hero_sprite[9] = al_load_bitmap("Characters/DivineKnight/BackMagic.png");
	Hero_sprite[10] = al_load_bitmap("Characters/DivineKnight/Blizzaja01.png");
	Hero_sprite[11] = al_load_bitmap("Characters/DivineKnight/Blizzaja02.png");
	Hero_sprite[12] = al_load_bitmap("Characters/DivineKnight/Blizzaja03.png");
	Hero_sprite[13] = al_load_bitmap("Characters/DivineKnight/Blizzaja04.png");
	Hero_sprite[14] = al_load_bitmap("Characters/DivineKnight/DDefense.png");
	Hero_sprite[15] = al_load_bitmap("Characters/DivineKnight/DVictory.png");
	Hero_sprite[16] = al_load_bitmap("Characters/DivineKnight/DVictoryInverse.png");
	Hero_sprite[17] = al_load_bitmap("Characters/DivineKnight/DDeath01.png");
	Hero_sprite[18] = al_load_bitmap("Characters/DivineKnight/DDeath02.png");
	Hero_sprite[19] = al_load_bitmap("Characters/DivineKnight/DUpdateScreen01.png");
	Hero_sprite[20] = al_load_bitmap("Characters/DivineKnight/DUpdateScreen02.png");
	Hero_sprite[21] = al_load_bitmap("Characters/DivineKnight/DUpdateScreen03.png");
	Hero_sprite[22] = al_load_bitmap("Characters/DivineKnight/DUpdateScreen04.png");
	Hero_sprite[23] = al_load_bitmap("Characters/DivineKnight/BackGround_Shiva.png");
	Hero_sprite[24] = al_load_bitmap("Characters/DivineKnight/Shiiva.png");
	Hero_sprite[25] = al_load_bitmap("Characters/DivineKnight/Shiiva02.png");
	Hero_sprite[26] = al_load_bitmap("Characters/DivineKnight/Shiiva03.png");
	Hero_sprite[27] = al_load_bitmap("Characters/DivineKnight/DReceiveDamage01.png");
	Hero_sprite[28] = al_load_bitmap("Characters/DivineKnight/DReceiveDamage02.png");
	Hero_sprite[29] = al_load_bitmap("Characters/DivineKnight/DReceiveDamage03.png");
	Hero_sprite[30] = al_load_bitmap("Characters/DivineKnight/DPortrait.png");
	Hero_sprite[31] = al_load_bitmap("Characters/DivineKnight/HeartRefresh01.png");
	Hero_sprite[32] = al_load_bitmap("Characters/DivineKnight/HeartRefresh02.png");
	Hero_sprite[33] = al_load_bitmap("Characters/DivineKnight/HeartRefresh03.png");
	Hero_sprite[34] = al_load_bitmap("Characters/DivineKnight/HeartRefresh04.png");
	Hero_sprite[35] = al_load_bitmap("Characters/DivineKnight/HeartRefresh05.png");
	Hero_sprite[36] = al_load_bitmap("Characters/DivineKnight/HeartRefreshUpdate.png");
	Hero_sprite[37] = al_load_bitmap("Characters/DivineKnight/Magics01.png");
	Hero_sprite[38] = al_load_bitmap("Characters/DivineKnight/DialogStasisSword.png");
	Hero_sprite[39] = al_load_bitmap("Characters/DivineKnight/DialogBlizzaja.png");
	Hero_sprite[40] = al_load_bitmap("Characters/DivineKnight/DialogHeartRefresh.png");
	Hero_sprite[41] = al_load_bitmap("Characters/DivineKnight/DialogShiiva.png");
	Hero_sprite[42] = al_load_bitmap("Characters/DivineKnight/BackGround_StasisSword.png");
	Hero_sprite[43] = al_load_bitmap("Characters/DivineKnight/Stasis01.png");
	Hero_sprite[44] = al_load_bitmap("Characters/DivineKnight/Stasis02.png");
	Hero_sprite[45] = al_load_bitmap("Characters/DivineKnight/Stasis03.png");
	Hero_sprite[46] = al_load_bitmap("Characters/DivineKnight/Stasis04.png");
	Hero_sprite[47] = al_load_bitmap("Characters/DivineKnight/DStop Inverse.png");
}

void DivineKnight::loadSamples() {
	sample[0] = al_load_sample("Sounds/Attack/AttackSword.ogg");
	sample[1] = al_load_sample("Sounds/Attack/StasisSword.ogg");
	sample[2] = al_load_sample("Sounds/Magick/Blizzaja.ogg");
	sample[3] = al_load_sample("Sounds/Magick/HeartRefresh.ogg");
	sample[4] = al_load_sample("Sounds/Summon/Shiva.ogg");
	sample[5] = al_load_sample("Sounds/Magick/Healing.ogg");

	for(short attach = 0; attach < 6; attach++) {		
		sampleinstance[attach] = al_create_sample_instance(sample[attach]);
		al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
	}
}

void DivineKnight::basicAttack(short pos_x0, short pos_y0, 
							   ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
							   ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
							   ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
							   ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 346; x--) {		//ANIMAÇÃO INDO ATACAR			
		if(x > 460) {
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);		//Go Attack 01
			al_flip_display();
			al_rest(0.005);
		}

		else if(x <= 460) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[2], x, pos_y0, 0);	//"Go Attack 02"
			al_flip_display();
			al_rest(0.005);
		}
	}//Fim da animação de indo atacar

	al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

al_play_sample_instance(sampleinstance[1]);

	al_draw_bitmap(Hero_sprite[3], 290, pos_y0 - 6, 0);	//Desenha "Attack 01"
	al_flip_display();
	al_rest(0.15);

	al_draw_bitmap(Hero_sprite[42], 0, 0, 0);	//Desenha o Fundo Escuro
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
	al_draw_bitmap(Hero_sprite[4], 290, pos_y0 - 6, 0);	//Desenha "Attack 02"
	al_flip_display();
	al_rest(0.3);

//Stasis Sword
	for(float y = -397; y < 1; y += 4) {
		al_draw_bitmap(Hero_sprite[42], 0, 0, 0);	//Desenha o Fundo Escuro
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[4], 290, pos_y0 - 6, 0);	//Desenha "Attack 02"

		al_draw_tinted_bitmap(Hero_sprite[43], al_map_rgba_f(1, 1, 1, 0.1), 0, y, 0);
		al_flip_display();
	}

	for(float y = -397; y < 1; y += 4) {
		al_draw_bitmap(Hero_sprite[42], 0, 0, 0);	//Desenha o Fundo Escuro
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[4], 290, pos_y0 - 6, 0);	//Desenha "Attack 02"

		al_draw_tinted_bitmap(Hero_sprite[43], al_map_rgba_f(1, 1, 1, 0.1), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[44], al_map_rgba_f(1, 1, 1, 0.1), 0, y, 0);
		al_flip_display();
	}

	for(float y = -397; y < 1; y += 4) {
		al_draw_bitmap(Hero_sprite[42], 0, 0, 0);	//Desenha o Fundo Escuro
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[4], 290, pos_y0 - 6, 0);	//Desenha "Attack 02"

		al_draw_tinted_bitmap(Hero_sprite[43], al_map_rgba_f(1, 1, 1, 0.1), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[44], al_map_rgba_f(1, 1, 1, 0.1), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[45], al_map_rgba_f(1, 1, 1, 0.1), 0, y, 0);
		al_flip_display();
	}
	al_rest(0.5);

	for(float alpha = 0; alpha < 256; alpha += 0.7) {
		al_draw_bitmap(Hero_sprite[42], 0, 0, 0);	//Desenha o Fundo Escuro
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[4], 290, pos_y0 - 6, 0);	//Desenha "Attack 02"

		al_draw_tinted_bitmap(Hero_sprite[43], al_map_rgba_f(1, 1, 1, alpha / 255.0), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[44], al_map_rgba_f(1, 1, 1, alpha / 255.0), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[45], al_map_rgba_f(1, 1, 1, alpha / 255.0), 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[46], al_map_rgba_f(1, 1, 1, alpha / 255.0), 0, 0, 0);
		al_flip_display();
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 342, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 342, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	for(int x = 290; x < pos_x0 - 52; x++) {	//ANIMAÇÃO VOLTANDO DO ATAQUE
		if(x < 460){
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);	//"Back Attack 01"
			al_flip_display();
			al_rest(0.005);
		}

		else if(x >= 460) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[6], x, pos_y0, 0);	//"Back Attack 02"
			al_flip_display();
			al_rest(0.005);
		}
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);			//Desenha "DivineKnight Stop"
	al_flip_display();
}//Fim da animação do Ataque Básico

void DivineKnight::magic(short pos_x0, short pos_y0, 
						 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
						 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
						 ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 517; x--) {		//ANIMAÇÃO INDO ATACAR			
		if(x > 460) {
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);		//Go Attack 01
			al_flip_display();
			al_rest(0.005);
		}

		else if(x <= 460) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[7], x, pos_y0, 0);	//"Go Magic 01"
			al_flip_display();
			al_rest(0.005);
		}
	}//Fim de indo atacar

al_play_sample_instance(sampleinstance[2]);

	al_draw_bitmap(Hero_sprite[23], 0, 0, 0);			//Desenha o Background Azul
	al_draw_bitmap(boss, 57, 171, 0);						//Desenha o Boss
	al_draw_bitmap(Hero_sprite[8], 518 - 23, pos_y0, 0);
	al_flip_display();
	al_rest(3.0);

	for(int i = 0; i < 3; i++) {						//Laço que faz o gelo cair 3 vezes	
		float blizpos_y = -412;
		for(float blizpos_x = 186; blizpos_x > 87; blizpos_x -= 0.25) {
			al_draw_bitmap(Hero_sprite[23], 0, 0, 0);				//Desenha o Background Azul
			al_draw_bitmap(Hero_sprite[8], 518 - 23, pos_y0, 0);	//Desenha "Divine Knight Magic"
			al_draw_bitmap(boss, 57, 171, 0);						//Desenha o Boss
			al_draw_tinted_bitmap(Hero_sprite[10], al_map_rgba_f(1, 1, 1, 0.6), blizpos_x, blizpos_y, 0);
			al_flip_display();
			al_rest(0.0013);
			blizpos_y += 1.0625;
		}

		float blizpart02_x = 118;			//Variável que controla a pos_x da partícula 02
		float blizpart03_x = 133;			//Variável que controla a pos_x da partícula 03

		float blizpart01_y = 254;			//Variável que controla a pos_y da partícula 01
		float blizpart02_y = 237;			//Variável que controla a pos_y da partícula 02
		float blizpart03_y = 303;			//Variável que controla a pos_y da partícula 03
		float alpha = 1.0;					//Variável que controla o alpha das partículas

		for(float blizpart01_x = 88; blizpart01_x > 0; blizpart01_x -= 0.35) {		
			al_draw_bitmap(Hero_sprite[23], 0, 0, 0);				//Desenha o Background
			al_draw_bitmap(Hero_sprite[8], 518 - 23, pos_y0, 0);	//Desenha "Divine Knight Magic"
			al_draw_bitmap(boss, 57, 171, 0);						//Desenha o Boss

			al_draw_tinted_bitmap(Hero_sprite[11], al_map_rgba_f(1, 1, 1, alpha), blizpart01_x, blizpart01_y, 0);

			al_draw_tinted_bitmap(Hero_sprite[12], al_map_rgba_f(1, 1, 1, alpha), blizpart02_x, blizpart02_y, 0);

			al_draw_tinted_bitmap(Hero_sprite[13], al_map_rgba_f(1, 1, 1, alpha), blizpart03_x, blizpart03_y, 0);
			al_flip_display();
	
			blizpart01_y -= 0.497;	
			blizpart02_x += 0.35;
			blizpart02_y -= 0.497;
			blizpart03_x += 0.35;
		    blizpart03_y -= 0.497;
			alpha -= 0.05;
		}
	}//Fim do laço que faz cair gelo 3 vezes

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	for(int x = 518; x < pos_x0 + 1; x++) {		//ANIMAÇÃO VOLTANDO DO ATAQUE		
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[9], x, pos_y0, 0);	//Desenha Divine Knight "Back Magic"
		al_flip_display();
		al_rest(0.005);
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);			//Desenha "DivineKnight Stop"
	al_flip_display();

}//Fim de magic


void DivineKnight::summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font) {

	for(int x = pos_x0; x > 517; x--) {		//ANIMAÇÃO INDO ATACAR			
		if(x > 460) {
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);		//Go Attack 01
			al_flip_display();
			al_rest(0.005);
		}

		else if(x <= 460) {	
			al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[7], x, pos_y0, 0);	//"Go Magic 01"
			al_flip_display();
			al_rest(0.005);
		}
	}//Fim de indo atacar	

al_play_sample_instance(sampleinstance[4]);

	al_draw_bitmap(Hero_sprite[23], 0, 0, 0);				//Desenha "Shiva Background" 
	al_draw_bitmap(boss, 57, 171, 0);						//Desenha o Boss
	al_draw_bitmap(Hero_sprite[8], 518, pos_y0, 0);			 //Desenha "Divine Knight Magic"
	al_flip_display();
	al_rest(3.0);

	float shiivapos_x = 588;
	for(float shiivapos_y = -217; shiivapos_y < 73; shiivapos_y ++) {
		al_draw_bitmap(Hero_sprite[23], 0, 0, 0);						//Desenha "Shiva Background" 
		al_draw_bitmap(boss, 57, 171, 0);								//Desenha o Boss
		al_draw_bitmap(Hero_sprite[8], 518, pos_y0, 0);					//Desenha "Divine Knight Magic"
		al_draw_bitmap(Hero_sprite[24], shiivapos_x, shiivapos_y, 0);	//Desenha Shiiva
		al_flip_display();
		al_rest(0.005);
		shiivapos_x--;
	} 

	shiivapos_x = 289;
	float shiivapos_y = 72;

	float neve_y = -2026;
	float alpha = 0;
	for(float neve_x = 0; neve_x > -1100; neve_x -= 0.4) {
			al_draw_tinted_bitmap(Hero_sprite[21], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);	
			al_draw_bitmap(Hero_sprite[26], shiivapos_x, shiivapos_y, 0);			//Desenha Shiiva
			al_draw_bitmap(boss, 57, 171, 0);										//Desenha o Boss
			al_draw_bitmap(Hero_sprite[25], neve_x, neve_y, 0);						//Desenha flocos de neve

			al_draw_bitmap(menu, 0, 0, 0);
			al_draw_bitmap(portrait, 13, 493, 0);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 365, 520, ALLEGRO_ALIGN_LEFT, "%s", N1);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 365, 562, ALLEGRO_ALIGN_LEFT, "%s", N2);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 365, 604, ALLEGRO_ALIGN_LEFT, "%s", N3);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 365, 646, ALLEGRO_ALIGN_LEFT, "%s", N4);

			al_draw_textf(font, al_map_rgb(0, 0, 0), 559, 520, ALLEGRO_ALIGN_LEFT, "%d/999", HP1);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 559, 562, ALLEGRO_ALIGN_LEFT, "%d/999", HP2);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 559, 604, ALLEGRO_ALIGN_LEFT, "%d/999", HP3);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 559, 646, ALLEGRO_ALIGN_LEFT, "%d/999", HP4);

			al_draw_textf(font, al_map_rgb(0, 0, 0), 717, 520, ALLEGRO_ALIGN_LEFT, "%d/99", MP1);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 717, 562, ALLEGRO_ALIGN_LEFT, "%d/99", MP2);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 717, 604, ALLEGRO_ALIGN_LEFT, "%d/99", MP3);
			al_draw_textf(font, al_map_rgb(0, 0, 0), 717, 646, ALLEGRO_ALIGN_LEFT, "%d/99", MP4);

			al_draw_bitmap(Hero_sprite[8], 518, pos_y0, 0);							//Desenha "Divine Knight Magic"
			al_flip_display();

		neve_y += 0.4;
		alpha += 1.5;
		if(shiivapos_x < 811)
			shiivapos_x += 0.3;

		if(shiivapos_y > -290)
			shiivapos_y -= 0.3;

		if(alpha >= 255)
			alpha = 0;
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	for(int x = 518; x < pos_x0 + 1; x++) {		//ANIMAÇÃO VOLTANDO DO ATAQUE		
		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

		al_draw_bitmap(Hero_sprite[9], x, pos_y0, 0);	//Desenha Divine Knight "Back Magic"
		al_flip_display();
		al_rest(0.005);

		al_draw_bitmap(Hero_sprite[22], 0, 0, 0);	//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);			//Desenha "DivineKnight Stop"
	al_flip_display();
}//Fim de Summon

void DivineKnight::recover(ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
						   ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
						   ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
						   ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
						   ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font,
						   short hp0, short hp1, short hp2, short hp3) {

	al_draw_bitmap(Hero_sprite[19], 0, 0, 0);			//Atualiza a tela 01
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(Hero_sprite[8], pos_x0 - 23, pos_y0, 0);	//Desenha "DivineKnight Magic"
	al_flip_display();
	al_rest(0.8);

	al_draw_bitmap(Hero_sprite[19], 0, 0, 0);			//Atualiza a tela 01
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(Hero_sprite[15], pos_x0, pos_y0, 0);		//Desenha "DivineKnight Victory"
	al_flip_display();
	al_rest(0.5);

	for(int i = 31; i < 33; i++) {
		al_draw_bitmap(Hero_sprite[36], 0, 0, 0);
		al_draw_bitmap(Hero_sprite[i], 0, 0, 0);
		al_flip_display();
		al_rest(0.4);
	}

al_play_sample_instance(sampleinstance[3]);
	for(float alpha = 0; alpha < 256; alpha += 2.5) {
		al_draw_bitmap(Hero_sprite[36], 0, 0, 0);
		al_draw_tinted_bitmap(Hero_sprite[32], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);
		al_flip_display();
		al_rest(0.01);
	}

	float dx = 374;
	float dy = 102;
	float dwh = 176;
	
	for(dwh = 176; dwh < 354.1; dwh += 0.3) {
		al_draw_bitmap(Hero_sprite[36], 0, 0, 0);
		al_draw_tinted_scaled_bitmap(Hero_sprite[33], al_map_rgba_f(1, 1, 1, 0.3), 0, 0, 176, 176, 
																				  dx, dy, dwh, dwh, 0);
		al_flip_display();
		dx -= 0.15;
		dy -= 0.15;
	}
al_play_sample_instance(sampleinstance[5]);

	al_draw_bitmap(Hero_sprite[36], 0, 0, 0);
	al_flip_display();

	for(int i = 0; i < 3; i++) {
		for(int i = 34; i < 36; i++) {
			al_draw_bitmap(Hero_sprite[19], 0, 0, 0);			//Atualiza tela 01
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);	//Desenha "DivineKnight Stop"

			al_draw_bitmap(Hero_sprite[i], 0, 0, 0);
			al_flip_display();
			al_rest(0.4);
		}
	}

	float posy0 = 180;
	float posy1 = 229;
	float posy2 = 278;
	float posy3 = 327;

	for(posy0 = 180; posy0 > 160; posy0 -= 0.45) {
		al_draw_bitmap(update, 0, 0, 0);
		al_draw_bitmap(H0, pos_x0, pos_y0, 0);
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		if(hp0 > 0)
		al_draw_textf(font, al_map_rgb(90, 230, 50), 668, posy0, ALLEGRO_ALIGN_CENTER, "%d", 999 - hp0);
		
		if(hp1 > 0)
		al_draw_textf(font, al_map_rgb(90, 230, 50), 703, posy1, ALLEGRO_ALIGN_CENTER, "%d", 999 - hp1);
		
		if(hp2 > 0)
		al_draw_textf(font, al_map_rgb(90, 230, 50), 738, posy2, ALLEGRO_ALIGN_CENTER, "%d", 999 - hp2);
		
		if(hp3 > 0)
		al_draw_textf(font, al_map_rgb(90, 230, 50), 773, posy3, ALLEGRO_ALIGN_CENTER, "%d", 999 - hp3);

		al_flip_display();
		al_rest(0.025);

		posy1 -= 0.45;
		posy2 -= 0.45;
		posy3 -= 0.45;
	}

	al_draw_bitmap(update, 0, 0, 0);
	al_draw_bitmap(H0, pos_x0, pos_y0, 0);
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_flip_display();

}//Fim de Recover

void DivineKnight::receiveDamage(short pos_x0, short pos_y0, 
								 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
								 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
								 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for(int i = 27; i < 30; i++) {
		al_draw_bitmap(Hero_sprite[19], 0, 0, 0);			//Atualiza tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);			//Desenha frames da animação
		al_flip_display();
		al_rest(0.3);
	}
}

void DivineKnight::death(short pos_x0, short pos_y0,
	 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for(int i = 17; i < 19; i++) {
		al_draw_bitmap(Hero_sprite[19], 0, 0, 0);	//Atualiza a tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);
		al_flip_display();
		al_rest(1.0);
	}
}

ALLEGRO_BITMAP *DivineKnight::getStop() {
	return Hero_sprite[0];
}

ALLEGRO_BITMAP *DivineKnight::getStopInverse() {
	return Hero_sprite[47];
}

ALLEGRO_BITMAP *DivineKnight::getVictory() {
	return Hero_sprite[15];
}

ALLEGRO_BITMAP *DivineKnight::getVictoryInverse() {
	return Hero_sprite[16];
}

ALLEGRO_BITMAP *DivineKnight::getPortrait() {
	return Hero_sprite[30];
}

ALLEGRO_BITMAP *DivineKnight::getDefend() {
	return Hero_sprite[14];
}

ALLEGRO_BITMAP *DivineKnight::getDeath01() {
	return Hero_sprite[17];
}

ALLEGRO_BITMAP *DivineKnight::getDeath() {
	return Hero_sprite[18];
}

ALLEGRO_BITMAP *DivineKnight::getMagics01() {
	return Hero_sprite[37];
}

ALLEGRO_BITMAP *DivineKnight::text01() {
	return Hero_sprite[38];
}

ALLEGRO_BITMAP *DivineKnight::text02() {
	return Hero_sprite[39];
}
ALLEGRO_BITMAP *DivineKnight::text03() {
	return Hero_sprite[40];
}
ALLEGRO_BITMAP *DivineKnight::text04() {
	return Hero_sprite[41];
}

void DivineKnight::destroy() {
	for (int i = 0; i < 48; i++) {
		al_destroy_bitmap(Hero_sprite[i]);
	}

	for (int i = 0; i < 6; i++) {
		al_destroy_sample(sample[i]);
	}

	for (int i = 0; i < 6; i++) {
		al_destroy_sample_instance(sampleinstance[i]);
	}
}