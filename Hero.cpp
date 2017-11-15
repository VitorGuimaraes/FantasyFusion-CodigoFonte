#include "Hero.h"

Hero::Hero() { 
	HP = 999;
	MP = 99;
	pos_x = 0;
	pos_y = 0;
	Defend = false;
}

void Hero::setHP(short hp) {
	HP = hp;
}

short Hero::getHP() {
	return HP;
}

void Hero::setMP(short mp) {
	MP = mp;
}

short Hero::getMP() {
	return MP;
}

void Hero::setName(char n[12]) {
	strcpy(Name, n);
}

char *Hero::getName() {
	return Name;
}

short Hero::getpos_x() {
	return pos_x;
}

void Hero::setpos_y(short pos_Y) {
	pos_y = pos_Y;
}

short Hero::getpos_y() {
	return pos_y;
}

void Hero::setDefend(bool d) {
	Defend = d;
}

short Hero::getclass() {
	return classe;
}

void Hero::putHero(short C, short pos_X, short pos_Y) {
	classe = C;
	pos_x = pos_X;
	pos_y = pos_Y;

	switch(classe) {
		case 550:
			soldier.loadSprites();
			soldier.loadSamples();
			break;

		case 581:
			divineknight.loadSprites();
			divineknight.loadSamples();
			break;

		case 612:
			viera.loadSprites();
			viera.loadSamples();
			setpos_y(pos_y - 16);
			break;
	
		case 643:
			monk.loadSprites();
			monk.loadSamples();
			break;
	}
}

ALLEGRO_BITMAP *Hero::drawPerson() {
	switch(classe) {
		case 550:
			if(HP > 300) {
				if(Defend)
					return soldier.getDefend();

				else if(!Defend)
					return soldier.getStop();
			}
			else if(HP > 0 && HP <= 300) 
				return soldier.getDeath01();
			
			else if(HP == 0)
				return soldier.getDeath();

		case 581:
			if(HP > 300) {
				if(Defend)
					return	divineknight.getDefend();

				else if(!Defend)
					return	divineknight.getStop();
			}

			else if(HP > 0 && HP <= 300)
				return divineknight.getDeath01();

			else if(HP == 0)
				return	divineknight.getDeath();

		case 612:
			if(HP > 300) {
				if(Defend)
					return	viera.getDefend();

				else if(!Defend)
					return	viera.getStop();
			}

			else if(HP > 0 && HP <= 300)
				return viera.getDeath01();

			else if(HP == 0)
				return	viera.getDeath();

		case 643:
			if(HP > 300) {
				if(Defend)
					return	monk.getDefend();

				else if(!Defend)
					return	monk.getStop();
			}

			else if(HP > 0 && HP <= 300)
				return monk.getDeath01();

			else if(HP == 0)
				return	monk.getDeath();
	}//Fim do switch de classe
}//Fim do método drawPerson

ALLEGRO_BITMAP *Hero::getStop() {
	switch (classe) {
	case 550:
		return soldier.getStop();
		break;

	case 581:
		return divineknight.getStop();
		break;

	case 612:
		return viera.getStop();
		break;

	case 643:
		return monk.getStop();
		break;
	}
}

ALLEGRO_BITMAP *Hero::getStopInverse() {
	switch (classe) {
	case 550:
		return soldier.getStopInverse();
		break;

	case 581:
		return divineknight.getStopInverse();
		break;

	case 612:
		return viera.getStopInverse();
		break;

	case 643:
		return monk.getStopInverse();
		break;
	}
}

ALLEGRO_BITMAP *Hero::getVictory() {
	switch (classe) {
	case 550:
		return soldier.getVictory();
		break;

	case 581:
		return divineknight.getVictory();
		break;

	case 612:
		return viera.getVictory();
		break;

	case 643:
		return monk.getVictory();
		break;
	}
}

ALLEGRO_BITMAP *Hero::getVictoryInverse() {
	switch (classe) {
	case 550:
		return soldier.getVictoryInverse();
		break;

	case 581:
		return divineknight.getVictoryInverse();
		break;

	case 612:
		return viera.getVictoryInverse();
		break;

	case 643:
		return monk.getVictoryInverse();
		break;
	}
}

