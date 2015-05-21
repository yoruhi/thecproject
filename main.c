#include "prototypes.h"
#include <SDL2/SDL.h>
 
/* Déclaration des variables / structures utilisées par le jeu */
 Input input;
 Player player;
 eList enlist;
 
int main(int argc, char *argv[])
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
 
    // Initialisation de la SDL 
    init("Je suce des gnomes");
		enlist = headAddEnneny(enlist);
		//initInputs(&input);
 
	// Chargement des ressources (graphismes, sons)
		loadGame();
    
	// Appelle la fonction cleanup à la fin du programme 
    atexit(cleanup);
 
    go = 1;
 
    // Boucle infinie, principale, du jeu 
    while (go == 1)
    {
        //Gestion des inputs clavier
        gestionInputs(&input);
				updatePlayer(&input);
				updateEnnemy(enlist);

        //On dessine tout
        drawGame();

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16)
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
    exit(0);
}
