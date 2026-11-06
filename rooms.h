
#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "character.h"
#include "enemy.h"

enum class TipoSala {
    sala1,
    sala2,
    sala3,
    sala4
};

class porta {
private:
    SDL_FRect desenho_porta{};

public:
    void criar_portas(float x, float y, float w, float h) {
        desenho_porta.x = x;
        desenho_porta.y = y;
        desenho_porta.w = w;
        desenho_porta.h = h;
    }

    SDL_FRect& usarQuadradoPorta() {
        return desenho_porta;
    }
};

class paredes {
private:
    SDL_FRect desenho_colisao{};

public:
    void criar_parede(float x, float y, float w, float h) {
        desenho_colisao.x = x;
        desenho_colisao.y = y;
        desenho_colisao.w = w;
        desenho_colisao.h = h;
    }

    SDL_FRect& usarquadrado_paredes() {
        return desenho_colisao;
    }
}; 

class sala {
private:
    std::vector<paredes> lista_paredes;
    std::vector<porta> lista_porta;
    std::vector<std::unique_ptr<inimigo>> lista_inimigos;

public:
    void configurar_sala(TipoSala tipo, int largura, int altura);

    void configurar_sala1(int largura, int altura);
    void configurar_sala2(int largura, int altura);
    void configurar_sala3(int largura, int altura);
    void configurar_sala4(int largura, int altura);

    void verificar_colisoes(jogador& jogador);
    void transicao_de_sala(jogador& jogador, TipoSala& tipo, int largura, int altura);

    void desenhar_paredes();
    void desenhar_portas();
    void desenhar_inimigos();
    void configurar_inimigos(jogador& jogador);
    void aplicar_ataque(jogador& jogador);
    void afastar_inimigos();
    void matar_inimigos();
};
