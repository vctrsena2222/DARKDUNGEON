#pragma once
#include <SDL3/SDL.h>
extern SDL_Renderer* renderer;//extern informa que a variavel esta declarada em outro lugar e pode ser acessada por aqui, assim, quando puxo o video.h em outro lugar posso usar essa variavel
extern const int largura;
extern const int altura;

void criarJanela();
void desenharQuadrado(SDL_FRect& quadrado);
void executarRenderer();
void limparFrame();
void redefinirRenderer();