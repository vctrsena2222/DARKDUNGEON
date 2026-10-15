#include <SDL3/SDL.h>
#include <iostream>

SDL_Window* janela;
SDL_Renderer* renderer;
const int largura = 1200;
const int altura = 800;

void criarJanela() {

	janela = SDL_CreateWindow(
		"DarkDungeon",
		largura,
		altura,
		0);
	renderer = SDL_CreateRenderer(janela, NULL);


}

void executarRenderer() {
	

	SDL_RenderPresent(renderer);

}
void desenharQuadrado(SDL_FRect& quadrado) {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderFillRect(renderer, &quadrado);
}

void redefinirRenderer() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void limparFrame() {

	SDL_RenderClear(renderer);
}