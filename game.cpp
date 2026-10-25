#include <SDL3/SDL.h>
#include "video.h"
#include "character.h"
#include "enemy.h"
#include "colisao.h"
#include "rooms.h"
//PARA CRIAR PAREDE
paredes parede_superior;//criar o objeto, usando rooms.h
jogador j;
inimigo i(600, 600);
inimigo i2(600,700);


void loop_principal() {
	

	
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
		
		i.movimentoInimigo(j.usarquadrado());
		i.posicao_hitbox_inimigo(j.usarquadrado());
		i.colisao_de_ataque(j.usarquadrado(), j);

		//TESTE: DESENHANDO PAREDES E APLICANDO COLISAO
		parede_superior.criar_parede(0.0f, 0.0f, 1200.0f, 20.0f);//primeiro usa-se o metodo para determinar tamanho e posição do objeto
		desenharQuadrado(parede_superior.usarquadrado_paredes());//desenhe esse objeto usando o metodo desenhar quadrado declarado em video
		colisao(j.usarquadrado(), parede_superior.usarquadrado_paredes(), j.getxanterior(), j.getyanterior()); //usa a função de colisão no colisão.h

		//

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