#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "definition.h"
#include "initialize.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
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

        else if (pause) {
            graphics.renderTexture(background, 0, 0);
            graphics.renderTexture(button, 264, 300);
            graphics.renderTexture(font_resume, 310, 336);
            int mx, my;
            SDL_GetMouseState(&mx, &my);
            if (mx >= 264 && mx <= 264 + 241 && my >= 300 && my <= 400 && SDL_MOUSEBUTTONDOWN == e.type) {
                pause = false, play = true;
            }
        }

        else if (menu) present_menu();

        SDL_PollEvent(&e);
        graphics.presentScene();
        SDL_Delay(15);

    }
	//SDL_DestroyTexture( manTexture ); manTexture = nullptr;
	//SDL_DestroyTexture( birdTexture ); birdTexture = nullptr;

    graphics.quit();
    return 0;
}
