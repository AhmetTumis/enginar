#include "Sound.h"
#include <iostream>

Sound::Sound(std::string filepath) {
    if (SDL_LoadWAV(filepath.c_str(), &m_audioSpec, &m_waveStart, &m_waveLength) == nullptr) {
        std::cerr << "sound loading error: " << SDL_GetError() << std::endl;
    }
}

Sound::~Sound() {
    SDL_FreeWAV(m_waveStart);
    SDL_CloseAudioDevice(m_device);
}

void Sound::PlaySound() {
    
    int status = SDL_QueueAudio(m_device, m_waveStart, m_waveLength);
    /*int status1 = SDL_QueueAudio(0, m_waveStart, m_waveLength);
    int status2 = SDL_QueueAudio(1, m_waveStart, m_waveLength);*/
    //SDL_Delay(5000);
    SDL_PauseAudioDevice(m_device, 0);
}

void Sound::StopSound() {
    SDL_PauseAudioDevice(m_device, 1);
}

void Sound::SetupDevice() {
    //m_device = SDL_OpenAudio(2,2);
    m_device = SDL_OpenAudioDevice(nullptr, 0, &m_audioSpec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (0 == m_device) {
        std::cerr << "sound device error: " << SDL_GetError() << std::endl;
    }
    int i, count = SDL_GetNumAudioDevices(0);

    for (i = 0; i < count; ++i) {
        SDL_Log("Audio device %d: %s", i, SDL_GetAudioDeviceName(i, 0));
    }
}