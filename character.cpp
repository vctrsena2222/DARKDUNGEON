#include <SDL3/SDL.h>
#include <iostream>
#include "enemy.h"
#include "character.h"

void jogador::movimentoJogador(const bool* teclado_movimento) {
	teclado_movimento = SDL_GetKeyboardState(NULL);

	xanterior = quadrado.x;
	yanterior = quadrado.y;

	float velocidade_atual = velocidade;

	if (teclado_movimento[SDL_SCANCODE_LSHIFT] ||
		teclado_movimento[SDL_SCANCODE_RSHIFT]) {
		velocidade_atual *= 1.5f;
	}

	if (teclado_movimento[SDL_SCANCODE_W] or teclado_movimento[SDL_SCANCODE_UP]) {
		quadrado.y -= velocidade_atual;
		jogador_direcao = cima;
	}
	if (teclado_movimento[SDL_SCANCODE_S] or teclado_movimento[SDL_SCANCODE_DOWN]) {
		quadrado.y += velocidade_atual;
		jogador_direcao = baixo;
	}
	if (teclado_movimento[SDL_SCANCODE_D] or teclado_movimento[SDL_SCANCODE_RIGHT]) {
		quadrado.x += velocidade_atual;
		jogador_direcao = direita;
	}
	if (teclado_movimento[SDL_SCANCODE_A] or teclado_movimento[SDL_SCANCODE_LEFT]) {
		quadrado.x -= velocidade_atual;
		jogador_direcao = esquerda;
	}
	esta_movendo = (quadrado.x != xanterior || quadrado.y != yanterior);
}
void jogador::posicao_hitbox() {

	if (jogador_direcao == cima) {
		quadrado_colisao.x = quadrado.x;
		quadrado_colisao.y = quadrado.y - 60;
	}
	else if (jogador_direcao == baixo) {
		quadrado_colisao.x = quadrado.x;
		quadrado_colisao.y = quadrado.y + 60;
	}
	else if (jogador_direcao == direita) {
		quadrado_colisao.x = quadrado.x + 60;
		quadrado_colisao.y = quadrado.y;
	}
	else if (jogador_direcao == esquerda) {
		quadrado_colisao.x = quadrado.x - 60;
		quadrado_colisao.y = quadrado.y;
	}

};

bool jogador::atacando(const SDL_Event& evento) {

	if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN &&
		evento.button.button == SDL_BUTTON_LEFT) {

		atacando_jogador = true;
		inicio_ataque = SDL_GetTicks();

		return true;
	}

	return false;
}

void jogador::defendendo(const bool* teclado_movimento) {
	defesa_jogador = teclado_movimento[SDL_SCANCODE_SPACE];

	if (defesa_jogador && !defesa_anterior) {
		inicio_defesa = SDL_GetTicks();
	}

	defesa_anterior = defesa_jogador;
}

void jogador::receber_dano(bool inimigo_atacando) {
	if (inimigo_atacando && !defesa_jogador) { vida_jogador -= 1; };
	std::cout << "vida do jogador: " << vida_jogador << std::endl;

};






	float jogador::getxanterior() {
	
		return xanterior;
	
	}
	float jogador::getyanterior() {

		return  yanterior;
		

	}






