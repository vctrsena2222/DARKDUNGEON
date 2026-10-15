#pragma once
#include <SDL3/SDL.h>
extern const int largura;
extern const int altura;

void criarJanela();
void desenharQuadrado(SDL_FRect& quadrado);
void executarRenderer();
void limparFrame();
void redefinirRenderer();