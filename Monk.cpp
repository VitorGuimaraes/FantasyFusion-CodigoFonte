#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>			
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include "Monk.h"

void Monk::loadSprites() {
	Hero_sprite[0] = al_load_bitmap("Characters/Monk/MStop.png");
	Hero_sprite[1] = al_load_bitmap("Characters/Monk/MGoAttack.png");
	Hero_sprite[2] = al_load_bitmap("Characters/Monk/MAttack01.png");	
	Hero_sprite[3] = al_load_bitmap("Characters/Monk/MAttack02.png");
	Hero_sprite[4] = al_load_bitmap("Characters/Monk/MBackAttack01.png");
	Hero_sprite[5] = al_load_bitmap("Characters/Monk/MBackAttack02.png");
	Hero_sprite[6] = al_load_bitmap("Characters/Monk/MReceiveDamage01.png");
	Hero_sprite[7] = al_load_bitmap("Characters/Monk/MReceiveDamage02.png");
	Hero_sprite[8] = al_load_bitmap("Characters/Monk/MReceiveDamage03.png");
	Hero_sprite[9] = al_load_bitmap("Characters/Monk/MMagic.png");
	Hero_sprite[10] = al_load_bitmap("Characters/Monk/RepeatingFist01.png");
	Hero_sprite[11] = al_load_bitmap("Characters/Monk/RepeatingFist02.png");
	Hero_sprite[12] = al_load_bitmap("Characters/Monk/RepeatingFist03.png");
	Hero_sprite[13] = al_load_bitmap("Characters/Monk/RepeatingFist04.png");
	Hero_sprite[14] = al_load_bitmap("Characters/Monk/RepeatingFist05.png");
	Hero_sprite[15] = al_load_bitmap("Characters/Monk/RepeatingFist06.png");
	Hero_sprite[16] = al_load_bitmap("Characters/Monk/RepeatingFist07.png");
	Hero_sprite[17] = al_load_bitmap("Characters/Monk/RepeatingFist08.png");
	Hero_sprite[18] = al_load_bitmap("Characters/Monk/MDefense.png");
	Hero_sprite[19] = al_load_bitmap("Characters/Monk/MConjuring.png");
	Hero_sprite[20] = al_load_bitmap("Characters/Monk/MVictoryInverse.png");
	Hero_sprite[21] = al_load_bitmap("Characters/Monk/MDeath01.png");
	Hero_sprite[22] = al_load_bitmap("Characters/Monk/MDeath02.png");
	Hero_sprite[23] = al_load_bitmap("Characters/Monk/MUpdateScreen01.png");
	Hero_sprite[24] = al_load_bitmap("Characters/Monk/MUpdateScreen02.png");
	Hero_sprite[25] = al_load_bitmap("Characters/Monk/MUpdateScreen03.png");
	Hero_sprite[26] = al_load_bitmap("Characters/Monk/MUpdateScreen04.png");
	Hero_sprite[27] = al_load_bitmap("Characters/Monk/BackGround_Titan.png");
	Hero_sprite[28] = al_load_bitmap("Characters/Monk/BackGround_RepeatingFist.png");
	Hero_sprite[29] = al_load_bitmap("Characters/Monk/Titan.png");
	Hero_sprite[30] = al_load_bitmap("Characters/Monk/Titan01.png");
	Hero_sprite[31] = al_load_bitmap("Characters/Monk/Titan02.png");
	Hero_sprite[32] = al_load_bitmap("Characters/Monk/Titan03.png");
	Hero_sprite[33] = al_load_bitmap("Characters/Monk/Titan04.png");
	Hero_sprite[34] = al_load_bitmap("Characters/Monk/Titan05.png");
	Hero_sprite[35] = al_load_bitmap("Characters/Monk/Titan06.png");
	Hero_sprite[36] = al_load_bitmap("Characters/Monk/Titan07.png");
	Hero_sprite[37] = al_load_bitmap("Characters/Monk/MUpdateScreen05.png");
	Hero_sprite[38] = al_load_bitmap("Characters/Monk/MPortrait.png");
	Hero_sprite[39] = al_load_bitmap("Characters/Monk/DialogRepeatedFist.png");
	Hero_sprite[40] = al_load_bitmap("Characters/Monk/DialogTitan.png");
	Hero_sprite[41] = al_load_bitmap("Characters/Monk/MVictory.png");
}

