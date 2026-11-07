#pragma once
#include "entidade.h"
#include <SDL3/SDL.h>


class jogador;

class inimigo : public entidade {

public:

    inimigo(float x, float y) {
        quadrado.x = x;
        quadrado.y = y;
    }

    int get_vida() const {
        return vida_inimigo;
    }

    SDL_FRect& usarquadrado() {
        return quadrado;
    }

    SDL_FRect& usarquadrado_colisao() {
        return quadrado_colisao;
    }

    void movimentoInimigo(SDL_FRect quadrado_jogador);
    void mudanca_de_cor(SDL_Renderer* renderer);
    void posicao_hitbox_inimigo(SDL_FRect quadrado_jogador);
    void colisao_de_ataque(SDL_FRect quadrado_jogador, jogador& jogador);
    void atacando(jogador& jogador);
    void inimigo_recebe_dano(bool atacando_jogador, SDL_FRect quadradoColisao_jogador);


private:

    int vida_inimigo = 3;
    float velocidade_inimigo = 0.10f;

    direcao inimigo_direcao = esquerda;

    // Controle da movimentação.
    bool esta_movendo = false;
    bool olhando_esquerda = false;

    // Controle das animações.
    enum class EstadoAnimacao {
        parado,
        andando,
        atacando
    };

    EstadoAnimacao animacao_atual = EstadoAnimacao::parado;

    int frame_atual = 0;
    Uint64 inicio_animacao = 0;


    // Estados de ataque.
    bool estado_de_ataque = false;
    bool atacando_inimigo = false;
    bool inicio_preparacao = false;
    bool defesa_inimigo = true;
    bool parry_realizado = false;
    bool dano_aplicado = false;

    Uint64 janela_parry = 500;


    // Marcadores de tempo.
    Uint64 contagem_preparacao = 0;
    Uint64 duracaoPreparo = 3000;

    Uint64 tempo_execucao = 0;
    Uint64 duracaoExecucaoAtaque = 1000;

};