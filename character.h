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
	int get_vida() const {
		return vida_jogador;
	}
	bool get_esta_movendo() const {
		return esta_movendo;
	}
	bool esta_atacando() const {
		return atacando_jogador &&
			SDL_GetTicks() - inicio_ataque < 360;
	}

	Uint64 get_inicio_ataque() const {
		return inicio_ataque;
	}

	bool atacando(const SDL_Event& evento);

	bool olhando_para_esquerda() const {
		return jogador_direcao == esquerda;
	}
	
	void defendendo(const bool* teclado_movimento);
	void receber_dano(bool inimigo_atacando);
	void movimentoJogador(const bool* teclado_movimento);
	void posicao_hitbox();
    float getxanterior();
	float getyanterior();
	void atualizar_posicao_anterior() {
		xanterior = quadrado.x;
		yanterior = quadrado.y;
	}

private:
	
	int vida_jogador = 1;
	float velocidade = 0.15f;

	float xanterior;
	float yanterior;

	bool atacando_jogador = false;
	Uint64 inicio_ataque = 0;
	bool defesa_jogador = false;
	bool defesa_anterior = false;
	Uint64 inicio_defesa = 0;
	direcao jogador_direcao;

	bool esta_movendo = false;


};