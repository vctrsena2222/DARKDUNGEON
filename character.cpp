#include <SDL3/SDL.h>
#include "character.h"

void jogador::movimentoJogador() {
	const bool* teclado_movimento = SDL_GetKeyboardState(NULL);
	xanterior = quadrado.x;
	yanterior = quadrado.y;

	if (teclado_movimento[SDL_SCANCODE_W] or teclado_movimento[SDL_SCANCODE_UP]) {//cima
		quadrado.y -= velocidade;
	}
	if (teclado_movimento[SDL_SCANCODE_S] or teclado_movimento[SDL_SCANCODE_DOWN]) {//baixo
		quadrado.y += velocidade;

	}
	if (teclado_movimento[SDL_SCANCODE_D] or teclado_movimento[SDL_SCANCODE_RIGHT]) {//direita
		quadrado.x += velocidade;
	}
	if (teclado_movimento[SDL_SCANCODE_A] or teclado_movimento[SDL_SCANCODE_LEFT]) {//direita
		quadrado.x -= velocidade;
	}


}

	float jogador::getxanterior() {
	
		return xanterior;
	
	}
	float jogador::getyanterior() {

		return  yanterior;
		

	}






