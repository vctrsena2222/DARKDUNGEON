#pragma once
#include <SDL3/SDL.h>

enum class TipoSala {
    sala1,
    sala2,
    sala3,
    sala4
};

class paredes {
private:
    SDL_FRect desenho_colisao;

public:
    void criar_parede(float x, float y, float w, float h) {
        desenho_colisao.x = x;
        desenho_colisao.y = y;
        desenho_colisao.w = w;
        desenho_colisao.h = h;
    }
    SDL_FRect& usarquadrado_paredes() {
        return desenho_colisao;
    };
};