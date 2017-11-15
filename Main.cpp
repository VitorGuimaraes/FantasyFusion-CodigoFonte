//Includes do Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>			
#include <allegro5/allegro_acodec.h>

//Includes do C e C++
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Includes das classes
#include "Hero.h"
#include "Boss.h"
#include "Soldier.h"
#include "DivineKnight.h"
#include "Viera.h"
#include "Monk.h"

ALLEGRO_TIMER *timer = NULL;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *general_event = NULL;
ALLEGRO_FONT *font1 = NULL;
ALLEGRO_FONT *font2 = NULL;
ALLEGRO_FONT *font3 = NULL;
ALLEGRO_FONT *font4 = NULL;

ALLEGRO_BITMAP *Misc[31];
ALLEGRO_BITMAP *Load[19];

ALLEGRO_SAMPLE *sample[3];
ALLEGRO_SAMPLE_INSTANCE *sampleinstance[3];

ALLEGRO_SAMPLE *audio[7];
ALLEGRO_SAMPLE_INSTANCE *audioinstance[7];;

char str[9];							//String que recebe o nome dos personagens

bool inicializar() {
	int FPS = 30;

	if(!al_init()) {							//Inicia o Allegro					        
		return 0;
	}
	display = al_create_display(810, 682);		//Cria a janela
//==================
//Instala os addons
//==================
	al_init_font_addon();	//Instala addon de fontes
	al_init_ttf_addon();	//Instala addon de fontes .ttf	
	al_init_image_addon();	//Instala addon de imagens
	al_init_acodec_addon(); //Instala os codecs de áudio

	al_install_audio();		//Instala o áudio
	al_install_keyboard();	//Instala o teclado
	al_reserve_samples(40);	//Quantidade de canais que devem ser alocados ao mixer principal


	Load[0] = al_load_bitmap("Misc/LoadingFundo.png");
	Load[1] = al_load_bitmap("Misc/Line.png");
	Load[2] = al_load_bitmap("Misc/S.png");
	Load[3] = al_load_bitmap("Misc/SQ.png");
	Load[4] = al_load_bitmap("Misc/SQU.png");
	Load[5] = al_load_bitmap("Misc/SQUA.png");
	Load[6] = al_load_bitmap("Misc/SQUAR.png");
	Load[7] = al_load_bitmap("Misc/SQUARE.png");
	Load[8] = al_load_bitmap("Misc/SQUARE E.png");
	Load[9] = al_load_bitmap("Misc/SQUARE EN.png");
	Load[10] = al_load_bitmap("Misc/SQUARE ENI.png");
	Load[11] = al_load_bitmap("Misc/SQUARE ENIX.png");
	Load[12] = al_load_bitmap("Misc/Loading01.png");
	Load[13] = al_load_bitmap("Misc/Loading02.png");
	Load[14] = al_load_bitmap("Misc/Loading03.png");
	Load[15] = al_load_bitmap("Misc/Loading04.png");
	Load[16] = al_load_bitmap("Misc/Loading05.png");
	Load[17] = al_load_bitmap("Misc/Loading06.png");
	Load[18] = al_load_bitmap("Misc/Loading07.png");

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(0.5);

	for(float fadeloop = 0; fadeloop < 256; fadeloop += 0.5) {
		al_draw_tinted_bitmap(Load[0], al_map_rgba_f(1, 1, 1, fadeloop / 255.0), 0, 0, 0);	//Desenha "LoadingFundo"	
		al_flip_display();
	}
	for(int i = 2; i < 12; i++) {
		al_draw_bitmap(Load[0], 0, 0, 0);			//Desenha "LoadingFundo"
		al_draw_bitmap(Load[1], 0, 0, 0);			//Desenha "Line"
		al_draw_bitmap(Load[i], 0, 0, 0);

		al_flip_display();
		al_rest(0.12);

		if(i == 11)
			al_rest(1.0);
	}//Fim de for(int i = 2; i < 12; i ++)
	for (float fadeloop = 256; fadeloop > 0; fadeloop -= 0.3) {
		al_draw_tinted_bitmap(Load[0], al_map_rgba_f(1, 1, 1, fadeloop / 255.0), 0, 0, 0);	//Desenha "LoadingFundo"	
		al_flip_display();
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(2.0);

	srand(time(NULL));
	short load = rand() % 7 + 12;

	al_draw_bitmap(Load[load], 0, 0, 0);
	al_flip_display();
//===================
//Carrega os samples
//===================
	sample[0] = al_load_sample("Sounds/Sample/CursorMove.ogg");
	sample[1] = al_load_sample("Sounds/Sample/CursorConfirm.ogg");
	sample[2] = al_load_sample("Sounds/Sample/ThunderEffect.ogg");
//=================================================================
//Cria sample instance para os samples e anexa com o mixer padrão
//=================================================================
for(int attach = 0; attach < 3; attach++) {		
	sampleinstance[attach] = al_create_sample_instance(sample[attach]);
	al_attach_sample_instance_to_mixer(sampleinstance[attach], al_get_default_mixer());
}	
//===================
//Carrega as músicas
//===================
	audio[0] = al_load_sample("Sounds/Duration/Intro.ogg");
	audio[1] = al_load_sample("Sounds/Duration/SelectNamesClasses.ogg");
	audio[2] = al_load_sample("Sounds/Duration/HistoryTheme.ogg");
	audio[3] = al_load_sample("Sounds/Duration/Dialog.ogg");
	audio[4] = al_load_sample("Sounds/Duration/BattleTheme.ogg");
	audio[5] = al_load_sample("Sounds/Duration/GameOver.ogg");
	audio[6] = al_load_sample("Sounds/Duration/Victory.ogg");
//================================================================
//Cria sample instance para os músicas e anexa com o mixer padrão
//================================================================
for(int attach = 0; attach < 7; attach++) {		
	audioinstance[attach] = al_create_sample_instance(audio[attach]);
	al_attach_sample_instance_to_mixer(audioinstance[attach], al_get_default_mixer());
}	
//==================
//Carrega os Miscs
//==================
	Misc[0] = al_load_bitmap("Misc/BackGroundTitleScreen.png");
	Misc[1] = al_load_bitmap("Misc/FantasyFusionTitleScreen.png");
	Misc[2] = al_load_bitmap("Misc/PlayerName.png");
	Misc[3] = al_load_bitmap("Misc/BahamutImperium.png");
	Misc[4] = al_load_bitmap("Misc/History.png"); 
	Misc[5] = al_load_bitmap("Misc/FantasyFusionPresents.png");
	Misc[6] = al_load_bitmap("Misc/ActionMenu.png");
	Misc[7] = al_load_bitmap("Misc/Cursor.png");
	Misc[8] = al_load_bitmap("Misc/Dialog01.png");
	Misc[9] = al_load_bitmap("Misc/Dialog02.png");
	Misc[10] = al_load_bitmap("Misc/Dialog03.png");
	Misc[11] = al_load_bitmap("Misc/Dialog04.png");
	Misc[12] = al_load_bitmap("Misc/Dialog05.png");
	Misc[13] = al_load_bitmap("Misc/Dialog06.png");
	Misc[14] = al_load_bitmap("Misc/Dialog07.png");
	Misc[15] = al_load_bitmap("Misc/Dialog08.png");
	Misc[16] = al_load_bitmap("Misc/Dialog09.png");
	Misc[17] = al_load_bitmap("Misc/Dialog10.png");
	Misc[18] = al_load_bitmap("Misc/Dialog11.png");
	Misc[19] = al_load_bitmap("Misc/BackGround_Normal.png");
	Misc[20] = al_load_bitmap("Misc/HeroName.png");
	Misc[21] = al_load_bitmap("Misc/HeroClass.png");
	Misc[22] = al_load_bitmap("Misc/WarriorFromDarkness.png");
	Misc[23] = al_load_bitmap("Misc/SoldierClass.png");
	Misc[24] = al_load_bitmap("Misc/DivineKnightClass.png");
	Misc[25] = al_load_bitmap("Misc/VieraClass.png");
	Misc[26] = al_load_bitmap("Misc/MonkClass.png");
	Misc[27] = al_load_bitmap("Misc/GameOver.png");
	Misc[28] = al_load_bitmap("Misc/FantasyFusion.png");
	Misc[29] = al_load_bitmap("Misc/Update.png");
	Misc[30] = al_load_bitmap("Misc/Update2.png");

	font1 = al_load_font("nyala.ttf", 36, 0);		//Fonte para receber nome do jogador 
	font2 = al_load_font("nyala.ttf", 26, 0);		//Fonte para desenhar o HP e MP dos personagens	
	font3 = al_load_font("nyala.ttf", 29, 0);		//Fonte para desenhar nome dos heróis
//=======================
//Timer init and StartUp
//=======================
	general_event = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);							//FPS = 30 frames por segundo

	al_register_event_source(general_event, al_get_keyboard_event_source());
	al_register_event_source(general_event, al_get_display_event_source(display));
	al_register_event_source(general_event, al_get_timer_event_source(timer));
	al_start_timer(timer);
	return true;
}

