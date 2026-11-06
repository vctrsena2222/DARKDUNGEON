#include "character.h"
#include "rooms.h"
#include "video.h"
#include "colisao.h"
#include <cmath>

void sala::configurar_sala1(int largura, int altura) {
    // Cria e armazena as quatro paredes da sala 1.

    paredes superior;
    superior.criar_parede(0.0f, 0.0f, static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(superior);

    paredes inferior;
    inferior.criar_parede(0.0f, static_cast<float>(altura - 20), static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(inferior);

    paredes esquerda;
    esquerda.criar_parede(0.0f, 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(esquerda);

    paredes direita;
    direita.criar_parede(static_cast<float>(largura - 20), 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(direita);

    // Porta à direita.
    porta porta_direita;
    porta_direita.criar_portas(
        static_cast<float>(largura - 40),
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );

    lista_porta.push_back(porta_direita);
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 600));
   
}

void sala::configurar_sala2(int largura, int altura) {
    // Cria e armazena as quatro paredes da sala 2.

    paredes superior;
    superior.criar_parede(0.0f, 0.0f, static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(superior);

    paredes inferior;
    inferior.criar_parede(0.0f, static_cast<float>(altura - 20), static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(inferior);

    paredes esquerda;
    esquerda.criar_parede(0.0f, 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(esquerda);

    paredes direita;
    direita.criar_parede(static_cast<float>(largura - 20), 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(direita);

    // Porta à esquerda.
    porta porta_esquerda;
    porta_esquerda.criar_portas(
        20.0f,
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );
    lista_porta.push_back(porta_esquerda);

    // Porta à direita.
    porta porta_direita;
    porta_direita.criar_portas(
        static_cast<float>(largura - 40),
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );
    lista_porta.push_back(porta_direita);
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 800));
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 600));
}

void sala::configurar_sala3(int largura, int altura) {
    // Cria e armazena as quatro paredes da sala 3.

    paredes superior;
    superior.criar_parede(0.0f, 0.0f, static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(superior);

    paredes inferior;
    inferior.criar_parede(0.0f, static_cast<float>(altura - 20), static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(inferior);

    paredes esquerda;
    esquerda.criar_parede(0.0f, 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(esquerda);

    paredes direita;
    direita.criar_parede(static_cast<float>(largura - 20), 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(direita);

    //Porta à esquerda.
    porta porta_esquerda;
    porta_esquerda.criar_portas(
        20.0f,
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );
    lista_porta.push_back(porta_esquerda);

    // Porta à direita.
    porta porta_direita;
    porta_direita.criar_portas(
        static_cast<float>(largura - 40),
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );
    lista_porta.push_back(porta_direita);
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 800));
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 600));
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 500));

    
}

void sala::configurar_sala4(int largura, int altura) {
    // Cria e armazena as quatro paredes da sala 4.

    paredes superior;
    superior.criar_parede(0.0f, 0.0f, static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(superior);

    paredes inferior;
    inferior.criar_parede(0.0f, static_cast<float>(altura - 20), static_cast<float>(largura), 20.0f);
    lista_paredes.push_back(inferior);

    paredes esquerda;
    esquerda.criar_parede(0.0f, 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(esquerda);

    paredes direita;
    direita.criar_parede(static_cast<float>(largura - 20), 0.0f, 20.0f, static_cast<float>(altura));
    lista_paredes.push_back(direita);

    // Porta à esquerda.
    porta porta_esquerda;
    porta_esquerda.criar_portas(
        20.0f,
        static_cast<float>(altura / 2 - 25),
        20.0f,
        70.0f
    );

    lista_porta.push_back(porta_esquerda);
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 800));
    lista_inimigos.push_back(std::make_unique<inimigo>(600, 600));
    lista_inimigos.push_back(std::make_unique<inimigo>(300, 500));
    lista_inimigos.push_back(std::make_unique<inimigo>(300, 700));
 
}

void sala::configurar_sala(TipoSala tipo, int largura, int altura) {
    // Remove as paredes e portas da configuração anterior.
    lista_paredes.clear();
    lista_porta.clear();
    lista_inimigos.clear();

    switch (tipo) {
    case TipoSala::sala1:
        configurar_sala1(largura, altura);
        break;

    case TipoSala::sala2:
        configurar_sala2(largura, altura);
        break;

    case TipoSala::sala3:
        configurar_sala3(largura, altura);
        break;

    case TipoSala::sala4:
        configurar_sala4(largura, altura);
        break;
    }
}

void sala::verificar_colisoes(jogador& jogador) {
    // Verifica a colisão do jogador com cada parede da sala.
    for (paredes& parede : lista_paredes) {
        colisao(
            jogador.usarquadrado(),
            parede.usarquadrado_paredes(),
            jogador.getxanterior(),
            jogador.getyanterior()
        );
    }
}

