#include <SDL3/SDL.h>
#include <iostream>
#include "video.h"
#include "game.h"
#include "character.h"
#include "audio.h"





int main() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); 
    if (!inicializarAudio()) {
        SDL_Quit();
        return 1;
    }

    if (!carregarEfeitosSonoros()) {
        encerrarAudio();
        SDL_Quit();
        return 1;
    }

	criarJanela();
	
	loop_principal();

	

	encerrarAudio();
	return 0;
}