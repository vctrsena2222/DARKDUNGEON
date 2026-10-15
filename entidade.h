#pragma once
#include <SDL3/SDL.h>

class entidade {

protected: //um especificador de acesso que permite que o atributo seja acessado apenas por metodos da classe ou por classes derivadas desta
	SDL_FRect quadrado;
	SDL_FRect quadrado_colisao;

private:


public:
	entidade() {
		quadrado.w = 50;
		quadrado.h = 50;
		quadrado_colisao.w = 50;
		quadrado_colisao.h = 50;
	}
	

};

