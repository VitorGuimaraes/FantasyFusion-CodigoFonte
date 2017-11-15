#include "Boss.h"

Boss::Boss() {					//Método Construtor Padrão
	HP = 6999;

	Boss_sprite[0] = al_load_bitmap("Characters/Boss/BossStop.png");
	Boss_sprite[1] = al_load_bitmap("Characters/Boss/BossAttack01.png");
	Boss_sprite[2] = al_load_bitmap("Characters/Boss/BossAttack02.png");
	Boss_sprite[3] = al_load_bitmap("Characters/Boss/BossAttack03.png");
	Boss_sprite[4] = al_load_bitmap("Characters/Boss/BossAttack04.png");
	Boss_sprite[5] = al_load_bitmap("Characters/Boss/BossAttack05.png");
	Boss_sprite[6] = al_load_bitmap("Characters/Boss/BossAttack06.png");
	Boss_sprite[7] = al_load_bitmap("Characters/Boss/BossAttack07.png");
	Boss_sprite[8] = al_load_bitmap("Characters/Boss/BossAttack08.png");
	Boss_sprite[9] = al_load_bitmap("Characters/Boss/BossAttack09.png");
	Boss_sprite[10] = al_load_bitmap("Characters/Boss/BossAttack10.png");
	Boss_sprite[11] = al_load_bitmap("Characters/Boss/BossAttack11.png");
	Boss_sprite[12] = al_load_bitmap("Characters/Boss/Fireball01.png");
	Boss_sprite[13] = al_load_bitmap("Characters/Boss/Fireball02.png");
	Boss_sprite[14] = al_load_bitmap("Characters/Boss/ReceiveDamage.png");
	Boss_sprite[15] = al_load_bitmap("Characters/Boss/BUpdateScreen01.png");
	Boss_sprite[16] = al_load_bitmap("Characters/Boss/BUpdateScreen02.png");
	Boss_sprite[17] = al_load_bitmap("Characters/Boss/BUpdateScreen03.png");
	Boss_sprite[18] = al_load_bitmap("Characters/Boss/Fire01.png");
	Boss_sprite[19] = al_load_bitmap("Characters/Boss/Fire02.png");
	Boss_sprite[20] = al_load_bitmap("Characters/Boss/Fire03.png");
	Boss_sprite[21] = al_load_bitmap("Characters/Boss/Fire04.png");
	Boss_sprite[22] = al_load_bitmap("Characters/Boss/Fire05.png");
	Boss_sprite[23] = al_load_bitmap("Characters/Boss/Fire06.png");
	Boss_sprite[24] = al_load_bitmap("Characters/Boss/Fire07.png");
	Boss_sprite[25] = al_load_bitmap("Characters/Boss/Fire08.png");
	Boss_sprite[26] = al_load_bitmap("Characters/Boss/Fire09.png");
	Boss_sprite[27] = al_load_bitmap("Characters/Boss/Fire10.png");
}

void Boss::loadSamples() {
	sample[0] = al_load_sample("Sounds/Sample/FireBallSound.ogg");
	sample[1] = al_load_sample("Sounds/Sample/DarkFireballSound.ogg");
	sample[2] = al_load_sample("Sounds/Sample/DraculaDeath.ogg");

	for(int attach = 0; attach < 3; attach++) {		
	sampleinstance[attach] = al_create_sample_instance(sample[attach]);
	al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
	}
}

short Boss::damage() {
	return 200 + (int)(799 * rand() / (RAND_MAX + 1.0));
}

short Boss::target(short hp0, short hp1, short hp2, short hp3) {
	bool success = false;
	short target = 0;

//Verifica se o alvo está vivo
	while(!success) {
		target = 1 + (int)(4 * rand() / (RAND_MAX + 1.0));

		if(target == 1 && hp0 > 0) 
			success = true;

		if(target == 2 && hp1 > 0) 
			success = true;
	
		if(target == 3 && hp2 > 0)
			success = true;

		if(target == 4 && hp3 > 0)
			success = true;
	}//Fim do while de !success
	return target;
}