ALLEGRO_BITMAP *Hero::drawPortrait() {
	switch(classe) {
		case 550:
			return soldier.getPortrait();
		break;

		case 581:
			return divineknight.getPortrait();
		break;

		case 612:
			return viera.getPortrait();
		break;

		case 643:
			return monk.getPortrait();
		break;
	}
}

void Hero::drawReceiveDamage(short pos_x0, short pos_y0, 
							 ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
							 ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
							 ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {
	switch(classe) {
		case 550:
			soldier.receiveDamage(pos_x0, pos_y0, 
						      H1, pos_x1, pos_y1, 
							  H2, pos_x2, pos_y2,
							  H3, pos_x3, pos_y3);
		break;

		case 581:
			divineknight.receiveDamage(pos_x0, pos_y0, 
								   H1, pos_x1, pos_y1, 
								   H2, pos_x2, pos_y2,
								   H3, pos_x3, pos_y3);
		break;

		case 612:
			viera.receiveDamage(pos_x0, pos_y0, 
							H1, pos_x1, pos_y1, 
						    H2, pos_x2, pos_y2,
							H3, pos_x3, pos_y3);
		break;

		case 643:
			monk.receiveDamage(pos_x0, pos_y0, 
						   H1, pos_x1, pos_y1, 
						   H2, pos_x2, pos_y2,
						   H3, pos_x3, pos_y3);
		break;
	}
}

void Hero::death(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3) {
	
	switch(classe) {
	case 550:
		soldier.death(pos_x0, pos_y0,
			H1, pos_x1, pos_y1,
			H2, pos_x2, pos_y2,
			H3, pos_x3, pos_y3);
		break;

	case 581:
		divineknight.death(pos_x0, pos_y0,
			H1, pos_x1, pos_y1,
			H2, pos_x2, pos_y2,
			H3, pos_x3, pos_y3);
		break;

	case 612:
		viera.death(pos_x0, pos_y0,
			H1, pos_x1, pos_y1,
			H2, pos_x2, pos_y2,
			H3, pos_x3, pos_y3);
		break;

	case 643:
		monk.death(pos_x0, pos_y0,
			H1, pos_x1, pos_y1,
			H2, pos_x2, pos_y2,
			H3, pos_x3, pos_y3);
		break;
	}
}

ALLEGRO_BITMAP *Hero::drawMagicsMenu01() {
	return divineknight.getMagics01();
}

short Hero::basicAttack(short pos_x0, short pos_y0, 
						ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
						ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
						ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
						ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, ALLEGRO_FONT *font2) {
	int critical;
	short damage;
	switch(classe) {
		case 550:
			damage = 225 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			soldier.basicAttack(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			for(float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 581:
			damage = 150 + (int)(100 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 220) {
				al_draw_bitmap(divineknight.text01(), 0, 0, 0);
				al_flip_display();
			}

			divineknight.basicAttack(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			for(float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 612:
			critical = 1 + (int)(99 * rand() / (RAND_MAX + 1.0));
			
			if(critical > 0 && critical < 41) //40% de chances do ataque ser crítico
				damage = 300 + (int)(200 * rand() / (RAND_MAX + 1.0));  //Cálculo do dano crítico
			else if(critical > 40 && critical < 101)
				damage = 150 + (int)(100 * rand() / (RAND_MAX + 1.0));	  //Cálculo do dano normal

			if(damage <= 250)
				al_play_sample_instance(viera.shot());
			else if(damage >= 300)
				al_play_sample_instance(viera.criticalshot());
	
			viera.basicAttack(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);

				for(float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
					al_draw_bitmap(update, 0, 0, 0);
					al_draw_bitmap(boss, 57, 171, 0);

					if(damage <= 250)
					al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);

					else if(damage >= 300)
					al_draw_textf(font2, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);

					al_flip_display();
					al_rest(0.0075);
				}
			
			return damage;
		break;

		case 643:
			monk.basicAttack(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			damage = 210 + (int)(140 * rand() / (RAND_MAX + 1.0));//Cálculo do dano
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;
	}
}

short Hero::magic(short pos_x0, short pos_y0, 
				  ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1, 
				  ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2, 
				  ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3, 
				  ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font) {

	short damage;
	switch(classe) {
		case 550:
			damage = 300 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 400) {
				al_draw_bitmap(soldier.text01(), 0, 0, 0);
				al_flip_display();
			}

			soldier.magic(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			setMP(MP - 8);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 581:
			damage = 450 + (int)(175 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if (damage > 570) {
				al_draw_bitmap(divineknight.text02(), 0, 0, 0);
				al_flip_display();
			}

			divineknight.magic(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			setMP(MP - 8);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 612:
			damage = 300 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if (damage > 400) {
				al_draw_bitmap(viera.text01(), 0, 0, 0);
				al_flip_display();
			}

			viera.magic(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			setMP(MP - 4);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 643:
			damage = 300 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if (damage > 400) {
				al_draw_bitmap(monk.text01(), 0, 0, 0);
				al_flip_display();
			}

			monk.magic(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage);
			setMP(MP - 8);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;
	}
}

short Hero::summon(short pos_x0, short pos_y0,
	ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
	ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
	ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
	ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *bossDamage, ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *portrait,
	char *N1, char *N2, char *N3, char *N4,
	short HP1, short HP2, short HP3, short HP4,
	short MP1, short MP2, short MP3, short MP4, ALLEGRO_FONT *font, ALLEGRO_BITMAP *update) {

	short damage;
	switch(classe) {
		case 550:
			damage = 500 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 600) {
				al_draw_bitmap(soldier.text02(), 0, 0, 0);
				al_flip_display();
			}

			soldier.summon(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage, menu, portrait, 
				N1, N2, N3, N4, HP1, HP2, HP3, HP4, MP1, MP2, MP3, MP4, font);
			setMP(MP - 12);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 581:
			damage = 750 + (int)(225 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 900) {
				al_draw_bitmap(divineknight.text04(), 0, 0, 0);
				al_flip_display();
			}

			divineknight.summon(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage, menu, portrait,
				N1, N2, N3, N4, HP1, HP2, HP3, HP4, MP1, MP2, MP3, MP4, font);
			setMP(MP - 12);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 612:
			damage = 500 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 600) {
				al_draw_bitmap(viera.text02(), 0, 0, 0);
				al_flip_display();
			}

			viera.summon(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage, menu, portrait,
				N1, N2, N3, N4, HP1, HP2, HP3, HP4, MP1, MP2, MP3, MP4, font);
			setMP(MP - 8);
			for (float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;

		case 643:
			damage = 500 + (int)(150 * rand() / (RAND_MAX + 1.0));	//Cálculo do dano
			if(damage > 600) {
				al_draw_bitmap(monk.text02(), 0, 0, 0);
				al_flip_display();
			}

			monk.summon(pos_x0, pos_y0, H1, pos_x1, pos_y1, H2, pos_x2, pos_y2, H3, pos_x3, pos_y3, boss, bossDamage, menu, portrait,
				N1, N2, N3, N4, HP1, HP2, HP3, HP4, MP1, MP2, MP3, MP4, font);
			setMP(MP - 12);
			for(float pos_y = 200; pos_y > 151; pos_y -= 0.5) {
				al_draw_bitmap(update, 0, 0, 0);
				al_draw_bitmap(boss, 57, 171, 0);
				al_draw_textf(font, al_map_rgb(255, 0, 0), 200, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -damage);
				al_flip_display();
				al_rest(0.0075);
			}
			return damage;
		break;
	}
}

void Hero::recover(ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
				   ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
				   ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
				   ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
				   ALLEGRO_BITMAP *boss, ALLEGRO_BITMAP *update, ALLEGRO_FONT *font,
				   short hp0, short hp1, short hp2, short hp3) {
			
			al_draw_bitmap(divineknight.text03(), 0, 0, 0);
			al_flip_display();

			divineknight.recover(H0, pos_x0, pos_y0,
								 H1, pos_x1, pos_y1,
							     H2, pos_x2, pos_y2,
								 H3, pos_x3, pos_y3,
							     boss, update, font,
								 hp0, hp1, hp2, hp3);
			setMP(MP - 10);
}

void Hero::receiveDamage(short damage, ALLEGRO_BITMAP *H0, short pos_x0, short pos_y0,
									   ALLEGRO_BITMAP *H1, short pos_x1, short pos_y1,
									   ALLEGRO_BITMAP *H2, short pos_x2, short pos_y2,
									   ALLEGRO_BITMAP *H3, short pos_x3, short pos_y3,
									   ALLEGRO_BITMAP *update, ALLEGRO_FONT *font, short target) {
short Dano = 0;

	if(!Defend) {		//Não está no modo de defesa
		if(classe == 550 || classe == 581 || classe == 612) {
			if((HP - damage) > 0) {
				setHP(HP - damage);
			}

			else if(HP - damage <= 0) {
				setHP(0);
			}
			Dano = damage;
		}

		else if(classe == 643) {
			if((HP - (damage * 0.7)) > 0) {
				setHP(HP - (damage * 0.7));
			}

			else if((HP - (damage * 0.7)) <= 0) {
				setHP(0);
			}
			Dano = damage * 0.7;
		}
	}//Fim do if de não está no modo de defesa

	else if(Defend) {	//Está no modo de defesa
		if(classe == 550 || classe == 581 || classe == 612) {
			if((HP - (damage * 0.8)) > 0) {
				setHP(HP - (damage * 0.8));
			}

			else if((HP - (damage * 0.8)) < 0) {
				setHP(0);
			}
			Dano = (damage * 0.8) + 1;
		}

		else if(classe == 643) {
			if((HP - (damage * 0.5)) > 0) {
				setHP(HP - (damage * 0.5));
			}

			else if((HP - (damage * 0.5)) <= 0) {
				setHP(0);
			}
			Dano = (damage * 0.5);
		}
	}//Fim do if de está no modo de defesa

	switch(target) {
	case 1:
		for(float pos_y = 180; pos_y > 160; pos_y -= 0.5) {
			al_draw_bitmap(update, 0, 0, 0);
			al_draw_bitmap(H0, pos_x0, pos_y0, 0);
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), pos_x0, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -Dano);
			al_flip_display();
			al_rest(0.015);
		}
		break;

	case 2:
		for(float pos_y = 229; pos_y > 209; pos_y -= 0.5) {
			al_draw_bitmap(update, 0, 0, 0);
			al_draw_bitmap(H0, pos_x0, pos_y0, 0);
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), pos_x1, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -Dano);
			al_flip_display();
			al_rest(0.015);
		}
		break;

	case 3:
		for(float pos_y = 278; pos_y > 258; pos_y -= 0.5) {
			al_draw_bitmap(update, 0, 0, 0);
			al_draw_bitmap(H0, pos_x0, pos_y0, 0);
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), pos_x2, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -Dano);
			al_flip_display();
			al_rest(0.015);
		}
		break;

	case 4:
		for(float pos_y = 327; pos_y > 307; pos_y -= 0.5) {
			al_draw_bitmap(update, 0, 0, 0);
			al_draw_bitmap(H0, pos_x0, pos_y0, 0);
			al_draw_bitmap(H1, pos_x1, pos_y1, 0);
			al_draw_bitmap(H2, pos_x2, pos_y2, 0);
			al_draw_bitmap(H3, pos_x3, pos_y3, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), pos_x3, pos_y, ALLEGRO_ALIGN_LEFT, "%d", -Dano);
			al_flip_display();
			al_rest(0.015);
		}
		break;
	}//Fim do switch de Target
}

void Hero::destroy() {
	switch (classe) {
	case 550:
		soldier.destroy();
		break;

	case 581:
		divineknight.destroy();
		break;

	case 612:
		viera.destroy();
		break;

	case 643:
		monk.destroy();
		break;
	}
}