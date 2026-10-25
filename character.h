#pragma once
#include "entidade.h"
#include <SDL3/SDL.h>

class inimigo;//declaraçao antecipada, apra o compilador conhecer a classe executar os metodos, na chamadao objeto referente a classe necessaria sera usado

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

	bool esta_defendendo() const {
		return defesa_jogador;
	};
	Uint64 get_inicio_defesa() const {
		return inicio_defesa;
	
	};

	void atacando(SDL_Event evento, inimigo& inimigo);
	void defendendo(const bool* teclado_movimento, inimigo& inimigo);
	void receber_dano(bool inimigo_atacando);
	void movimentoJogador(const bool* teclado_movimento);
	void posicao_hitbox();
    float getxanterior();
	float getyanterior();

private:
	
	int vida_jogador = 100;
	float velocidade = 0.25f;

	float xanterior;
	float yanterior;

	bool atacando_jogador = false;
	bool defesa_jogador = false;
	bool defesa_anterior = false;
	Uint64 inicio_defesa = 0;
	direcao jogador_direcao = direita;


};