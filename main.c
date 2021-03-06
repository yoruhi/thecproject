#include "prototypes.h"
#include <SDL2/SDL.h>

Input input;
Player player;
sList tabShoot=NULL;
eList enlist; 
int firstIndex, lastIndex,currentIndex;
	
int main(int argc, char *argv[]){
    
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;
	srand(time(NULL));	
	init("Je suce des gnomes");// Initialisation de la SDL 
	enlist = headAddEnneny(enlist);
	enlist = headAddEnneny(enlist);
	
		loadGame();// Chargement des ressources (graphismes, sons)
    initializePlayer();
		initInputs(&input);
    atexit(cleanup);// Appelle la fonction cleanup à la fin du programme 
 
    go = 1;
 
    // Boucle infinie, principale, du jeu 
    while (go == 1)
    {
        gestionInputs(&input);//Gestion des inputs clavier
				updatePlayer(&input);
				updateShoot(tabShoot);
      	updateEnnemy(enlist,tabShoot);
        drawGame(); //On dessine tout

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16)
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
    exit(0);
}