void Monk::loadSamples() {
	sample[0] = al_load_sample("Sounds/Attack/Attack.ogg");
	sample[1] = al_load_sample("Sounds/Magick/RepeatingFist.ogg");
	sample[2] = al_load_sample("Sounds/Summon/Titan.ogg");

	for(short attach = 0; attach < 3; attach++) {		
		sampleinstance[attach] = al_create_sample_instance(sample[attach]);
		al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
	}
}

void Monk::basicAttack(short pos_x0, short pos_y0, 
					   ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
					   ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
					   ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
					   ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 290; x -= 27) {		//ANIMAÇÃO INDO ATACAR
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[0], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de indo atacar

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[2], 290, pos_y0, 0); //Desenha "Attack01"
	al_flip_display();
	al_rest(0.1);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[3], 290, pos_y0, 0);	//Desenha "Attack 02"
	al_flip_display();
	al_rest(0.2);

al_play_sample_instance(sampleinstance[0]);

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 301, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 301, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	for(int x = 290; x < pos_x0 + 1; x += 27) {	//ANIMAÇÃO VOLTANDO DO ATAQUE
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[4], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);				
	al_flip_display();
}//Fim de basicAttack

void Monk::magic(short pos_x0, short pos_y0, 
				 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
				 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
				 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
				 ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage) {

	for(int x = pos_x0; x > 517; x -= 27) {		//ANIMAÇÃO INDO ATACAR
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[0], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de indo atacar

al_play_sample_instance(sampleinstance[1]);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[2], 519, pos_y0, 0);
	al_flip_display();
	al_rest(0.1);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[3], 518, pos_y0, 0);
	al_flip_display();
	al_rest(0.2);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);
	al_flip_display();
	al_rest(0.1);

	for(int i = 10; i < 18; i++) {
		al_draw_bitmap(Hero_sprite[28], 0, 0, 0);
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);
		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_draw_bitmap(Hero_sprite[i], 0, 0, 0);
		al_flip_display();
		al_rest(0.2);
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano


	for(int x = 518; x < pos_x0 + 1; x += 27) {	//ANIMAÇÃO VOLTANDO DO ATAQUE
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[4], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);				
	al_flip_display();

}//Fim de RepeatedFist

