#include "prototypes.h"

Player player;
SDL_Texture* playerSprite;

void initPlayerSprite(void){
	playerSprite = loadImage("spaceship.png");
}

void cleanPlayer(void){
	if(playerSprite != NULL){
		SDL_DestroyTexture(playerSprite);
		playerSprite = NULL;
	}
}

void drawPlayer(){
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 55;
	src.h = 41;
	
	
	SDL_Rect dest;
	dest.x = 250;
	dest.y = 250;
	dest.w = 55; 
	dest.h = 41;

SDL_RenderCopyEx(getrenderer(), playerSprite, &src, &dest, 0, 0, SDL_FLIP_NONE);
}

void initializePlayer(void){
	player.health = 100;
	player.score = 0;
	player.cdOra = 0;
	player.cdYell=0;player.active[1]=0; 
	player.cdRed=0;player.active[2]=0; 
	player.cdNBlu=0; player.active[3]=0;
	player.cdTur=0;player.active[4]=0;
	player.cdGree=0;player.active[5]=0;
	player.cdPur=0; player.active[6]=0;
	player.cdPin=0;player.active[7]=0;
	player.cdVio=0;player.active[8]=0;
	player.active[0]=1;
	player.viewX = 0;
	player.viewY = 0;
}
//player.active pourrait donner le niveau de la couleur
void updatePlayer(Input* input){
	player.viewX = input->aimX;
	player.viewY = input->aimY;
	dimSwitch(input);
//if(input->orange==1){/*gerer le tir en fonction de la couleur jaune ou orange*/}
//if(input->mute==1){/*mute le jeu*/}
//if(input->pause==1){/*pause le jeu tant que cette valeur est de 1*/}
//if(input->yellow==1){/*laser,check jaune, si disponible, activation*/}
//if(input->red==1){/*heal,check red, si disponible, activation*/}
//if(input->navyblue==1){/*slow, check navyblue, si disponible, activation*/}
//if(input->turquoise==1){/*ally,check turquoise, si disponible, activation*/}
//if(input->green==1){/*full circle,check green, si disponible, activation*/}
//if(input->purple==1){/*nuke,check purple si disponible, activation*/}
//if(input->pink==1){/*freeze total, check pink, si disponible, activation*/}
//if(input->violet==1){/* invincible, check violet, si disponible, activation*/} 
}


