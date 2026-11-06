#include <iostream>
#include <SDL3/SDL.h>
#include "video.h"
#include "character.h"
#include "enemy.h"
#include "colisao.h"
#include "rooms.h"

sala sala_atual; 
jogador j;

TipoSala tipo = TipoSala::sala1;
void loop_principal() {
	sala_atual.configurar_sala(TipoSala::sala1, largura, altura);

	

	
	bool rodando = true;
    while (rodando) {

        const bool* teclado_movimento = SDL_GetKeyboardState(NULL);
        SDL_Event evento;

        bool ataque_solicitado = false;

        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                rodando = false;
            }

            if (j.atacando(evento)) {
                ataque_solicitado = true;
            }
        }
        if (j.get_vida() <= 0) {
            rodando = false;
            std::cout << "voce morreu";
        }
       
        j.defendendo(teclado_movimento);

        j.movimentoJogador(teclado_movimento);
        j.posicao_hitbox();

        sala_atual.verificar_colisoes(j);

        sala_atual.configurar_inimigos(j);

        sala_atual.afastar_inimigos();

        if (ataque_solicitado) {
            sala_atual.aplicar_ataque(j);
        }
        sala_atual.matar_inimigos();

        desenharCenario();

        sala_atual.desenhar_paredes();
        sala_atual.desenhar_portas();
        sala_atual.desenhar_inimigos();

        sala_atual.transicao_de_sala(j, tipo, largura, altura);

        if (j.esta_defendendo()) {
            desenhoJogador_defendendo(
                j.usarquadrado(),
                j.olhando_para_esquerda(),
                j.get_inicio_defesa()
            );
        }
        else if (j.esta_atacando()) {
            desenhoJogador_atacando(
                j.usarquadrado(),
                j.olhando_para_esquerda(),
                j.get_inicio_ataque()
            );
        }
        else if (j.get_esta_movendo()) {
            desenhoJogador_andando(
                j.usarquadrado(),
                j.olhando_para_esquerda()
            );
        }
        else {
            desenhoJogador(
                j.usarquadrado(),
                j.olhando_para_esquerda()
            );
        } 

        executarRenderer();
        redefinirRenderer();
        limparFrame();
    }

		


}