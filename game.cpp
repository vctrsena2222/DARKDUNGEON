#include <SDL3/SDL.h>
#include "video.h"
#include "character.h"
#include "enemy.h"
#include "colisao.h"
#include "rooms.h"

sala sala_atual; 
jogador j;
inimigo i(600, 600);
inimigo i2(600,700);

TipoSala tipo = TipoSala::sala1;
void loop_principal() {
	sala_atual.configurar_sala(TipoSala::sala1, largura, altura);

	

	
	bool rodando = true;
	while (rodando) {

		const bool* teclado_movimento = SDL_GetKeyboardState(NULL);
		SDL_Event evento;

		while (SDL_PollEvent(&evento)) 
		{
			if (evento.type == SDL_EVENT_QUIT) //evento recebe um objeto que fecha o progama, permite apertar X na janela
				rodando = false;// sai do loop principal
			j.atacando(evento, i);
			

		}
		j.defendendo(teclado_movimento, i);

		j.movimentoJogador(teclado_movimento);
		sala_atual.verificar_colisoes(j);
		
		i.movimentoInimigo(j.usarquadrado());
		i.posicao_hitbox_inimigo(j.usarquadrado());
		i.colisao_de_ataque(j.usarquadrado(), j);

		sala_atual.desenhar_paredes();
		sala_atual.desenhar_portas();
		sala_atual.transicao_de_sala(j, tipo, largura, altura);
		

		desenharQuadrado(i.usarquadrado_colisao());

		desenharQuadrado(j.usarquadrado());
		desenharQuadrado(j.usarquadrado_colisao());

		j.posicao_hitbox();

		desenharQuadrado(i.usarquadrado());
		i.mudanca_de_cor(renderer);
		

	

		

		executarRenderer();

		redefinirRenderer();

		limparFrame();
		


	}

		


}//CRIAR DETECÇÃO DE PROXIMIDADE PARA INIMIGO E RESTRINGIR A FUNÇÃO DE COLISÃO PARA AS PAREDES