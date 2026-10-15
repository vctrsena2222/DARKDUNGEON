#include <SDL3/SDL.h>


void colisao(SDL_FRect& jogador, const SDL_FRect& obstaculo,
    float xAnterior, float yAnterior)
{
    bool colidiu =
        jogador.x < obstaculo.x + obstaculo.w &&
        jogador.x + jogador.w > obstaculo.x &&
        jogador.y < obstaculo.y + obstaculo.h &&
        jogador.y + jogador.h > obstaculo.y;

    if (!colidiu)
        return;

    // Jogador veio de cima
    if (yAnterior + jogador.h <= obstaculo.y)
    {
        jogador.y = obstaculo.y - jogador.h;
    }
    // Jogador veio de baixo
    else if (yAnterior >= obstaculo.y + obstaculo.h)
    {
        jogador.y = obstaculo.y + obstaculo.h;
    }
    // Jogador veio da esquerda
    else if (xAnterior + jogador.w <= obstaculo.x)
    {
        jogador.x = obstaculo.x - jogador.w;
    }
    // Jogador veio da direita
    else if (xAnterior >= obstaculo.x + obstaculo.w)
    {
        jogador.x = obstaculo.x + obstaculo.w;
    }
}

