#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "definition.h"
#include "initialize.h"
#include "present.h"
#include "game.h"

using namespace std;
//Tất cả các biến nằm ở file initialize.h, hầu hết là biến toàn cục

int main(int argc, char* argv[]) {
    srand(time(0));
    initialize();
    graphics.play(intro);

    while (!quit) {
        if (e.type == SDL_QUIT) {quit = true; break;}
        graphics.prepareScene();
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (play) {
            Mix_HaltMusic();
            graphics.renderTexture(background, 0, 0);
            update();
            gen_pipe();
            present_score();
            present_bar();
            if (pause && !mute_music) Mix_PauseMusic();
            else if (menu && !mute_music) Mix_HaltMusic();
        }

        else if (pause) {
            present_pause();
            if (play && !mute_music) Mix_ResumeMusic();
        }

        else if (settings) {
            present_settings();
        }

        else if (menu) {
            if (!mute_music) graphics.play(intro);
            present_menu();
        }

        SDL_PollEvent(&e);
        graphics.presentScene();
        SDL_Delay(15);
    }

    graphics.quit();
    ofstream fo("highscore.txt", ios::out | ios::trunc);
    fo << highpoint;
    return 0;
}
