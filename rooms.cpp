#include "character.h"
#include "rooms.h"
#include "video.h"
#include "colisao.h"

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
}

void sala::configurar_sala(TipoSala tipo, int largura, int altura) {
    // Remove as paredes e portas da configuração anterior.
    lista_paredes.clear();
    lista_porta.clear();

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
    // Desenha todas as paredes armazenadas no vetor.
    for (paredes& parede : lista_paredes) {
        desenharQuadrado(parede.usarquadrado_paredes());
    }
}

void sala::desenhar_portas() {
    // Desenha todas as portas armazenadas no vetor.
    for (porta& porta_atual : lista_porta) {
        desenharQuadrado(porta_atual.usarQuadradoPorta());
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