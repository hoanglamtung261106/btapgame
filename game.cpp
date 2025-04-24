#include <SDL.h>
#include <stdio.h>
#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Mouse Button Down",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            std::cout << event.type << "\n";
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    std::cout << event.type << "!\n";
                    printf("Mouse button pressed: ");
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        printf("Left button\n");
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        printf("Right button\n");
                    } else if (event.button.button == SDL_BUTTON_MIDDLE) {
                        printf("Middle button\n");
                    } else {
                        printf("Other button\n");
                    }
                    printf("At position (%d, %d)\n", event.button.x, event.button.y);
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
