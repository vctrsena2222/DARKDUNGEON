#include <iostream>
#include "audio.h"

MIX_Mixer* mixer = nullptr;

MIX_Audio* som_ataque = nullptr;
MIX_Audio* som_defesa = nullptr;
MIX_Audio* som_parry = nullptr;

bool inicializarAudio() {

    if (!MIX_Init()) {
        std::cout << "Erro ao inicializar SDL_mixer: "
            << SDL_GetError() << '\n';

        return false;
    }

    mixer = MIX_CreateMixerDevice(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
        nullptr
    );

    if (mixer == nullptr) {
        std::cout << "Erro ao criar mixer: "
            << SDL_GetError() << '\n';

        MIX_Quit();
        return false;
    }

    std::cout << "SDL_mixer inicializado com sucesso!\n";

    return true;
}

void encerrarAudio() {

    if (som_ataque != nullptr) {
        MIX_DestroyAudio(som_ataque);
        som_ataque = nullptr;
    }

    if (som_defesa != nullptr) {
        MIX_DestroyAudio(som_defesa);
        som_defesa = nullptr;
    }

    if (som_parry != nullptr) {
        MIX_DestroyAudio(som_parry);
        som_parry = nullptr;
    }

    if (mixer != nullptr) {
        MIX_DestroyMixer(mixer);
        mixer = nullptr;
    }

    MIX_Quit();
}




bool carregarEfeitosSonoros() {

    som_ataque = MIX_CreateSineWaveAudio(mixer, 1200, 0.12f, 100);
    som_defesa = MIX_CreateSineWaveAudio(mixer, 450, 0.17f, 140);
    som_parry = MIX_CreateSineWaveAudio(mixer, 1600, 0.20f, 220);

    if (som_ataque == nullptr ||
        som_defesa == nullptr ||
        som_parry == nullptr) {

        std::cout << "Erro ao criar efeitos sonoros: "
            << SDL_GetError() << '\n';

        return false;
    }

    std::cout << "Efeitos sonoros criados com sucesso!\n";

    return true;
}

void tocarSomAtaque() {
    MIX_PlayAudio(mixer, som_ataque);
}

void tocarSomDefesa() {
    MIX_PlayAudio(mixer, som_defesa);
}

void tocarSomParry() {
    MIX_PlayAudio(mixer, som_parry);
}

