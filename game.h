#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

#include "definition.h"
#include "graphics.h"
#include "present.h"

void change_bird() {
    if (pipe_x == 800 && state_portal[0] == 0) upside_down ^= 1;
    else if (pipe_x == 800 && state_portal[0] == 1) upside_down = true;
    else if (pipe_x == 800 && state_portal[0] == 2) upside_down = false;
    else if (pipe_x == 800 && state_portal[0] == 3) {
        mini = true;
        if (!upside_down) {
            y += 10;
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x && y + 40 > pipes[0]) y -= 10;
            if (y % 20 != 0) y += 10;
        }
        else {
            y -= 10;
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x && y < pipes[0] - 200) y -= 10;
            if (y % 20 != 0) y -= 10;
        }
    }
    else if (pipe_x == 800 && state_portal[0] == 4) {
        mini = false;
        if (!upside_down) {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y == pipes[0] - 200);
                else if (y + 40 == pipes[0]) y -= 20;
                else y -= 10;
            }
            else y -= 10;
        }
        else {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y == pipes[0] - 200) y += 20;
                else if (y + 40 == pipes[0]);
                else y += 10;
            }
            else y += 10;
        }
    }
    else if (state_portal[0] == 5 && time_secret == -1) {
        if (!mini) {
            if (pipe_x - 600 == 240) mul_ten = 5;
        }
        else if (mini) {
            if (pipe_x - 600 == 195) mul_ten = 5;
        }
        if (mul_ten == 5) time_secret = 20000;
    }

    else if (state_portal[0] == 6 && time_secret == -1) {
        if (!mini) {
            if (pipe_x - 600 == 240) point = max(point - 20, 0);
        }
        else if (mini) {
            if (pipe_x - 600 == 195) point = max(point - 20, 0);
        }
    }

    else if (state_portal[0] == 7 && time_secret == -1) {
        if (!mini) {
            if (pipe_x - 600 == 240 && y + 80 >= pipes[0] - 150 && y <= pipes[0] - 50) point += 20;
        }
        else if (mini) {
            if (pipe_x - 600 == 195 && y + 40 >= pipes[0] - 150 && y <= pipes[0] - 50) point += 20;
        }
    }
}

void check_play() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    int mx, my; SDL_GetMouseState(&mx, &my);
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) play = false, pause = true;
    else if ((mx - SCREEN_WIDTH + 10) * (mx - SCREEN_WIDTH + 10) + (my - 10) * (my - 10) <= 100 && SDL_MOUSEBUTTONDOWN == e.type) play = false, pause = true;
    if (!mini && pipe_x - 600 == 150 + 90 && (y + 80 > pipes[0] || y < pipes[0] - 200)) graphics.play(game_over), present_gameover();
    else if (mini && pipe_x - 600 == 150 + 45 && (y + 40 > pipes[0] || y < pipes[0] - 200)) graphics.play(game_over), present_gameover();
}

void update() {
    change_bird();

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (!upside_down && !mini) /*Xuôi và to*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y >= 10) {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y > pipes[0] - 200) y -= 10;
            }
            else y -= 10;
        }
        else if (currentKeyStates[SDL_SCANCODE_UP]);
        else if (y <= SCREEN_HEIGHT - 90) {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y + 80 < pipes[0]) y += 10;
            }
            else y += 10;
        }
        graphics.renderTexture(bird1[clip], x, y);
    }

    else if (upside_down && !mini) /*Ngược và to*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y <= SCREEN_HEIGHT - 90) {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y + 80 < pipes[0]) y += 10;
            }
            else y += 10;
        }
        else if (currentKeyStates[SDL_SCANCODE_UP]);
        else if (y >= 10) {
            if (pipe_x - 600 < x + 90 && pipe_x - 600 + 100 > x) {
                if (y > pipes[0] - 200) y -= 10;
            }
            else y -= 10;
        }
        graphics.renderTexture(bird2[clip], x, y);
    }

    else if (!upside_down && mini) /*Xuôi và nhỏ*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y >= 20) {
            if (pipe_x - 600 < x + 22 + 45 && pipe_x - 600 + 100 > x + 22) {
                if (y > pipes[0] - 200) y -= 20;
            }
            else y -= 20;
        }
        else if (currentKeyStates[SDL_SCANCODE_UP]);
        else if (y <= SCREEN_HEIGHT - 60) {
            if (pipe_x - 600 < x + 22 + 45 && pipe_x - 600 + 100 > x + 22) {
                if (y + 40 < pipes[0]) y += 20;
            }
            else y += 20;
        }
        graphics.renderTexture(bird3[clip], x + 22, y);
    }

    else if (upside_down && mini) /*Ngược và nhỏ*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y <= SCREEN_HEIGHT - 60) {
            if (pipe_x - 600 < x + 22 + 45 && pipe_x - 600 + 100 > x + 22) {
                if (y + 40 < pipes[0]) y += 20;
            }
            else y += 20;
        }
        else if (currentKeyStates[SDL_SCANCODE_UP]);
        else if (y >= 20) {
            if (pipe_x - 600 < x + 22 + 45 && pipe_x - 600 + 100 > x + 22) {
                if (y > pipes[0] - 200) y -= 20;
            }
            else y -= 20;
        }
        graphics.renderTexture(bird4[clip], x + 22, y);
    }

    clip = (clip + 1) % 4; //Update 1 đoạn mới cho 2 loại chim (14 đoạn tất cả)

    check_play();
}

#endif // GAME_H