void sala::desenhar_paredes() {
    // Desenha todas as paredes
    for (paredes& parede : lista_paredes) {
        desenharParede(parede.usarquadrado_paredes());
    }
}

void sala::desenhar_portas() {
    // Desenha todas as portas 
    for (porta& porta_atual : lista_porta) {
        desenharPorta(porta_atual.usarQuadradoPorta());
    }
}

void sala::desenhar_inimigos() {
    for (auto& inimigo_atual : lista_inimigos) {
        inimigo_atual->mudanca_de_cor(renderer);
    }
}


void sala::configurar_inimigos(jogador& jogador) {
    for (auto& inimigo_atual : lista_inimigos) {
        inimigo_atual->movimentoInimigo(jogador.usarquadrado());
        inimigo_atual->posicao_hitbox_inimigo(jogador.usarquadrado());
        inimigo_atual->colisao_de_ataque(jogador.usarquadrado(), jogador);

       //a desenharQuadrado(inimigo_atual->usarquadrado_colisao());

        inimigo_atual->colisao_de_ataque(jogador.usarquadrado(), jogador);
        inimigo_atual->atacando(jogador);
    }
}
void sala::afastar_inimigos() {

    for (size_t i = 0; i < lista_inimigos.size(); i++) {
        for (size_t j = i + 1; j < lista_inimigos.size(); j++) {

            SDL_FRect& inimigo1 = lista_inimigos[i]->usarquadrado();
            SDL_FRect& inimigo2 = lista_inimigos[j]->usarquadrado();

            float dx = (inimigo1.x + inimigo1.w / 2) -
                (inimigo2.x + inimigo2.w / 2);

            float dy = (inimigo1.y + inimigo1.h / 2) -
                (inimigo2.y + inimigo2.h / 2);

            if (std::abs(dx) < 50 && std::abs(dy) < 50) {

                if (dx == 0) dx = 1;
                if (dy == 0) dy = 1;

                float movimentoX = (dx > 0) ? 1.0f : -1.0f;
                float movimentoY = (dy > 0) ? 1.0f : -1.0f;

                inimigo1.x += movimentoX;
                inimigo1.y += movimentoY;

                inimigo2.x -= movimentoX;
                inimigo2.y -= movimentoY;
            }
        }
    }
}

void sala::aplicar_ataque(jogador& jogador) {
    for (auto& inimigo_atual : lista_inimigos) {
        inimigo_atual->inimigo_recebe_dano(
            true,
            jogador.usarquadrado_colisao()
        );
    }
}
void sala::matar_inimigos() {

    for (auto it = lista_inimigos.begin(); it != lista_inimigos.end();) {

        if ((*it)->get_vida() <= 0) {
            it = lista_inimigos.erase(it);
        }
        else {
            ++it;
        }
    }
}
void sala::transicao_de_sala(jogador& jogador, TipoSala& tipo, int largura, int altura) {

    for (porta& porta_atual : lista_porta) {

        if (colisao_porta(
            jogador.usarquadrado(),
            porta_atual.usarQuadradoPorta()
        )) {

            switch (tipo) {

            case TipoSala::sala1:
                tipo = TipoSala::sala2;
                jogador.usarquadrado().x = 30.0f;
                jogador.usarquadrado().y = 600.0f;
                break;

            case TipoSala::sala2:
                if (porta_atual.usarQuadradoPorta().x < largura / 2) {
                    tipo = TipoSala::sala1;
                    jogador.usarquadrado().x = static_cast<float>(largura - 50);
                    jogador.usarquadrado().y = 300.0f;
                }
                else {
                    tipo = TipoSala::sala3;
                    jogador.usarquadrado().x = 30.0f;
                    jogador.usarquadrado().y = 300.0f;
                }
                break;

            case TipoSala::sala3:
                if (porta_atual.usarQuadradoPorta().x < largura / 2) {
                    tipo = TipoSala::sala2;
                    jogador.usarquadrado().x = static_cast<float>(largura - 50);
                    jogador.usarquadrado().y = 300.0f;
                }
                else {
                    tipo = TipoSala::sala4;
                    jogador.usarquadrado().x = 30.0f;
                    jogador.usarquadrado().y = 300.0f;
                }
                break;

            case TipoSala::sala4:
                tipo = TipoSala::sala3;
                jogador.usarquadrado().x = static_cast<float>(largura - 50);
                jogador.usarquadrado().y = 300.0f;
                break;
            }

            jogador.atualizar_posicao_anterior();

            configurar_sala(tipo, largura, altura);

            break;
        }
    }
}