#pragma once
#include <SDL3/SDL.h>

extern SDL_Renderer* renderer;
extern const int largura;
extern const int altura;

enum class AnimacaoOrc {
    parado,
    andando,
    atacando
};

void criarJanela();
void desenharQuadrado(SDL_FRect& quadrado);
void executarRenderer();
void limparFrame();
void redefinirRenderer();

bool carregarTextura_jogador_parado();
bool carregarTextura_jogador_andar();
bool carregarTextura_jogador_defesa();
bool carregarTextura_jogador_ataque();

void desenhoJogador_andando(SDL_FRect& destino, bool olhando_esquerda);
void desenhoJogador(SDL_FRect& destino, bool olhando_esquerda);

void desenhoJogador_defendendo(
    SDL_FRect& destino,
    bool olhando_esquerda,
    Uint64 inicio_defesa
);

void desenhoJogador_atacando(
    SDL_FRect& destino,
    bool olhando_esquerda,
    Uint64 inicio_ataque
);

// Funções relacionadas ao Orc.
bool carregarTexturas_inimigo();

bool desenhoInimigo(
    SDL_Renderer* renderer,
    SDL_FRect& destino,
    bool olhando_esquerda,
    int frame,
    AnimacaoOrc animacao,
    bool vermelho
);