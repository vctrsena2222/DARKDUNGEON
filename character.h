#pragma once
#include "entidade.h"
#include <SDL3/SDL.h>

class jogador : public entidade {



public:
	SDL_FRect& usarquadrado() {
		return quadrado;
	}
	SDL_FRect& usarquadrado_colisao() {
		return quadrado_colisao;
	}

	jogador() {
		quadrado.x = 100;
		quadrado.y = 600;
			
	}

	void movimentoJogador();
    float getxanterior();
	float getyanterior();

private:
	float velocidade = 0.05f;

	float xanterior;
	float yanterior;


};