#include "jorgito_reforzado.h"

int jugar();

ALLEGRO_DISPLAY* ventana;
ALLEGRO_FONT* cookie;
ALLEGRO_TIMER* segundoTimer;
ALLEGRO_EVENT_QUEUE* queue;
int ancho = 896;
int alto = 768;

int main()
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR 404", "No se pudo abrir allegro", NULL, ALLEGRO_MESSAGEBOX_QUESTION);
	}

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_image_addon();


	int anchoW = GetSystemMetrics(SM_CXSCREEN);
	int altoW = GetSystemMetrics(SM_CYSCREEN);
	

	ventana = al_create_display(ancho, alto);
	cookie = al_load_font("fuentes/Symtext.ttf",70,0);
	segundoTimer = al_create_timer(1.0);
	
	ALLEGRO_EVENT evento;
	queue = al_create_event_queue();
	
	ALLEGRO_COLOR blanco = al_map_rgb(255,255,255);
	ALLEGRO_COLOR  azar = al_map_rgb(34, 23, 67);

	ALLEGRO_BITMAP* menu_null = al_load_bitmap("imagenes/menu_null.png");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("imagenes/menu_jugar.png");
	ALLEGRO_BITMAP* menu_instrucciones = al_load_bitmap("imagenes/menu_instrucciones.png");
	ALLEGRO_BITMAP* menu_comosejuega = al_load_bitmap("imagenes/menu_comosejuega.png");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("imagenes/menu_salir.png");

	al_set_window_title(ventana, "CYBERCOOK");
	al_set_window_position(ventana, anchoW / 2 - ancho/2, altoW / 2 - alto/2);

	al_register_event_source(queue, al_get_timer_event_source(segundoTimer));
	al_register_event_source(queue, al_get_mouse_event_source());

	al_start_timer(segundoTimer);

	//al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR 404", "HOLA SI ME ABRI UWU", NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL);
	
	int segundo = 0;
	int x = -1, y = -1;
	
	int botones[] = { 0 };

	while(true)
	{
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			if (evento.timer.source == segundoTimer)
			{
				segundo++;
			}
		}
		
		

		if (botones[0] == 0)
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}
		else 
		{
			if(botones[0]==1)
			{
				al_draw_bitmap(menu_jugar, 0, 0, 0);
			}
			else
			{
				if (botones[0] == 2) 
				{
					al_draw_bitmap(menu_instrucciones, 0, 0, 0);
				}
				else
				{
					if (botones[0] == 3)
					{
						al_draw_bitmap(menu_comosejuega, 0, 0, 0);
					}
					else
					{
						al_draw_bitmap(menu_salir, 0, 0, 0);
					}
				}
				
			}
		}
		
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			x = evento.mouse.x;
			y = evento.mouse.y;
			 
			// 1 = clic izquierdo, 2 = clic derecho, 4= ruedita
			if (x >= 410 && x <= 812 && y >= 359 && y <= 432) 
			{
				botones[0] = 1;
				if (evento.mouse.button & 1)
				{
					jugar();
				}
			}
			else
			{
				if (x >= 409 && x <= 810 && y >= 453 && y <= 523)
				{
					botones[0] = 2;
					if (evento.mouse.button & 1)
					{
						printf("Instrucciones :)\n");
					}
				}
				else
				{
					if (x >= 406 && x <= 809 && y >= 548 && y <= 618)
					{
						botones[0] = 3;
						if (evento.mouse.button & 1)
						{
							printf("Como se juega :) :(\n");
						}
					}
					else
					{
						if (x >= 404 && x <= 806 && y >= 639 && y <= 709)
						{
							botones[0] = 4;
							if (evento.mouse.button & 1)
							{
								return 1;
							}
						}
						else
						{
							botones[0] = 0;
						}
					}
				}
				
			}

			
		}
		
		
		al_flip_display();
	}
	return 0;
}

int jugar()
{
	printf("Jugar :)\n");
	return 1;
}