#include "prototypes.h"

Ennemy ennemy;
eList ennList; 
SDL_Texture* ennemiSprite;

Ennemy* createEnnemy(Name name){
	Ennemy* e=malloc(sizeof(Ennemy));
	e-> dimension = 1;//randomiser
	e -> speed=10;//randomiser le resultat
	e -> name=name;
	e -> appRadius = RADIUS;
	e -> appAngle = 42;
	e -> timer = TIMER;
	e -> posX = PLR_X + RADIUS*cos(e->appAngle);
	e -> posY = PLR_Y + RADIUS*sin(e->appAngle);
	e -> progressX = (e->speed)*cos(e->appAngle);
	e -> progressY =(e->speed)*sin(e->appAngle);	
	return e;
}

eList headAddEnneny(eList list){
	Ennemy* e = malloc(sizeof(Ennemy));
	e = createEnnemy(octogone);
	e ->next = list;
	printf("prout");
	return e;
}


void deleteEnnemy(Ennemy* ennemy){
	free(ennemy);
}

void drawEnnemy(eList list){
	Ennemy* e = list;

	while( e != NULL){
			SDL_Rect src;
			src.x = 0;
			src.y = 0;
			src.w = MONSTER_WIDTH;
			src.h = MONSTER_HEIGTH;
		
			SDL_Rect dest;
			dest.x = e->posX;
			dest.y = e->posY;
			dest.w = 25; 
			dest.h = 30;

			SDL_RenderCopyEx(getrenderer(), ennemiSprite, &src, &dest,0, 0, SDL_FLIP_NONE);
			e=e->next;
	}	
}

void updateEnnemy(eList list){
	Ennemy* e = list;
	while	(e != NULL){
		e->timer-=1;
		printf("diminution du timer");
		if (e->timer < 0){
			e->posX-=e->progressX;
			e->posY-=e->progressY;
		}
		e=e->next;	
	}
}

void initEnnemySprites(void){
	ennemiSprite=loadImage("tuk.png");
}

