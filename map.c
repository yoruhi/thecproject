#include "prototypes.h"
#include "structs.h" 
#include <SDL2/SDL.h>
 
Map map;
Input input;

void initMaps(void) {// Charge l'image du fond (background)
	map.dim1=loadImage("Dim1.bmp");
	map.dim2=loadImage("Dim2.bmp");
	map.activemap = 1;
}

void dimSwitch(Input *input){
	if (input->changeBack == 1){
		if(map.activemap == 1){
				map.activemap = 2;
				input-> changeBack = 0;
		}else{ 
				if(map.activemap == 2){
				map.activemap = 1;
				input-> changeBack = 0;
			}
		}
	}
}
 // Todo gérer le multi background après l'implé du switch via touch
SDL_Texture* getBackground() {
	switch (map.activemap){
		case 1:
			return map.dim1;
    break;
		case 2:
			return map.dim2;
		break;

	  default:
    break;
	}
}


void cleanMaps(void){
	// Libère la texture du background
	if (map.dim1 != NULL)	{
		SDL_DestroyTexture(map.dim1);
		map.dim1 = NULL;
	}
	if (map.dim2 != NULL)	{
		SDL_DestroyTexture(map.dim1);
		map.dim2 = NULL;
	}
 
}
