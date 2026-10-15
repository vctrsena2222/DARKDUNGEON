#include <SDL3/SDL.h>
#include "video.h"
#include "character.h"
#include "enemy.h"
#include "colisao.h"

jogador j;
inimigo i(600, 600);
inimigo i2(600,700);


void loop_principal() {
	

	
	bool rodando = true;
	while (rodando) {


		SDL_Event evento;

		while (SDL_PollEvent(&evento)) 
		{
			if (evento.type == SDL_EVENT_QUIT) //evento recebe um objeto que fecha o progama, permite apertar X na janela
				rodando = false;// sai do loop principal
		}



		j.movimentoJogador();
		i.movimentoInimigo(j.usarquadrado());
		colisao(j.usarquadrado(), i.usarquadrado(),
			j.getxanterior(), j.getyanterior());


		desenharQuadrado(j.usarquadrado());

		desenharQuadrado(i.usarquadrado());

		desenharQuadrado(i2.usarquadrado());
		

		//i.movimentoInimigo(j.usarquadrado());

		//i2.movimentoInimigo(j.usarquadrado());

		

		executarRenderer();

		redefinirRenderer();

		limparFrame();
		


	}

		


}//CRIAR DETECÇÃO DE PROXIMIDADE PARA INIMIGO E RESTRINGIR A FUNÇÃO DE COLISÃO PARA AS PAREDES