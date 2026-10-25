#include <SDL3/SDL.h>
#include <iostream>
#include "video.h"
#include "game.h"
#include "character.h"




int main() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); 

	criarJanela();
	
	loop_principal();

	


	return 0;
}