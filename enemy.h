#pragma once
#include "entidade.h"
#include <SDL3/SDL.h>

class inimigo : public entidade {

public:

	inimigo(float x, float y) {//construtor pra definir posição
		quadrado.x = x;
		quadrado.y = y;

	}
	

	SDL_FRect& usarquadrado() {
		return quadrado;
	}


	void movimentoInimigo(SDL_FRect quadrado_jogador);
	


private: 
	float velocidade_inimigo = 0.03f;
	

};