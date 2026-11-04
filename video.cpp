#include <SDL3/SDL.h>
#include <iostream>
#include <SDL3_image/SDL_image.h>
#include "video.h"

SDL_Window* janela;
SDL_Renderer* renderer;

SDL_Texture* textura_jogador = nullptr;
SDL_Texture* textura_jogador_andando = nullptr;
SDL_Texture* textura_jogador_defendendo = nullptr;
SDL_Texture* textura_jogador_atacando = nullptr;

// Texturas do Orc.
SDL_Texture* textura_orc_parado = nullptr;
SDL_Texture* textura_orc_andando = nullptr;
SDL_Texture* textura_orc_atacando = nullptr;

int frame_atual = 0;
Uint64 tempo_ultimo_frame = 0;

extern const int largura = 1200;
extern const int altura = 800;


bool carregarTextura_jogador_parado() {

    textura_jogador = IMG_LoadTexture(
        renderer,
        "assets/character/soldier/Soldier_Idle.png"
    );

    if (textura_jogador == nullptr) {
        std::cout << "Erro ao carregar textura: "
            << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

bool carregarTextura_jogador_andar() {

    textura_jogador_andando = IMG_LoadTexture(
        renderer,
        "assets/character/soldier/Soldier_Walk.png"
    );

    if (textura_jogador_andando == nullptr) {
        std::cout << "Erro ao carregar walk: "
            << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

bool carregarTextura_jogador_defesa() {

    textura_jogador_defendendo = IMG_LoadTexture(
        renderer,
        "assets/character/soldier/Soldier_Attack01.png"
    );

    if (textura_jogador_defendendo == nullptr) {
        std::cout << "Erro ao carregar defesa: "
            << SDL_GetError() << '\n';
        return false;
    }

    return true;
}

bool carregarTextura_jogador_ataque() {

    textura_jogador_atacando = IMG_LoadTexture(
        renderer,
        "assets/character/soldier/Soldier_Attack01.png"
    );

    if (textura_jogador_atacando == nullptr) {
        std::cout << "Erro ao carregar textura de ataque: "
            << SDL_GetError() << '\n';

        return false;
    }

    return true;
}


// Carregamento das texturas do Orc.

bool carregarTexturaOrc(SDL_Texture*& textura, const char* caminho) {

    textura = IMG_LoadTexture(renderer, caminho);

    if (textura == nullptr) {
        std::cout << "Erro ao carregar textura do Orc: "
            << caminho << " | "
            << SDL_GetError() << '\n';

        return false;
    }

    return true;
}

bool carregarTexturas_inimigo() {

    bool idle = carregarTexturaOrc(
        textura_orc_parado,
        "assets/Orc/Orc with shadows/Orc_Idle.png"
    );

    bool walk = carregarTexturaOrc(
        textura_orc_andando,
        "assets/Orc/Orc with shadows/Orc_Walk.png"
    );

    bool attack = carregarTexturaOrc(
        textura_orc_atacando,
        "assets/Orc/Orc with shadows/Orc_Attack01.png"
    );

    return idle && walk && attack;
}


void criarJanela() {

    janela = SDL_CreateWindow(
        "DarkDungeon",
        largura,
        altura,
        0
    );

    renderer = SDL_CreateRenderer(janela, NULL);

    if (!carregarTextura_jogador_parado()) {
        std::cout << "Falha na inicializacao da textura do jogador.\n";
    }

    if (!carregarTextura_jogador_andar()) {
        std::cout << "Falha na inicializacao da textura Walk.\n";
    }

    if (!carregarTextura_jogador_defesa()) {
        std::cout << "Falha ao carregar textura de defesa.\n";
    }

    if (!carregarTextura_jogador_ataque()) {
        std::cout << "Falha ao carregar textura de ataque.\n";
    }

    if (!carregarTexturas_inimigo()) {
        std::cout << "Falha ao carregar uma ou mais texturas do Orc.\n";
    }
}


void desenhoJogador(SDL_FRect& destino, bool olhando_esquerda) {

    SDL_FRect src{ 0, 0, 100, 100 };

    SDL_FRect tamanho{
        destino.x - 95,
        destino.y - 90,
        destino.w * 5,
        destino.h * 5
    };

    SDL_RenderTextureRotated(
        renderer,
        textura_jogador,
        &src,
        &tamanho,
        0,
        nullptr,
        olhando_esquerda ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE
    );
}


void desenhoJogador_andando(SDL_FRect& destino, bool olhando_esquerda) {

    Uint64 tempo_atual = SDL_GetTicks();

    if (tempo_atual - tempo_ultimo_frame >= 100) {
        frame_atual++;

        if (frame_atual >= 8) {
            frame_atual = 0;
        }

        tempo_ultimo_frame = tempo_atual;
    }

    SDL_FRect src{
        static_cast<float>(frame_atual * 100),
        0,
        100,
        100
    };

    SDL_FRect tamanho{
        destino.x - 95,
        destino.y - 90,
        destino.w * 5,
        destino.h * 5
    };

    SDL_RenderTextureRotated(
        renderer,
        textura_jogador_andando,
        &src,
        &tamanho,
        0,
        nullptr,
        olhando_esquerda ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE
    );
}


void desenhoJogador_defendendo(
    SDL_FRect& destino,
    bool olhando_esquerda,
    Uint64 inicio_defesa
) {

    Uint64 tempo_atual = SDL_GetTicks();
    Uint64 tempo_decorrido = tempo_atual - inicio_defesa;

    int frame_defesa = static_cast<int>(tempo_decorrido / 40);

    if (frame_defesa > 2) {
        frame_defesa = 2;
    }

    SDL_FRect src{
        static_cast<float>(frame_defesa * 100),
        0,
        100,
        100
    };

    SDL_FRect tamanho{
        destino.x - 95,
        destino.y - 90,
        destino.w * 5,
        destino.h * 5
    };

    SDL_RenderTextureRotated(
        renderer,
        textura_jogador_defendendo,
        &src,
        &tamanho,
        0,
        nullptr,
        olhando_esquerda ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE
    );
}


void desenhoJogador_atacando(
    SDL_FRect& destino,
    bool olhando_esquerda,
    Uint64 inicio_ataque
) {

    Uint64 tempo_atual = SDL_GetTicks();
    Uint64 tempo_decorrido = tempo_atual - inicio_ataque;

    int frame_ataque = static_cast<int>(tempo_decorrido / 60);

    if (frame_ataque >= 6) {
        frame_ataque = 5;
    }

    SDL_FRect src{
        static_cast<float>(frame_ataque * 100),
        0,
        100,
        100
    };

    SDL_FRect tamanho{
        destino.x - 95,
        destino.y - 90,
        destino.w * 5,
        destino.h * 5
    };

    SDL_RenderTextureRotated(
        renderer,
        textura_jogador_atacando,
        &src,
        &tamanho,
        0,
        nullptr,
        olhando_esquerda ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE
    );
}


// Desenho das animações do Orc.

bool desenhoInimigo(
    SDL_Renderer* renderer,
    SDL_FRect& destino,
    bool olhando_esquerda,
    int frame,
    AnimacaoOrc animacao,
    bool vermelho
) {

    SDL_Texture* textura = nullptr;

    switch (animacao) {

    case AnimacaoOrc::parado:
        textura = textura_orc_parado;
        break;

    case AnimacaoOrc::andando:
        textura = textura_orc_andando;
        break;

    case AnimacaoOrc::atacando:
        textura = textura_orc_atacando;
        break;
    }

    if (textura == nullptr) {
        return false;
    }

    // Restaura a cor original antes de desenhar.
    SDL_SetTextureColorMod(textura, 255, 255, 255);

    // Aplica a tonalidade vermelha durante a preparação do ataque.
    if (vermelho) {

        if (!SDL_SetTextureColorMod(textura, 255, 0, 0)) {
            return false;
        }
    }

    SDL_FRect src{
        static_cast<float>(frame * 100),
        0,
        100,
        100
    };

    SDL_FRect tamanho{
        destino.x - 95,
        destino.y - 90,
        destino.w * 5,
        destino.h * 5
    };

    bool sucesso = SDL_RenderTextureRotated(
        renderer,
        textura,
        &src,
        &tamanho,
        0,
        nullptr,
        olhando_esquerda ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE
    );

    // Impede que a tonalidade vermelha passe para outros inimigos.
    SDL_SetTextureColorMod(textura, 255, 255, 255);

    return sucesso;
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