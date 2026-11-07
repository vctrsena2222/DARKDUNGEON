
#pragma once
#include <SDL3_mixer/SDL_mixer.h>

// Inicialização e encerramento do áudio.
bool inicializarAudio();
void encerrarAudio();

// Carregamento dos efeitos sonoros.
bool carregarEfeitosSonoros();

// Reprodução dos efeitos.
void tocarSomAtaque();
void tocarSomDefesa();
void tocarSomParry();