void Monk::summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font) {

for(int x = pos_x0; x > 517; x -= 27) {		//ANIMAÇÃO INDO ATACAR
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[0], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[1], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de indo atacar

al_play_sample_instance(sampleinstance[2]);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[9], 518, pos_y0, 0);				//Desenha Monk Magic
	al_flip_display();
	al_rest(2.0);

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[19], 518, pos_y0, 0);	//Desenha Monk "Victory"
	al_flip_display();
	al_rest(0.3);


	al_draw_bitmap(Hero_sprite[27], 0, 0, 0);			//Desenha o Background de Titan
	al_draw_bitmap(Hero_sprite[19], 518, pos_y0, 0);	//Desenha Monk "Victory"
	al_draw_bitmap(boss, 57, 171, 0);					//Desenha o Boss

	float alpha = 0;
	for(float titanpos_y = 480; titanpos_y > 5; titanpos_y -= 0.6) {	//Desenha Titan subindo na tela
		al_draw_tinted_bitmap(Hero_sprite[36], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);	
		al_draw_bitmap(Hero_sprite[29], 0, titanpos_y, 0);			//Desenha Titan

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

		al_draw_bitmap(Hero_sprite[19], 518, pos_y0, 0);			//Desenha Monk "Victory"
		al_draw_bitmap(boss, 57, 171, 0);							//Desenha o Boss

		al_flip_display();
		alpha += 3;
	}
	
	for(float titanpos_y = 5; titanpos_y < 480; titanpos_y += 1.3) {	//Desenha Titan descendo na tela
		al_draw_tinted_bitmap(Hero_sprite[36], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);	
		al_draw_bitmap(Hero_sprite[29], 0, titanpos_y, 0);			//Desenha Titan
		
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

		al_draw_bitmap(Hero_sprite[19], 518, pos_y0, 0);			//Desenha Monk "Victory"
		al_draw_bitmap(boss, 57, 171, 0);							//Desenha o Boss
		
		al_flip_display();
		alpha += 2;
	}

	float rocha01_y = 480;
	float rocha02_y = 480;
	float rocha03_y = 480;
	float rocha04_y = 480;
	float rocha05_y = 480;
	float rocha06_y = 480;

	for(int i = 0; i < 2000; i++) {		//Laço das rochas subindo
		al_draw_bitmap(boss, 57, 171, 0);							//Desenha o Boss

		al_draw_bitmap(Hero_sprite[30], 0, rocha01_y, 0);
		al_draw_bitmap(Hero_sprite[31], 0, rocha02_y, 0);
		al_draw_bitmap(Hero_sprite[32], 0, rocha03_y, 0);
		al_draw_bitmap(Hero_sprite[33], 0, rocha04_y, 0);
		al_draw_bitmap(Hero_sprite[34], 0, rocha05_y, 0);
		al_draw_bitmap(Hero_sprite[35], 0, rocha06_y, 0);

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

		al_draw_tinted_bitmap(Hero_sprite[36], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);						
		al_flip_display();

		if(rocha01_y > 18) 
			rocha01_y -= 1.2;
				else if(rocha01_y <= 19)
					rocha01_y += 5.0;

		if(rocha02_y > -1)
			rocha02_y -= 1.5;
				else if(rocha02_y <= 0)
					rocha02_y += 4.5;		

		if(rocha03_y > 1)
			rocha03_y -= 1.7;
				else if(rocha03_y <= 2)
					rocha03_y += 5.6;

		if(rocha04_y > 190)
			rocha04_y -= 0.9;
				else if(rocha04_y <= 191)
					rocha04_y += 4.7;

		if(rocha05_y > 257)
			rocha05_y -= 1.2;
				else if(rocha05_y <= 258)
					rocha05_y += 6.0;

		if(rocha06_y > 205)
			rocha06_y --;
				else if(rocha06_y <= 206)
					rocha06_y += 5.8;

		alpha += 2.0;
	}//Fim do laço das rochas subindo

	rocha01_y = 19;
	rocha02_y = 0;
	rocha03_y = 2;
	rocha04_y = 191;
	rocha05_y = 258;
	rocha06_y = 206;

	for(int i = 0; i < 900; i++) {			//Laço das rochas descendo
		al_draw_bitmap(boss, 57, 171, 0);							//Desenha o Boss
		al_draw_bitmap(Hero_sprite[30], 0, rocha01_y, 0);	
		al_draw_bitmap(Hero_sprite[31], 0, rocha02_y, 0);
		al_draw_bitmap(Hero_sprite[32], 0, rocha03_y, 0);
		al_draw_bitmap(Hero_sprite[33], 0, rocha04_y, 0);
		al_draw_bitmap(Hero_sprite[34], 0, rocha05_y, 0);
		al_draw_bitmap(Hero_sprite[35], 0, rocha06_y, 0);

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

		al_draw_tinted_bitmap(Hero_sprite[36], al_map_rgba_f(1, 1, 1, alpha/255.0), 0, 0, 0);	
		al_flip_display();
 
		rocha01_y++;
		rocha02_y += 1.2;		
		rocha03_y += 1.5;
		rocha04_y += 0.9;
		rocha05_y += 1.3;
		rocha06_y += 1.5;
		alpha += 5;
	}

	for(int i = 0; i < 2; i++) {	//ANIMAÇÃO DO BOSS LEVANDO DANO
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(bossDamage, 57, 171, 0);			//Desenha o Boss levando dano
		al_flip_display();
		al_rest(0.2);
		
		al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);
		al_draw_bitmap(Hero_sprite[0], 518, pos_y0, 0);

		al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss
		al_flip_display();
		al_rest(0.2);
	}//Fim da animação do Boss levando dano

	for(int x = 518; x < pos_x0 + 1; x += 27) {	//ANIMAÇÃO VOLTANDO DO ATAQUE
		if(x % 2 == 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[4], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}

		if(x % 2 != 0) {
			al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

			al_draw_bitmap(Hero_sprite[5], x, pos_y0, 0);
			al_flip_display();
			al_rest(0.12);
		}
	}//Fim da animação de voltando do ataque

	al_draw_bitmap(Hero_sprite[26], 0, 0, 0);		//Atualiza Tela 04
	al_draw_bitmap(H1, pos_x1, pos_y1, 0);
	al_draw_bitmap(H2, pos_x2, pos_y2, 0);
	al_draw_bitmap(H3, pos_x3, pos_y3, 0);
	al_draw_bitmap(boss, 57, 171, 0);				//Desenha o Boss

	al_draw_bitmap(Hero_sprite[0], pos_x0, pos_y0, 0);				//Desenha "Monk Stop"
	al_flip_display();
}//Fim de Titan

