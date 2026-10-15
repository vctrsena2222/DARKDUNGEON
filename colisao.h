#pragma once
#include <SDL3/SDL.h>

void colisao(SDL_FRect& jogador, const SDL_FRect& obstaculo,
    float xAnterior, float yAnterior);