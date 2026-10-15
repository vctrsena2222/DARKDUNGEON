#include <SDL3/SDL.h>
#include "enemy.h"


void inimigo::movimentoInimigo(SDL_FRect quadrado_jogador){

	if (quadrado_jogador.x > quadrado.x) {
		quadrado.x += velocidade_inimigo;

	}
	if (quadrado_jogador.x < quadrado.x) {
		quadrado.x -= velocidade_inimigo;
	}

	if (quadrado_jogador.y > quadrado.y) {

		quadrado.y += velocidade_inimigo;
	}
	if (quadrado_jogador.y < quadrado.y) {
		quadrado.y -= velocidade_inimigo;
	}


}