void Monk::receiveDamage(short pos_x0, short pos_y0, 
						 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
						 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {
	for(int i = 6; i < 9; i++) {
		al_draw_bitmap(Hero_sprite[23], 0, 0, 0);			//Atualiza tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);			//Desenha frames da animação
		al_flip_display();
		al_rest(0.3);
	}
}

void Monk::death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {

	for (int i = 21; i < 23; i++) {
		al_draw_bitmap(Hero_sprite[23], 0, 0, 0);	//Atualiza a tela 01
		al_draw_bitmap(H1, pos_x1, pos_y1, 0);
		al_draw_bitmap(H2, pos_x2, pos_y2, 0);
		al_draw_bitmap(H3, pos_x3, pos_y3, 0);

		al_draw_bitmap(Hero_sprite[i], pos_x0, pos_y0, 0);
		al_flip_display();
		al_rest(1.0);
	}
}

ALLEGRO_BITMAP *Monk::getStop() {
	return Hero_sprite[0];
}

ALLEGRO_BITMAP *Monk::getStopInverse() {
	return Hero_sprite[5];
}

ALLEGRO_BITMAP *Monk::getVictory() {
	return Hero_sprite[41];
}

ALLEGRO_BITMAP *Monk::getVictoryInverse() {
	return Hero_sprite[20];
}

ALLEGRO_BITMAP *Monk::getPortrait() {
	return Hero_sprite[38];
}

ALLEGRO_BITMAP *Monk::getDefend() {
	return Hero_sprite[18];
}

ALLEGRO_BITMAP *Monk::getDeath01() {
	return Hero_sprite[21];
}

ALLEGRO_BITMAP *Monk::getDeath() {
	return Hero_sprite[22];
}

ALLEGRO_BITMAP *Monk::text01() {
	return Hero_sprite[39];
}

ALLEGRO_BITMAP *Monk::text02() {
	return Hero_sprite[40];
}

void Monk::destroy() {
	for (int i = 0; i < 42; i++) {
		al_destroy_bitmap(Hero_sprite[i]);
	}

	for (int i = 0; i < 3; i++) {
		al_destroy_sample(sample[i]);
	}

	for (int i = 0; i < 3; i++) {
		al_destroy_sample_instance(sampleinstance[i]);
	}
}