#pragma once
#include "entidade.h"
#include <SDL3/SDL.h>
class jogador;//declaraçao antecipada, apra o compilador conhecer a classe executar os metodos, na chamadao objeto referente a classe necessaria sera usado


class inimigo : public entidade {

public:

	inimigo(float x, float y) {//construtor pra definir posição
		quadrado.x = x;
		quadrado.y = y;

	}
	

	SDL_FRect& usarquadrado() {
		return quadrado;
	}
	SDL_FRect& usarquadrado_colisao() {
		return quadrado_colisao;
	}

	void movimentoInimigo(SDL_FRect quadrado_jogador);
	void mudanca_de_cor( SDL_Renderer* renderer);
	void posicao_hitbox_inimigo(SDL_FRect quadrado_jogador);
	void colisao_de_ataque(SDL_FRect quadrado_jogador, jogador& jogador);
	void atacando(jogador& jogador);
	void inimigo_recebe_dano(bool atacando_jogador, SDL_FRect quadradoColisao_jogador);


private: 
	int vida_inimigo = 100;
	float velocidade_inimigo = 0.10f;
	direcao inimigo_direcao = esquerda;

	//abaixo vairaveis relacionadas ao sistema de ataque
	//estados de ataque
	bool estado_de_ataque = false; //vai pra true quando inimigo entra em estado de ataque
	bool atacando_inimigo =  false;//serve pra identificar quando a vida do jogador é afetada
	bool inicio_preparacao = false;
	bool defesa_inimigo = true;
	bool parry_realizado = false;
	bool dano_aplicado = false;

	Uint64 janela_parry = 500;


	//marcadores de tempo
	Uint64 contagem_preparacao = 0;
	Uint64 duracaoPreparo = 3000;//

	Uint64 tempo_execucao = 0;
	Uint64 duracaoExecucaoAtaque = 1000;


};

