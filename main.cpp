#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "definition.h"
#include "initialize.h"
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));
    initialize();

    while (!quit) {
        if (e.type == SDL_QUIT) return 0;
        graphics.prepareScene();
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (play) {
            graphics.renderTexture(background, 0, 0);
            update();
            gen_pipe();
            present_score();
        }
        else if (pause) present_pause();
        else if (menu) present_menu();

        SDL_PollEvent(&e);
        graphics.presentScene();
        SDL_Delay(15);

    }

    graphics.quit();
    return 0;
}