short Boss::attack(short hp0, short hp1, short hp2, short hp3, short damage) {

	short T = target(hp0, hp1, hp2, hp3);
	int BF  = 0;			//Bola de fogo (Normal ou Escura)
	short sound = 0;

	if(damage < 700) {
		BF = 12;			//Bola de Fogo Normal
		sound = 0;
	}

	else if(damage >= 700) {
		BF = 13;			//Bola de Fogo Escura
		sound = 1;
	}

al_play_sample_instance(sampleinstance[sound]); 
	for(int i = 1; i < 12; i++) {
		al_draw_bitmap(Boss_sprite[15], 0, 0, 0);		//UpdateScreen
		al_draw_bitmap(Boss_sprite[i], 57, 171, 0);
		al_flip_display();
		al_rest(0.06);
	}
		al_draw_bitmap(Boss_sprite[0], 57, 171, 0);		//Boss Parado
		al_flip_display();

	float pos_y = 226.0;
	if(T == 1) {
		for(float x = 211.0; x < 588.1; x += 1.984) {
			al_draw_bitmap(Boss_sprite[15], 0, 0, 0);			//Update Screen
			al_draw_bitmap(Boss_sprite[0], 57, 171, 0);			//Boss parado
			al_draw_bitmap(Boss_sprite[BF], x, pos_y, 0);		//Bola de fogo	
			al_flip_display();
			al_rest(0.003);
			pos_y -= 0.1; 		
		}
	}//Fim de if(T == 1)

	else if(T == 2) {
		for(float x = 211.0; x < 623.1; x += 1.177) {				
				al_draw_bitmap(Boss_sprite[15], 0, 0, 0);		//Update Screen
				al_draw_bitmap(Boss_sprite[0], 57, 171, 0);		//Boss parado
				al_draw_bitmap(Boss_sprite[BF], x, pos_y, 0);	//Bola de fogo	
				al_flip_display();
				al_rest(0.002);
				pos_y += 0.1; 		
		}
	}//Fim de if(T == 2)

	else if(T== 3) {
		for(float x = 211.0; x < 658.1; x += 2.625) {				
			al_draw_bitmap(Boss_sprite[15], 0, 0, 0);			//Update Screen
			al_draw_bitmap(Boss_sprite[0], 57, 171, 0);			//Boss parado
			al_draw_bitmap(Boss_sprite[BF], x, pos_y, 0);		//Bola de fogo	
			al_flip_display();
			al_rest(0.004);
			pos_y += 0.5; 			
		}
	}//Fim de if(T == 3)

	else if(T == 4) {
		for(float x = 211.0; x < 693.1; x += 1.81) {				
			al_draw_bitmap(Boss_sprite[15], 0, 0, 0);			//Update Screen
			al_draw_bitmap(Boss_sprite[0], 57, 171, 0);			//Boss parado
			al_draw_bitmap(Boss_sprite[BF], x, pos_y, 0);		//Bola de fogo	
			al_flip_display();
			al_rest(0.003);
			pos_y += 0.5; 			
		} 
	}//Fim de if(T == 4)
	return T;

}//Fim do ataque do Boss

void Boss::death() {
al_play_sample_instance(sampleinstance[2]);

	for(int cont = 0; cont < 7; cont++) {
		for(int i = 18; i < 28; i++) {
			al_draw_bitmap(Boss_sprite[17], 0, 0, 0);		//Atualiza a tela
			al_draw_bitmap(Boss_sprite[0], 57, 171, 0);		//Desenha o Boss
			al_draw_bitmap(Boss_sprite[i], 0, 0, 0);		//Desenha as explosões

			al_flip_display();
			al_rest(0.15);
		}
	}
}

void Boss::setHP(short hp) {
	HP = hp;
}

short Boss::getHP() {
	return HP;
}

short Boss::receiveDamage(short damage) {
	HP -= damage;

	if(HP < 0) {
		setHP(0);
	}
	else 
		setHP(HP);
	return damage;
}


ALLEGRO_BITMAP *Boss::getBossStop() {
	return Boss_sprite[0];
}

ALLEGRO_BITMAP *Boss::getBossReceiveDamage() {
	return Boss_sprite[14];
}

void Boss::destroy() {
	for (int i = 0; i < 28; i++) {
		al_destroy_bitmap(Boss_sprite[i]);
	}

	for (int i = 0; i < 3; i++) {
		al_destroy_sample(sample[i]);
	}

	for (int i = 0; i < 3; i++) {
		al_destroy_sample_instance(sampleinstance[i]);
	}
}