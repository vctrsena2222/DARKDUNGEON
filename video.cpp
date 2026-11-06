#include <SDL3/SDL.h>
#include <iostream>
#include <SDL3_image/SDL_image.h>
#include <algorithm>
#include "video.h"

SDL_Window* janela;
SDL_Renderer* renderer;
 //texturas do jogador
SDL_Texture* textura_jogador = nullptr;
SDL_Texture* textura_jogador_andando = nullptr;
SDL_Texture* textura_jogador_defendendo = nullptr;
SDL_Texture* textura_jogador_atacando = nullptr;

// Texturas do Orc.
SDL_Texture* textura_orc_parado = nullptr;
SDL_Texture* textura_orc_andando = nullptr;
SDL_Texture* textura_orc_atacando = nullptr;

//  texturas do cenario
SDL_Texture* textura_cenario = nullptr;
int frame_atual = 0;
Uint64 tempo_ultimo_frame = 0;

extern const int largura = 1200;
extern const int altura = 800;

bool carregarTexturaCenario() {

    textura_cenario = IMG_LoadTexture(
        renderer,
        "assets/cenario/Dungeon_Tileset.png"
    );

    if (textura_cenario == nullptr) {
        std::cout << "Erro ao carregar cenario: "
            << SDL_GetError() << '\n';

        return false;
    }

    return true;
}
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

//funções da janela 
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
    if (!carregarTexturaCenario()) {
        std::cout << "Falha ao carregar textura do cenario.\n";
    }
}
//função do cenario

void desenharCenario() {

    SDL_FRect src{ 0, 96, 64, 32 };

    for (int y = 0; y < altura; y += 32) {
        for (int x = 0; x < largura; x += 64) {

            SDL_FRect destino{
                static_cast<float>(x),
                static_cast<float>(y),
                64.0f,
                32.0f
            };

            SDL_RenderTexture(
                renderer,
                textura_cenario,
                &src,
                &destino
            );
        }
    }
}
void desenharParede(SDL_FRect& destino) {

    if (textura_cenario == nullptr || renderer == nullptr)
        return;

    // Parede horizontal
    if (destino.w >= destino.h) {

        float x = destino.x;
        float limite = destino.x + destino.w;

        while (x < limite) {

            float largura = std::min(64.0f, limite - x);

            SDL_FRect src{ 16, 64, largura, 16 };

            SDL_FRect dst{
                x,
                destino.y,
                largura,
                destino.h
            };

            SDL_RenderTexture(renderer, textura_cenario, &src, &dst);

            x += largura;
        }
    }

    // Parede vertical
    else {

        float y = destino.y;
        float limite = destino.y + destino.h;

        while (y < limite) {

            float altura = std::min(48.0f, limite - y);

            SDL_FRect src{ 0, 16, 16, altura };

            SDL_FRect dst{
                destino.x,
                y,
                destino.w,
                altura
            };

            SDL_RenderTexture(renderer, textura_cenario, &src, &dst);

            y += altura;
        }
    }
}

void desenharPorta(SDL_FRect& destino) {

    if (textura_cenario == nullptr || renderer == nullptr)
        return;

    SDL_FRect src{ 136, 72, 8, 24 };
  
    float escala = std::min(
        destino.w / src.w,
        destino.h / src.h
    );

    SDL_FRect dst{
        destino.x + (destino.w - src.w * escala) / 2.0f,
        destino.y + (destino.h - src.h * escala) / 2.0f,
        src.w * escala,
        src.h * escala
    };

    SDL_RenderTexture(renderer, textura_cenario, &src, &dst);
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

    // Aplica a cor vermelho durante a preparação do ataque nos momentos certos
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