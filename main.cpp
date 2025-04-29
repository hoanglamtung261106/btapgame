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

    bool quit = false;
    bool upside_down = false;
    bool mini = false;
    SDL_Event e;
    int clip = 0;
    int x = 150, y = 150, point = 0;
    int xx = 1200; //xx la toa do x cua pipe

    while (!quit) {
        if (e.type == SDL_QUIT) return 0;
        graphics.prepareScene();
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (play) {
            graphics.renderTexture(background, 0, 0);
            update(graphics, clip, upside_down, mini, x, y, xx);
            gen_pipe(xx);
            present_score(point, xx);
        }

        else if (pause) {
            graphics.renderTexture(background, 0, 0);
            graphics.renderTexture(button, 264, 300);
            int mx, my;
            SDL_GetMouseState(&mx, &my);
            if (mx >= 264 && mx <= 264 + 241 && my >= 300 && my <= 400 && SDL_MOUSEBUTTONDOWN == e.type) {
                pause = false, play = true;
            }
        }

        else if (menu) {
            graphics.renderTexture(background, 0, 0);
            graphics.renderTexture(button, 264, 300);
            int mx, my;
            SDL_GetMouseState(&mx, &my);
            if (mx >= 264 && mx <= 264 + 241 && my >= 300 && my <= 400 && SDL_MOUSEBUTTONDOWN == e.type) {
                start_to_game(y, upside_down, mini, clip, xx, point), menu = false, play = true;
            }
        }

        SDL_PollEvent(&e);
        graphics.presentScene();
        SDL_Delay(15);

    }
	//SDL_DestroyTexture( manTexture ); manTexture = nullptr;
	//SDL_DestroyTexture( birdTexture ); birdTexture = nullptr;

    graphics.quit();
    return 0;
}
