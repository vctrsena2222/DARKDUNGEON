#include <SDL3/SDL.h>
#include <iostream>
#include "enemy.h"
#include "character.h"

void jogador::movimentoJogador(const bool* teclado_movimento) {
    teclado_movimento = SDL_GetKeyboardState(NULL);
	xanterior = quadrado.x;
	yanterior = quadrado.y;

	if (teclado_movimento[SDL_SCANCODE_W] or teclado_movimento[SDL_SCANCODE_UP]) {//cima
		quadrado.y -= velocidade;
		jogador_direcao = cima;
	}
	if (teclado_movimento[SDL_SCANCODE_S] or teclado_movimento[SDL_SCANCODE_DOWN]) {//baixo
		quadrado.y += velocidade;
		jogador_direcao = baixo;

	}
	if (teclado_movimento[SDL_SCANCODE_D] or teclado_movimento[SDL_SCANCODE_RIGHT]) {//direita
		quadrado.x += velocidade;
		jogador_direcao = direita;
	}
    if (teclado_movimento[SDL_SCANCODE_A] or teclado_movimento[SDL_SCANCODE_LEFT]) {//esquerda
		quadrado.x -= velocidade;
		jogador_direcao = esquerda;
	}



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

void jogador::atacando(SDL_Event evento, inimigo& inimigo) {

    if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN &&
		evento.button.button == SDL_BUTTON_LEFT)//se evento recebe um objeto que identifica quando o botão do mouse é apertado e esse botão é o botao esquerdo
	{
		atacando_jogador = true; //atacando vai pra true
	}
	else { atacando_jogador = false; }
	inimigo.inimigo_recebe_dano(atacando_jogador, quadrado_colisao);
	std::cout << "atacou " << atacando_jogador << std::endl;
	
}

void jogador::defendendo(const bool* teclado_movimento, inimigo& inimigo) {

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






