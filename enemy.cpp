#include <SDL3/SDL.h>
#include <cmath>
#include <iostream>
#include "character.h"
#include "enemy.h"
#include "video.h"



void inimigo::movimentoInimigo(SDL_FRect quadrado_jogador) {

    if (estado_de_ataque) {
        velocidade_inimigo = 0.0f;
    }
    else { velocidade_inimigo = 0.10f; }
    if (quadrado_jogador.x > quadrado.x) {
        quadrado.x += velocidade_inimigo;
        inimigo_direcao = direita;
    }
    if (quadrado_jogador.x < quadrado.x) {
        quadrado.x -= velocidade_inimigo;
        inimigo_direcao = esquerda;
    }

    if (quadrado_jogador.y > quadrado.y) {

        quadrado.y += velocidade_inimigo;
        inimigo_direcao = baixo;
    }
    if (quadrado_jogador.y < quadrado.y) {
        quadrado.y -= velocidade_inimigo;
        inimigo_direcao = cima;
    }
   // verificação dos estados
    /*std::cout << "Estado de ataque: " << estado_de_ataque
        << " | atacando_inimigo: " << atacando_inimigo
        << " | Inicio preparacao: " << contagem_preparacao
        << " | Duracao preparo: " << duracaoPreparo
        << " | Tempo execucao: " << tempo_execucao
        << " | Duracao execucao: " << duracaoExecucaoAtaque
        << '\n';*/
}




void inimigo::posicao_hitbox_inimigo(SDL_FRect quadrado_jogador)
{
    float distanciaX = std::abs(quadrado_jogador.x - quadrado.x);
    float distanciaY = std::abs(quadrado_jogador.y - quadrado.y);

    if (distanciaX > distanciaY)
    {
        // Ataque horizontal
        if (quadrado_jogador.x > quadrado.x)
        {
            quadrado_colisao.x = quadrado.x + 60;
        }
        else
        {
            quadrado_colisao.x = quadrado.x - 60;
        }

        quadrado_colisao.y = quadrado.y;
    }
    else
    {
        // Ataque vertical
        if (quadrado_jogador.y > quadrado.y)
        {
            quadrado_colisao.y = quadrado.y + 60;
        }
        else
        {
            quadrado_colisao.y = quadrado.y - 60;
        }

        quadrado_colisao.x = quadrado.x;
    }
}
void inimigo::colisao_de_ataque(SDL_FRect quadrado_jogador, jogador& jogador) {
    if (
        quadrado_jogador.x + quadrado_jogador.w > quadrado_colisao.x &&
        quadrado_colisao.x + quadrado_colisao.w > quadrado_jogador.x &&
        quadrado_jogador.y + quadrado_jogador.h > quadrado_colisao.y &&
        quadrado_colisao.y + quadrado_colisao.h > quadrado_jogador.y
        ) {
        estado_de_ataque = true;
        atacando(jogador);
        
    }
    else {
        estado_de_ataque = false;
        inicio_preparacao = false;
        contagem_preparacao = 0;
        tempo_execucao = 0;
        atacando_inimigo = false;
    }
    
}




void inimigo::atacando(jogador& jogador) {

    if (!inicio_preparacao) {
        contagem_preparacao = SDL_GetTicks();
        inicio_preparacao = true;
    }

    if (!atacando_inimigo &&
        defesa_inimigo &&
        SDL_GetTicks() - contagem_preparacao >= duracaoPreparo) {

        atacando_inimigo = true;
        tempo_execucao = SDL_GetTicks();
        parry_realizado = false;
        dano_aplicado = false;
    }

    if (atacando_inimigo) {

        Uint64 tempo_atual = SDL_GetTicks();
        Uint64 tempo_ataque = tempo_atual - tempo_execucao;
        Uint64 inicio_defesa = jogador.get_inicio_defesa();

        if (!parry_realizado &&
            tempo_ataque <= janela_parry &&
            jogador.esta_defendendo() &&
            inicio_defesa >= tempo_execucao &&
            inicio_defesa - tempo_execucao <= janela_parry) {

            parry_realizado = true;
            defesa_inimigo = false;
            atacando_inimigo = false;

            std::cout << "PARRY REALIZADO" << std::endl;
        }
        else if (!dano_aplicado &&
            tempo_ataque >= janela_parry) {

            jogador.receber_dano(atacando_inimigo);
            dano_aplicado = true;
        }
    }

    // Encerra o ciclo do ataque sem restaurar a defesa.
    if (tempo_execucao != 0 &&
        SDL_GetTicks() - tempo_execucao >= duracaoExecucaoAtaque) {

        inicio_preparacao = false;
        estado_de_ataque = false;
        contagem_preparacao = 0;
        tempo_execucao = 0;
        atacando_inimigo = false;
        parry_realizado = false;
        dano_aplicado = false;
    }
}


void inimigo::inimigo_recebe_dano(bool atacando_jogador, SDL_FRect quadradoColisao_jogador) {

    std::cout << "ataque jogador: " << atacando_jogador
        << " | defesa inimigo: " << defesa_inimigo
        << std::endl;
    if (atacando_jogador == true && !defesa_inimigo && quadradoColisao_jogador.x + quadradoColisao_jogador.w > quadrado.x &&
        quadradoColisao_jogador.x < quadrado.x + quadrado.w &&
        quadradoColisao_jogador.y + quadradoColisao_jogador.h > quadrado.y &&
        quadradoColisao_jogador.y < quadrado.y + quadrado.h) {
        vida_inimigo -= 1;
    }
    std::cout << "vida do inimigo: " << vida_inimigo << " ";


};

void inimigo::mudanca_de_cor(SDL_Renderer* renderer) {
    Uint64 duracao_da_cor1 = 500;
    Uint64 duracao_da_cor2 = 1500;
    Uint64 duracao_da_cor3 = 3000;

    Uint64 tempo_decorrido = SDL_GetTicks() - contagem_preparacao;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    if (estado_de_ataque == true && tempo_decorrido < duracao_da_cor1) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    else if (estado_de_ataque == true && tempo_decorrido > 1000 && tempo_decorrido < duracao_da_cor2) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    else if (estado_de_ataque == true && tempo_decorrido > 2000 && tempo_decorrido < duracao_da_cor3) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    SDL_RenderFillRect(renderer, &quadrado);
}