void receber_nome(ALLEGRO_EVENT ev){				//Função que recebe o nome do jogador e dos heróis
	if(ev.type == ALLEGRO_EVENT_KEY_CHAR) {		
		if(strlen(str) < 9) {
			char temp[] = {ev.keyboard.unichar, '\0'};	
			if(ev.keyboard.unichar == ' ')	{														
				strcat(str, temp);
			}
			else if(ev.keyboard.unichar >= '0' &&
				ev.keyboard.unichar <= '9') {
				strcat(str, temp);
			}
			else if(ev.keyboard.unichar >= 'A' &&
				ev.keyboard.unichar <= 'Z') {
				strcat(str, temp);
			}
			else if(ev.keyboard.unichar >= 'a' &&
				ev.keyboard.unichar <= 'z') {
				strcat(str, temp);
			}
		}

		if(ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0) {
			str[strlen(str) - 1] = '\0';
		}
	}
}

int main() {
	if(!inicializar()) {
		return -1;
	}

	Hero h[4];
	Boss B;
	B.loadSamples();
	
	ALLEGRO_EVENT ev;
	
	int titlecursor_x = 282;				//Variável que controla a posição do cursor na tela de start	
	int titlecursor_y = 472;				//Variável que controla a posição do cursor na tela de start
	
	int classcursor_y = 550;				//Variável que controla a posição do cursor nas telas de escolha de personagens
	int trovaoaleatorio = 0;
	
	int cont = 0;							//Variável que controla a quantidade de personagens do jogador (4)
	int actioncursor_y = 0;					//Variável que controla a posição do cursor na tela "Action Menu"

	float titleBackground = 0;				//Variável contadora que controla a velocidade que "Title Screen" se desloca na tela
	float history = 682;					//Variável contadora que controla a velocidade que "History" se desloca na tela

	bool end = false;						//Bool do laço principal do jogo
	bool StartScreen = true;				//Bool da tela de start
	bool PlayerNameScreen = false;			//Bool da tela que o jogador coloca seu nome
	bool enterName = false;					//Bool que verifica se o jogador terminou de digitar o nome
	bool PersonScreen = false;				//Bool da tela que o jogador escolhe os personagens
	bool History = false;					//Bool da tela da História
	bool Dialog = false;					//Bool da tela de Diálogo
	bool Battle = false;					//Bool da tela de Batalha
	bool desalocar = false;					//Função que desaloca a memória e encerra o jogo
	
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(1.0);
//===================================================================================================================================================================================================================================================================================================================================================
	while(!end) {			//Laço principal do jogo	
//===================================================================================================================================================================================================================================================================================================================================================
		while(StartScreen) {												//Inicio do laço da tela de start
			al_set_sample_instance_playing(audioinstance[0], 1);					//Toca a música da tela de start		
			for(float fadeloop = 0; fadeloop < 256; fadeloop += 0.9) {				//Efeito na tela
				if(titleBackground < 1) {												//Faz com que a imagem de fundo se desloque									
					titleBackground -= 0.2;												//Controla a velocidade que a imagem de fundo da tela se desloca
					al_draw_tinted_bitmap(Misc[0], al_map_rgba_f(1, 1, 1, fadeloop/255.0), titleBackground, 0, 0); //Faz a imagem de fundo da tela mudar de cor gradualmente
					al_draw_bitmap(Misc[1], 0, 0, 0);									//Desenha "Fantasy Fusion Title Screen"
					al_draw_bitmap(Misc[7], titlecursor_x, titlecursor_y, 0);			//Desenha o Cursor
					al_flip_display();													//Atualiza a tela
						if(titleBackground < -2672)										//Reseta a posição inicial de titleBackground
							titleBackground = 0;											//Reseta a posição inicial de titleBackground
				}//Fim do if que faz com que a imagem de fundo se desloque
					al_wait_for_event(general_event, &ev);
					if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
						switch (ev.keyboard.keycode) {
						case ALLEGRO_KEY_DOWN:
							al_play_sample_instance(sampleinstance[0]);
							titlecursor_y += 56;
							titlecursor_x += 50;

							if((titlecursor_y > 528) && (titlecursor_x > 332)) {
								titlecursor_y = 472;
								titlecursor_x = 282;
							}
							break;
						case ALLEGRO_KEY_UP:
							al_play_sample_instance(sampleinstance[0]);
							titlecursor_y -= 56;
							titlecursor_x -= 50;

							if((titlecursor_y < 472) && (titlecursor_x < 282)) {
								titlecursor_y = 528;
								titlecursor_x = 332;
							}
							break;
						case ALLEGRO_KEY_ENTER:
							if((titlecursor_x == 332) && (titlecursor_y == 528)) {	//Fecha o jogo
								titleBackground = 1;
								StartScreen = false;
								desalocar = true;
								break;
							}

							else if((titlecursor_x == 282) && (titlecursor_y == 472)) {		//Continua o jogo se der enter em NOVO JOGO
								al_play_sample_instance(sampleinstance[1]);											//Som de confirmação				
								for(int fadeloop = 150; fadeloop < 255; fadeloop += 4) {								//Efeito na tela
									al_clear_to_color(al_map_rgb(fadeloop, fadeloop, fadeloop));						//Efeito com o logo do jogo
									al_draw_tinted_bitmap(Misc[28], al_map_rgba_f(1, 1, 1, fadeloop / 255.0), 0, 0, 0);	//Continuação do efeito com o logo do jogo
									al_flip_display();																	//Atualiza a tela
									al_rest(0.1);																		//Espera 0.1 segundos e repete o laço
								}//Fim do efeito na tela
								al_rest(2.5);																		//Espera 2.5 segundos para continuar

								for(int fadeloop = 255; fadeloop > 0; fadeloop -= 16) {								//Fade Out na tela
									al_clear_to_color(al_map_rgb(fadeloop, fadeloop, fadeloop));					//Faz com que a tela escureça
									al_flip_display();																//Atualiza a tela
									al_rest(0.1);																	//Espera 0.1 segundos e repete o laço
								}//Fim do Fade Out
								al_set_sample_instance_playing(audioinstance[0], 0);								//Para a música da Tela de Inicio																	

								for(int fadeloop = 0; fadeloop < 255; fadeloop += 15) {								//Desenha "WarriorFromDark" com Fade in
									al_draw_tinted_bitmap(Misc[22], al_map_rgb(fadeloop, fadeloop, fadeloop), 0, 0, 0);	//Faz com que a tela escureça
									al_flip_display();																//Atualiza a tela
									al_rest(0.1);																	//Espera 0.1 segundos e repete o laço
								}//Fim do Fade Out
								al_rest(2.5);																		//Espera 2.5 segundos para continuar	
								for(int fadeloop = 0; fadeloop < 255; fadeloop += 20) {								//Fade Out na tela
									al_clear_to_color(al_map_rgb(fadeloop, fadeloop, fadeloop));					//Faz com que a tela escureça
									al_flip_display();																//Atualiza a tela
									al_rest(0.1);																	//Espera 0.1 segundos e repete o laço
								}//Fim do Fade Out
								al_set_sample_instance_playing(audioinstance[0], 0);							//Para a música da Tela de Inicio
								PlayerNameScreen = true;											//Valida a entrada no laço de PlayerNameScreen											
								titleBackground = 1;
								StartScreen = false;												//Invalida a entrada no laço de StartScreen 
								break;
							}//Fim do if do enter que começa o jogo
						case ALLEGRO_KEY_ESCAPE:
							titleBackground = 1;
							StartScreen = false;
							desalocar = true;
							break;
						}//Fim do switch
					}//Fim de ev.type == ALLEGRO_EVENT_KEY_DOWN
					else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {		//Fechar o jogo no X da janela
						titleBackground = 1;
						StartScreen = false;
						desalocar = true;
						break;
					}
				}//Fim do efeito na tela	
//====================================================================================================================================================			
			while(PlayerNameScreen) {													//Tela que o jogador coloca seu nome		
				while(!al_is_event_queue_empty(general_event)) {
					al_set_sample_instance_playing(audioinstance[1], 1);				//Toca a música de escolha de personagens		
					al_draw_bitmap(Misc[2], 0, 0, 0);									//Desenha "Player Name"	
				
					al_wait_for_event(general_event, &ev);
					if(!enterName) {
						receber_nome(ev);
						al_draw_text(font1, al_map_rgb(0, 0, 0), 405, 300, ALLEGRO_ALIGN_CENTER, str);
						al_flip_display();	
						if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER && (strlen(str) > 0)) {		//Aguarda o pressionamento da tecla ENTER
							al_play_sample_instance(sampleinstance[1]);					//Som de confirmação
							str[0] = '\0';
							enterName = true;
						}
					}
					if ((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) || (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
						titleBackground = 1;
						StartScreen = false;
						enterName = false;
						PlayerNameScreen = false;
						desalocar = true;
						break;
					}
					
					if(enterName) {
						enterName = false;
						PlayerNameScreen = false;
						PersonScreen = true;
						break;
					}
				}//Fim de !al_is_event_queue_empty(general_event)
//====================================================================================================================================================
				while(PersonScreen) {		
					bool Select = false;		//Bool da escolha da classe dos personagens

					if(classcursor_y == 550) 
						al_draw_bitmap(Misc[23], 0, 0, 0);								//Desenha a tela de "SoldierClass"

					else if(classcursor_y == 581) 
						al_draw_bitmap(Misc[24], 0, 0, 0);								//Desenha a tela de "DivineKnightClass"	
					
					else if(classcursor_y == 612) 
						al_draw_bitmap(Misc[25], 0, 0, 0);								//Desenha a tela de "VieraClass"

					else if(classcursor_y == 643) 
						al_draw_bitmap(Misc[26], 0, 0, 0);								//Desenha a tela de "MonkClass"	 
					
					al_draw_bitmap(Misc[21], 0, 0, 0);							//Desenha "HeroClass"
					al_draw_bitmap(Misc[7], 23, classcursor_y, 0);				//Desenha o Cursor
					al_flip_display();

						al_wait_for_event(general_event, &ev);
						if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {	
							switch(ev.keyboard.keycode) {
								case ALLEGRO_KEY_DOWN:
									al_play_sample_instance(sampleinstance[0]);	
									classcursor_y += 31;									
									if(classcursor_y > 644)
									classcursor_y = 550;
									break;
								case ALLEGRO_KEY_UP:
									al_play_sample_instance(sampleinstance[0]);
									classcursor_y -= 31;
									if(classcursor_y < 550)
									classcursor_y = 643;
									break;
								case ALLEGRO_KEY_ESCAPE:
									titleBackground = 1;
									StartScreen = false;
									enterName = false;
									PlayerNameScreen = false;
									PersonScreen = false;
									desalocar = true;
									break;
								case ALLEGRO_KEY_ENTER:
									while(!Select) {
										while(!al_is_event_queue_empty(general_event)) {
											al_draw_bitmap(Misc[20], 0, 0, 0);			//Desenha "Hero Name"
											al_flip_display();

											al_wait_for_event(general_event, &ev);
											if(!enterName) {
												receber_nome(ev);
												al_draw_text(font2, al_map_rgb(0, 0, 0), 100, 505, ALLEGRO_ALIGN_LEFT, str);
												al_flip_display();	

												if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER && (strlen(str) > 0)) {		//Aguarda o pressionamento da tecla ENTER
													al_play_sample_instance(sampleinstance[1]);					//Som de confirmação
													enterName = true;
												}
												else if ((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) || (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {	//Fecha o jogo no X ou no ESC
													titleBackground = 1;
													StartScreen = false;
													enterName = false;
													PlayerNameScreen = false;
													Select = true;
													PersonScreen = false;
													desalocar = true;
													break;
												}

											}//Fim de !enterName
										}//Fim de !al_is_event_queue_empty(general_event)
										if(enterName) {
											enterName = false;
											break;
										}
									}//Fim do while de Select
							Select = true;
							}//Fim do switch
						}//Fim de ev.type == ALLEGRO_EVENT_KEY_DOWN
						else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {		//Fechar o jogo no X da janela
							titleBackground = 1;
							StartScreen = false;
							enterName = false;
							PlayerNameScreen = false;
							Select = true;
							PersonScreen = false;
							desalocar = true;
							break;
						}

						if(Select) {
							if(cont < 4) {
								switch(cont) {
									case 0:
										h[cont].putHero(classcursor_y, 643, 180);
										h[cont].setName(str);
										str[0] = '\0';
									break;

									case 1:
										h[cont].putHero(classcursor_y, 678, 229);
										h[cont].setName(str);
										str[0] = '\0';
									break;

									case 2:
										h[cont].putHero(classcursor_y, 713, 278);
										h[cont].setName(str);
										str[0] = '\0';
									break;

									case 3:
										h[cont].putHero(classcursor_y, 748, 327);
										h[cont].setName(str);
										str[0] = '\0';
									break;
								}//Fim do switch
								cont++;
							}//Fim de if(cont < 4)
							if(cont == 4) {
								PersonScreen = false;
								History = true;
							}
						}//Fim do if de (Select)	
//====================================================================================================================================================
					while(History) {
						al_wait_for_event(general_event, &ev);
						if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {	//Aguarda o pressionamento da tecla ENTER
							al_play_sample_instance(sampleinstance[2]);									//Som de trovão		
							for(int fadeloop = 0; fadeloop < 256; fadeloop += 10) {							//Efeito de trovão no fundo após pressionar ENTER
								al_draw_tinted_bitmap(Misc[3], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
								al_flip_display();
								al_rest(0.1);
							}//Fecha o efeito em "BahamutImperium" 	
							al_rest(1.5);

							for(int fadeloop = 0; fadeloop < 240; fadeloop += 20) {						//Efeito com "FantasyFusionPresents"
								al_draw_tinted_bitmap(Misc[5], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
								al_flip_display();
								al_rest(0.1);
							 }//Fecha o efeito com "FantasyFusionPresents"																				
							al_rest(3.0);																//Espera 3 segundos para continuar								
							al_draw_bitmap(Misc[3], 0 ,0, 0);											//Redesenha "BahamutImperium"
							al_flip_display();
							al_rest(2.0);
										
							al_play_sample_instance(sampleinstance[2]);								//Som de trovão										
							for(int fadeloop = 0; fadeloop < 256; fadeloop += 10) {						//Efeito de trovão 
								al_draw_tinted_bitmap(Misc[3], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
								al_flip_display();
								al_rest(0.1);
							}//Fecha o efeito em "BahamutImperium" 

							for(int fadeloop = 255; fadeloop > 0; fadeloop -= 30) {		//Fade Out no fim de "BahamutImperium"
								al_draw_tinted_bitmap(Misc[3], al_map_rgb(fadeloop, fadeloop, fadeloop), 0, 0, 0);
								al_flip_display();
								al_rest(0.1);
							 }//Fecha o Fade Out
							al_rest(3.0);
							History = false;

							if(h[1].getclass() != h[0].getclass()) {		//Verifica se as classes dos personagens são diferentes
								if(h[2].getclass() != h[0].getclass() && h[2].getclass() != h[1].getclass()) {
									if(h[3].getclass() != h[0].getclass() && h[3].getclass() != h[1].getclass() && h[3].getclass() != h[2].getclass())
										Dialog = true;
								}
							}

							Battle = true;
						}//Fim de if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
						else if ((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) || (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {	//Fecha o jogo no X ou no ESC
							titleBackground = 1;
							StartScreen = false;
							enterName = false;
							PlayerNameScreen = false;
							Select = true;
							PersonScreen = false;
							History = false;
							desalocar = true;
							break;
						}
					      //=======================================================Se não apertar ENTER=============================================================
						al_set_sample_instance_playing(audioinstance[1], 0);						//Para a música de escolha de personagens
						al_set_sample_instance_playing(audioinstance[2], 1);						//Toca a música tema da História		
						al_draw_bitmap(Misc[3], 0, 0, 0);								//Desenha "BahamutImperium"			

						al_draw_bitmap(Misc[4], 0, history, 0);							//Desenha "History"					
						
						al_flip_display();												//Atualiza a Tela
							if(history > -2781) {										//Laço que controla a subida de "History"											
								history -= 0.4;					

								srand(time(NULL));														
								trovaoaleatorio = rand() % 60;											//Trovão aleatório em tempos aleatórios											
								
								if(trovaoaleatorio == 1)												//Trovão aleatório em tempos aleatórios
									al_play_sample_instance(sampleinstance[2]);						//Som de trovão
												
								if(history <= -2781) {													//Laço dos eventos que acontecem quando acaba a história
									al_rest(1.0);															//Quando acaba a história espera 1 segundo para continuar
									al_play_sample_instance(sampleinstance[2]);							//Som de trovão	quando acaba a história
									for(int fadeloop = 0; fadeloop < 256; fadeloop += 10) {					//Efeito de trovão quando acaba a história
											al_draw_tinted_bitmap(Misc[3], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
											al_flip_display();
											al_rest(0.1);
									}//Fecha o efeito em "BahamutImperium" 

									for(int fadeloop = 0; fadeloop < 240; fadeloop += 20) {					//Efeito com "FantasyFusionPresents"
										al_draw_tinted_bitmap(Misc[5], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
										al_flip_display();
										al_rest(0.1);
									 }//Fecha o efeito com "FantasyFusionPresents"																				
									al_rest(3.0);															//Espera 3 segundos para continuar								
									al_draw_bitmap(Misc[3], 0 ,0, 0);										//Redesenha "BahamutImperium"
									al_flip_display();
									al_rest(2.0);
										
									al_play_sample_instance(sampleinstance[2]);							//Som de trovão										
										for(int fadeloop = 0; fadeloop < 256; fadeloop += 10) {				//Efeito de trovão 
											al_draw_tinted_bitmap(Misc[3], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);
											al_flip_display();
											al_rest(0.1);
									}//Fecha o efeito em "BahamutImperium" 

									for(int fadeloop = 255; fadeloop > 1; fadeloop -= 30) {					//Fade Out no fim de "BahamutImperium"
										al_draw_tinted_bitmap(Misc[3], al_map_rgb(fadeloop, fadeloop, fadeloop), 0, 0, 0);
										al_flip_display();
										al_rest(0.1);
									 }//Fecha o Fade Out
									al_rest(4.0);
									History = false;

									if(h[1].getclass() != h[0].getclass()) {		//Verifica se as classes dos personagens são diferentes
										if (h[2].getclass() != h[0].getclass() && h[2].getclass() != h[1].getclass()) {
											if (h[3].getclass() != h[0].getclass() && h[3].getclass() != h[1].getclass() && h[3].getclass() != h[2].getclass())
												Dialog = true;
										}
									}

									Battle = true;
								}//Fim do laço dos eventos de quando acaba a história
							}//Fim de if(history > -2781)
//====================================================================================================================================================									
							while(Dialog) {
								al_set_sample_instance_playing(audioinstance[2], 0);								//Para a música tema da História										

								al_clear_to_color(al_map_rgb(0, 0, 0));
								for(int fadeloop = 0; fadeloop < 256; fadeloop += 16) {								
									al_draw_tinted_bitmap(Misc[19], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);		//Desenha o Cenário com Fade In
									al_draw_tinted_bitmap(Misc[8], al_map_rgba_f(1, 1, 1, fadeloop/255.0), 0, 0, 0);		//Desenha "Dialog 01" com Fade In
									
									al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
									al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
									al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
									al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
									al_draw_bitmap(B.getBossStop(), 57, 171, 0);
									
									al_flip_display();
									al_rest(0.1);
								}				

								al_set_sample_instance_playing(audioinstance[3], 1);	//Toca o diálogo dos personagens																														
									al_rest(14.0);											
										al_draw_bitmap(Misc[9], 0, 0, 0);					//Desenha "Dialog 02"
										al_flip_display();
										al_rest(8.0);
											al_draw_bitmap(Misc[10], 0, 0, 0);					//Desenha "Dialog 03"
											al_flip_display();
											al_rest(8.5);
												al_draw_bitmap(Misc[11], 0, 0, 0);					//Desenha "Dialog 04"
												al_flip_display();
												al_rest(2.0);
													al_draw_bitmap(Misc[12], 0, 0, 0);					//Desenha "Dialog 05"
													al_flip_display();
													al_rest(3.0);
														al_draw_bitmap(Misc[13], 0, 0, 0);					//Desenha "Dialog 06"
														al_flip_display();
														al_rest(4.5);
															al_draw_bitmap(Misc[14], 0, 0, 0);					//Desenha "Dialog 07"
															al_flip_display();
															al_rest(11.0);
																al_draw_bitmap(Misc[15], 0, 0, 0);					//Desenha "Dialog 08"
																al_flip_display();
																al_rest(6.0);
																	al_draw_bitmap(Misc[16], 0, 0, 0);					//Desenha "Dialog 09"
																	al_flip_display();
																	al_rest(3.5);
																		al_draw_bitmap(Misc[17], 0, 0, 0);					//Desenha "Dialog 10"
																		al_flip_display();
																		al_rest(7.0);
																			al_draw_bitmap(Misc[18], 0, 0, 0);					//Desenha "Dialog 11"
																			al_flip_display();
																			al_rest(7.5);									
																				Dialog = false; 
																				al_set_sample_instance_playing(audioinstance[3], 0);	//Para de tocar o diálogo dos personagens
																				Dialog = false;
																				Battle = true;  
									}//Fim de Dialog     
//====================================================================================================================================================
							actioncursor_y = 518;
							short vez = 0;							//Variável que controla a vez de cada personagem
							bool ultimo_atacou = false;				
							bool EndGame = false;

							while(Battle) {					//LOOP DA BATALHA
								bool action = true;					//Bool da ação escolhida pelo jogador

								if(h[vez].getHP() > 0) {
									actioncursor_y = 518;
									al_set_sample_instance_playing(audioinstance[2], 0);								//Para a música tema da História
									al_set_sample_instance_playing(audioinstance[4], 1);	//Toca a música da batalha
									al_draw_bitmap(Misc[19], 0, 0, 0);						//Desenha o cenário
									
									al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
									al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
									al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
									al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
									al_draw_bitmap(B.getBossStop(), 57, 171, 0);

									al_draw_bitmap(Misc[6], 0, 0, 0);						//Desenha o menu de ações 
									al_draw_bitmap(h[vez].drawPortrait(), 13, 493, 0);		//Desenha o Portrait do personagem da vez
									al_draw_bitmap(Misc[7], 156, actioncursor_y, 0);		//Desenha o cursor
									
									//Dados dos Heróis
									al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 520, ALLEGRO_ALIGN_LEFT, "%s", h[0].getName());
									al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 562, ALLEGRO_ALIGN_LEFT, "%s", h[1].getName());
									al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 604, ALLEGRO_ALIGN_LEFT, "%s", h[2].getName());
									al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 646, ALLEGRO_ALIGN_LEFT, "%s", h[3].getName());

									al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 520, ALLEGRO_ALIGN_LEFT, "%d/999", h[0].getHP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 562, ALLEGRO_ALIGN_LEFT, "%d/999", h[1].getHP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 604, ALLEGRO_ALIGN_LEFT, "%d/999", h[2].getHP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 646, ALLEGRO_ALIGN_LEFT, "%d/999", h[3].getHP());

									al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 520, ALLEGRO_ALIGN_LEFT, "%d/99", h[0].getMP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 562, ALLEGRO_ALIGN_LEFT, "%d/99", h[1].getMP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 604, ALLEGRO_ALIGN_LEFT, "%d/99", h[2].getMP());
									al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 646, ALLEGRO_ALIGN_LEFT, "%d/99", h[3].getMP());

									al_flip_display();

									while(action && !ultimo_atacou) {
										al_draw_bitmap(Misc[6], 0, 0, 0);
										al_draw_bitmap(h[vez].drawPortrait(), 13, 493, 0);
										al_draw_bitmap(Misc[7], 156, actioncursor_y, 0);

										al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 520, ALLEGRO_ALIGN_LEFT, "%s", h[0].getName());
										al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 562, ALLEGRO_ALIGN_LEFT, "%s", h[1].getName());
										al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 604, ALLEGRO_ALIGN_LEFT, "%s", h[2].getName());
										al_draw_textf(font3, al_map_rgb(0, 0, 0), 365, 646, ALLEGRO_ALIGN_LEFT, "%s", h[3].getName());

										al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 520, ALLEGRO_ALIGN_LEFT, "%d/999", h[0].getHP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 562, ALLEGRO_ALIGN_LEFT, "%d/999", h[1].getHP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 604, ALLEGRO_ALIGN_LEFT, "%d/999", h[2].getHP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 559, 646, ALLEGRO_ALIGN_LEFT, "%d/999", h[3].getHP());

										al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 520, ALLEGRO_ALIGN_LEFT, "%d/99", h[0].getMP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 562, ALLEGRO_ALIGN_LEFT, "%d/99", h[1].getMP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 604, ALLEGRO_ALIGN_LEFT, "%d/99", h[2].getMP());
										al_draw_textf(font2, al_map_rgb(0, 0, 0), 717, 646, ALLEGRO_ALIGN_LEFT, "%d/99", h[3].getMP());

										al_flip_display();

										if(!al_is_event_queue_empty(general_event)) {
										al_wait_for_event(general_event, &ev);
											if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
												switch(ev.keyboard.keycode) {
													case ALLEGRO_KEY_DOWN:
														al_play_sample_instance(sampleinstance[0]);
														actioncursor_y += 39;
														if(actioncursor_y > 635)
															actioncursor_y = 518;
													break;

													case ALLEGRO_KEY_UP:
														al_play_sample_instance(sampleinstance[0]);
														actioncursor_y -= 39;
															if(actioncursor_y < 518)
															actioncursor_y = 635;
													break;

													case ALLEGRO_KEY_ENTER:
														al_play_sample_instance(sampleinstance[1]);		
														action = false;
													break;
												}//Fim do switch de ev.keyboard.keycode
											}//Fim do if de ev.type == ALLEGRO_EVENT_KEY_DOWN
											else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {		//Fecha o jogo no X da janela
												titleBackground = 1;
												StartScreen = false;
												enterName = false;
												PlayerNameScreen = false;
												Select = true;
												PersonScreen = false;
												History = false;
												action = true;
												Battle = false;
												desalocar = true;
												break;
											}
										}//Fim do if de !al_is_event_queue_empty
									}//Fim de action && !ultimo_atacou
								}//h[vez].getHP() > 0
								else 
									vez++;
					
								if(ultimo_atacou) {		//Vez do Boss
									if(B.getHP() > 0 && (h[0].getHP() > 0 || h[1].getHP() > 0 || h[2].getHP() > 0 || h[3].getHP() > 0)) {
										
										short damage = B.damage();

										int T = B.attack(h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP(), damage);

										if(T == 1) {
											h[0].drawReceiveDamage(h[0].getpos_x(), h[0].getpos_y(), 
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());
											
											h[0].receiveDamage(damage, h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
																	   h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 
																	   h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 
																	   h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 
																	   Misc[30], font3, T);

											if(h[0].getHP() == 0)				
											            h[0].death(h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());

											if(h[0].getclass() == 550 && h[0].getHP() > 0)
												B.receiveDamage(h[0].basicAttack(h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
												B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
										}

										else if (T == 2) {
											h[1].drawReceiveDamage(h[1].getpos_x(), h[1].getpos_y(), 
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());
											
											h[1].receiveDamage(damage, h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
												Misc[30], font3, T);

											if(h[1].getHP() == 0)
												        h[1].death(h[1].getpos_x(), h[1].getpos_y(),
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());
											
											if(h[1].getclass() == 550 && h[1].getHP() > 0) 
												B.receiveDamage(h[1].basicAttack(h[1].getpos_x(), h[1].getpos_y(),
													h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
													h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));							
										}										

										else if(T == 3) {
											h[2].drawReceiveDamage(h[2].getpos_x(), h[2].getpos_y(), 
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());
											
											h[2].receiveDamage(damage, h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
												Misc[30], font3, T);

											if(h[2].getHP() == 0)
												       h[2].death(h[2].getpos_x(), h[2].getpos_y(),
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y());
											
											if(h[2].getclass() == 550 && h[2].getHP() > 0)
												B.receiveDamage(h[2].basicAttack(h[2].getpos_x(), h[2].getpos_y(),
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
												B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
										}

										else if(T == 4) {
											h[3].drawReceiveDamage(h[3].getpos_x(), h[3].getpos_y(), 
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y());
											
											h[3].receiveDamage(damage, h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
												Misc[30], font3, T);

											if(h[3].getHP() == 0)
												        h[3].death(h[3].getpos_x(), h[3].getpos_y(),
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y());
									
											if(h[3].getclass() == 550 && h[3].getHP() > 0)
												B.receiveDamage(h[3].basicAttack(h[3].getpos_x(), h[3].getpos_y(),
												h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
												h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
												h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
												B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
										}

										for(int i = 0; i < 4; i++) {
											h[i].setDefend(false);
										}
									}//Fim de if B.getHP() > 0 && (h[0].getHP() > 0 || h[1].getHP() > 0 || h[2].getHP() > 0 || h[3].getHP() > 0
									vez = 0;
									action = true;
									ultimo_atacou = false;
								}//Fim de vez do Boss

								if(B.getHP() <= 0 || ((h[0].getHP() <= 0) && (h[1].getHP() <= 0) && (h[2].getHP() <= 0) && (h[3].getHP() <= 0))) {
									Battle = false;
									EndGame = true;
								}

								if(!action) {
									if(actioncursor_y == 596 && (h[vez].getclass() == 581)) {
										action = true;
										actioncursor_y = 519;

										while(action) {
											al_draw_bitmap(h[vez].drawMagicsMenu01(), 0, 0, 0);
											al_draw_bitmap(Misc[7], 156, actioncursor_y, 0);
											al_flip_display();

											if(!al_is_event_queue_empty(general_event)) {
												al_wait_for_event(general_event, &ev);

												if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
													switch(ev.keyboard.keycode) {
														case ALLEGRO_KEY_DOWN:
															al_play_sample_instance(sampleinstance[0]);
															actioncursor_y += 39;
															if(actioncursor_y > 558)
																actioncursor_y = 519;
														break;

														case ALLEGRO_KEY_UP:
															al_play_sample_instance(sampleinstance[0]);
															actioncursor_y -= 39;
															if(actioncursor_y < 519)
																actioncursor_y = 558;
														break;

														case ALLEGRO_KEY_ENTER:
															al_play_sample_instance(sampleinstance[1]);		
															action = false;
														break;
													}//Fim do switch de ev.keyboard.keycode
												}//Fim do if de ev.type == ALLEGRO_EVENT_KEY_DOWN
												else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)	{	//Fecha o jogo no X da janela
													titleBackground = 1;
													StartScreen = false;
													enterName = false;
													PlayerNameScreen = false;
													Select = true;
													PersonScreen = false;
													History = false;
													action = false;
													Battle = false;
													desalocar = true;
													break;
												}

											}//Fim do if de !al_is_event_queue_empty
										}//Fim do while de action
									}//Fim do if de actioncursor_y == 596 && (h[vez].getclass() == 581
									if(vez == 0) {
										if(h[vez].getHP() > 0) {
											switch (actioncursor_y) {
											case 518:
												B.receiveDamage(h[0].basicAttack(h[0].getpos_x(), h[0].getpos_y(),
													h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
													h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));

											break;

											case 519:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[0].magic(h[0].getpos_x(), h[0].getpos_y(), 
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 557:
												h[vez].setDefend(true);

												al_draw_bitmap(Misc[19], 0, 0, 0);						//Desenha o cenário
												al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
												al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
												al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
												al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
												al_draw_bitmap(B.getBossStop(), 57, 171, 0);
											break;

											case 558:
												if(h[vez].getMP() > 12) {
													h[vez].recover(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
																   h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
																   h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
																   h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
																   B.getBossStop(), Misc[30], font3,
																   h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP());
												
															   for(int i = 0; i < 4; i++) {
														if(h[i].getHP() > 0)
														h[i].setHP(999);
													}
												}
												else 
													vez--;
											break;

											case 596:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[0].magic(h[0].getpos_x(), h[0].getpos_y(), 
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 635:
												if(h[vez].getMP() > 12) {
													B.receiveDamage(h[vez].summon(h[vez].getpos_x(), h[vez].getpos_y(),
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[6], h[0].drawPortrait(),
														h[0].getName(), h[1].getName(), h[2].getName(), h[3].getName(),
														h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP(),
														h[0].getMP(), h[1].getMP(), h[2].getMP(), h[3].getMP(), font3, Misc[29]));
												}
												else 
													vez--;
											break;
										}//Fim do switch actioncursor_y

										if(h[1].getHP() && h[2].getHP() == 0 && h[3].getHP() == 0)
											ultimo_atacou = true;
									}//Fim do if h[vez].getHP > 0
								}//Fim de vez == 0

								else if(vez == 1) {
										if(h[vez].getHP() > 0) {
											switch (actioncursor_y) {
											case 518:
												B.receiveDamage(h[1].basicAttack(h[1].getpos_x(), h[1].getpos_y(),
													h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
													h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
											break;

											case 519:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[1].magic(h[1].getpos_x(), h[1].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 557:
												h[vez].setDefend(true);

												al_draw_bitmap(Misc[19], 0, 0, 0);						//Desenha o cenário
												al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
												al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
												al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
												al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
												al_draw_bitmap(B.getBossStop(), 57, 171, 0);
											break;

											case 558:
												if(h[vez].getMP() > 12) {
													h[vez].recover(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
																   h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
																   h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
																   h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
																   B.getBossStop(), Misc[30], font3,
																   h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP());
													
												for(int i = 0; i < 4; i++) {
														if(h[i].getHP() > 0)
														h[i].setHP(999);
													}
												}
												else 
													vez--;
											break;

											case 596:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[1].magic(h[1].getpos_x(), h[1].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 635:
												if(h[vez].getMP() > 12) {
												B.receiveDamage(h[1].summon(h[1].getpos_x(), h[1].getpos_y(), 
													h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
													h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[6], h[1].drawPortrait(), 
													h[0].getName(), h[1].getName(), h[2].getName(), h[3].getName(),
													h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP(),
													h[0].getMP(), h[1].getMP(), h[2].getMP(), h[3].getMP(), font3, Misc[29]));
												}
												else 
													vez--;
											break;
										}//Fim do switch actioncursor_y
										if(h[2].getHP() == 0 && h[3].getHP() == 0)
											ultimo_atacou = true;
									}//Fim do if h[vez].getHP > 0
								}//Fim de vez == 1

								else if(vez == 2) {
										if(h[vez].getHP() > 0) {
											switch (actioncursor_y) {
											case 518:
												B.receiveDamage(h[2].basicAttack(h[2].getpos_x(), h[2].getpos_y(), 
													h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
													h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
											break;

											case 519:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[2].magic(h[2].getpos_x(), h[2].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 557:
												h[vez].setDefend(true);

												al_draw_bitmap(Misc[19], 0, 0, 0);						//Desenha o cenário
												al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
												al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
												al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
												al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
												al_draw_bitmap(B.getBossStop(), 57, 171, 0);
											break;

											case 558:
												if(h[vez].getMP() > 12) {
													h[vez].recover(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
																   h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
																   h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
																   h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
																   B.getBossStop(), Misc[30], font3,
																   h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP());

												for(int i = 0; i < 4; i++) {
														if(h[i].getHP() > 0)
														h[i].setHP(999);
													}
												}
												else 
													vez--;
											break;

											case 596:
												if(h[vez].getMP() > 8) {
													B.receiveDamage(h[2].magic(h[2].getpos_x(), h[2].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
												}
												else 
													vez--;
											break;

											case 635:
												if(h[vez].getMP() > 12) {
												B.receiveDamage(h[2].summon(h[2].getpos_x(), h[2].getpos_y(), 
													h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
													h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
													h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
													B.getBossStop(), B.getBossReceiveDamage(), Misc[6], h[2].drawPortrait(),
													h[0].getName(), h[1].getName(), h[2].getName(), h[3].getName(),
													h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP(),
													h[0].getMP(), h[1].getMP(), h[2].getMP(), h[3].getMP(), font3, Misc[29]));
												}
												else 
													vez--;
											break;
										}//Fim do switch actioncursor_y
										if(h[3].getHP() == 0)
											ultimo_atacou = true;
									}//Fim do if h[vez].getHP > 0
								}//Fim de vez == 2
									else if(vez == 3) {
											if(h[vez].getHP() > 0) {
												switch (actioncursor_y) {
												case 518:
													B.receiveDamage(h[3].basicAttack(h[3].getpos_x(), h[3].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3, font1));
												break;

												case 519:
													if(h[vez].getMP() > 8) {
														B.receiveDamage(h[3].magic(h[3].getpos_x(), h[3].getpos_y(), 
															h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
															h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
															h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
															B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
													}
													else 
														vez--;
												break;
	
												case 557:
													h[vez].setDefend(true);

													al_draw_bitmap(Misc[19], 0, 0, 0);						//Desenha o cenário
													al_draw_bitmap(h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(), 0);
													al_draw_bitmap(h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(), 0);
													al_draw_bitmap(h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(), 0);
													al_draw_bitmap(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(), 0);
													al_draw_bitmap(B.getBossStop(), 57, 171, 0);
												break;

												case 558:
													if(h[vez].getMP() > 12) {
														h[vez].recover(h[3].drawPerson(), h[3].getpos_x(), h[3].getpos_y(),
																	   h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
																	   h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
																	   h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
																	   B.getBossStop(), Misc[30], font3,
																	   h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP());

														for(int i = 0; i < 4; i++) {
															if(h[i].getHP() > 0)
															h[i].setHP(999);
														}
													}
													else 
														vez--;
												break;

												case 596:
													if(h[vez].getMP() > 8) {
														B.receiveDamage(h[3].magic(h[3].getpos_x(), h[3].getpos_y(), 
															h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
															h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
															h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
															B.getBossStop(), B.getBossReceiveDamage(), Misc[29], font3));
													}
													else 
														vez--;
												break;

												case 635:
													if(h[vez].getMP() > 12) {
													B.receiveDamage(h[vez].summon(h[3].getpos_x(), h[3].getpos_y(), 
														h[0].drawPerson(), h[0].getpos_x(), h[0].getpos_y(),
														h[1].drawPerson(), h[1].getpos_x(), h[1].getpos_y(),
														h[2].drawPerson(), h[2].getpos_x(), h[2].getpos_y(),
														B.getBossStop(), B.getBossReceiveDamage(), Misc[6], h[3].drawPortrait(),
														h[0].getName(), h[1].getName(), h[2].getName(), h[3].getName(),
														h[0].getHP(), h[1].getHP(), h[2].getHP(), h[3].getHP(),
														h[0].getMP(), h[1].getMP(), h[2].getMP(), h[3].getMP(), font3, Misc[29]));
													}
													else 
														vez--;
												break;
											}//Fim do switch actioncursor_y
												ultimo_atacou = true;
										}//Fim do if h[vez].getHP > 0
									}//Fim de vez == 3
								vez++;
								}//Fim do if de !action
								
								if (B.getHP() <= 0 || ((h[0].getHP() <= 0) && (h[1].getHP() <= 0) && (h[2].getHP() <= 0) && (h[3].getHP() <= 0))) {
									Battle = false;
									EndGame = true;
								}
							}//Fim da batalha

							while(EndGame) {
								if(B.getHP() <= 0) {		//Vitória
									al_set_sample_instance_playing(audioinstance[4], 0);	//Desliga a música da batalha
									B.death();

									al_set_sample_instance_playing(audioinstance[6], 1);
									for(int i = 0; i < 4; i++) {
										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getVictory(), h[0].getpos_x(), h[0].getpos_y() - 5, 0);
										al_draw_bitmap(h[1].getVictory(), h[1].getpos_x(), h[1].getpos_y() - 5, 0);
										al_draw_bitmap(h[2].getVictory(), h[2].getpos_x(), h[2].getpos_y() - 5, 0);
										al_draw_bitmap(h[3].getVictory(), h[3].getpos_x(), h[3].getpos_y() - 5, 0);

										al_flip_display();
										al_rest(0.4);

										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getStop(), h[0].getpos_x(), h[0].getpos_y(), 0);
										al_draw_bitmap(h[1].getStop(), h[1].getpos_x(), h[1].getpos_y(), 0);
										al_draw_bitmap(h[2].getStop(), h[2].getpos_x(), h[2].getpos_y(), 0);
										al_draw_bitmap(h[3].getStop(), h[3].getpos_x(), h[3].getpos_y(), 0);

										al_flip_display();
										al_rest(0.3);
									}

									for(int i = 0; i < 3; i++) {
										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getVictoryInverse(), h[0].getpos_x(), h[0].getpos_y() - 5, 0);
										al_draw_bitmap(h[1].getVictoryInverse(), h[1].getpos_x(), h[1].getpos_y() - 5, 0);
										al_draw_bitmap(h[2].getVictoryInverse(), h[2].getpos_x(), h[2].getpos_y() - 5, 0);
										al_draw_bitmap(h[3].getVictoryInverse(), h[3].getpos_x(), h[3].getpos_y() - 5, 0);

										al_flip_display();
										al_rest(0.3);

										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getStopInverse(), h[0].getpos_x(), h[0].getpos_y(), 0);
										al_draw_bitmap(h[1].getStopInverse(), h[1].getpos_x(), h[1].getpos_y(), 0);
										al_draw_bitmap(h[2].getStopInverse(), h[2].getpos_x(), h[2].getpos_y(), 0);
										al_draw_bitmap(h[3].getStopInverse(), h[3].getpos_x(), h[3].getpos_y(), 0);

										al_flip_display();
										al_rest(0.4);
									}

									for(int i = 0; i < 4; i++) {
										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getVictory(), h[0].getpos_x(), h[0].getpos_y() - 5, 0);
										al_draw_bitmap(h[1].getVictory(), h[1].getpos_x(), h[1].getpos_y() - 5, 0);
										al_draw_bitmap(h[2].getVictory(), h[2].getpos_x(), h[2].getpos_y() - 5, 0);
										al_draw_bitmap(h[3].getVictory(), h[3].getpos_x(), h[3].getpos_y() - 5, 0);

										al_flip_display();
										al_rest(0.4);

										al_draw_bitmap(Misc[19], 0, 0, 0);		//Desenha o fundo

										al_draw_bitmap(h[0].getStop(), h[0].getpos_x(), h[0].getpos_y(), 0);
										al_draw_bitmap(h[1].getStop(), h[1].getpos_x(), h[1].getpos_y(), 0);
										al_draw_bitmap(h[2].getStop(), h[2].getpos_x(), h[2].getpos_y(), 0);
										al_draw_bitmap(h[3].getStop(), h[3].getpos_x(), h[3].getpos_y(), 0);

										al_flip_display();
										al_rest(0.3);
									}

									al_draw_bitmap(Misc[19], 0, 0, 0);				//Desenha o fundo
									al_draw_bitmap(h[0].getStop(), h[0].getpos_x(), h[0].getpos_y(), 0);
									al_draw_bitmap(h[1].getStop(), h[1].getpos_x(), h[1].getpos_y(), 0);
									al_draw_bitmap(h[2].getStop(), h[2].getpos_x(), h[2].getpos_y(), 0);
									al_draw_bitmap(h[3].getStop(), h[3].getpos_x(), h[3].getpos_y(), 0);
									al_flip_display();
									al_rest(20.0);
								}//Fim de if(B.getHP() <= 0)		

								else if(B.getHP() > 0) {
									al_set_sample_instance_playing(audioinstance[4], 0);	//Desliga a música da batalha
									al_set_sample_instance_playing(audioinstance[5], 1);
									al_rest(3.0);

									for(short fade = 110; fade > -1; fade--) {
										al_clear_to_color(al_map_rgb(fade, fade, fade));		//Fade Out
										
										al_flip_display();
										al_rest(0.045);
									}

									al_draw_bitmap(Misc[27], 0, 0, 0);
									al_flip_display();
									al_rest(10.0);
								}//Fim de else if (B.getHP() > 0) 

									al_set_sample_instance_playing(audioinstance[5], 0);
									al_set_sample_instance_playing(audioinstance[6], 0);

									al_destroy_display(display);
									main();

							}//Fim de while(EndGame)
					}//Fim de History 
				}//Fim de Person Screen
			}//Fim de PlayerNameScreen
		}//Fim do while de StartScreen

		while (desalocar) {
			al_destroy_display(display);

			for (int i = 0; i < 31; i++) {
				al_destroy_bitmap(Misc[i]);
			}

			for (int i = 0; i < 19; i++) {
				al_destroy_bitmap(Load[i]);
			}

			for (int i = 0; i < 3; i++) {
				al_destroy_sample(sample[i]);
			}

			for (int i = 0; i < 3; i++) {
				al_destroy_sample_instance(sampleinstance[i]);
			}

			for (int i = 0; i < 7; i++) {
				al_destroy_sample(audio[i]);
			}

			for (int i = 0; i < 7; i++) {
				al_destroy_sample_instance(audioinstance[i]);
			}

			al_destroy_event_queue(general_event);
			al_destroy_timer(timer);
			al_destroy_font(font1);
			al_destroy_font(font2);
			al_destroy_font(font3);
			al_destroy_font(font4);

			for (int i = 0; i < 4; i++) {	//Desaloca a memória dos heróis
				h[i].destroy();
			}

			B.destroy();					//Desaloca memória do Boss

			exit(0);
		}
	}//Fim de while(!end)
} //Fecha o Main


