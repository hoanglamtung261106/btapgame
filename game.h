#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

#include "definition.h"
#include "graphics.h"
#include "present.h"

void change_bird() {
    if (pipe_x == 800 && state_portal[0] == 0 && !touch[0]) upside_down ^= 1;
    else if (pipe_x == 800 && state_portal[0] == 1 && !touch[0]) upside_down = true;
    else if (pipe_x == 800 && state_portal[0] == 2 && !touch[0]) upside_down = false;
    else if (pipe_x - 600 == 150 && state_portal[0] == 3 && !mini && !touch[0]) {
        mini = true;
        if (!upside_down && y % 20 != 0) y += 10;
        else if (!upside_down) y += 20;
        else if (upside_down && y % 20 != 0) y -= 10;
        else if (upside_down) y -= 20;
    }
    else if (pipe_x - 600 == 195 && state_portal[0] == 4 && mini && !touch[0]) {
        mini = false;
        if (!upside_down) {
            if (y + 40 == pipes[0]) y -= 40;
            else if (y == pipes[0] - 200) y = y;
            else if (y - 10 >= pipes[0] - 200) y -= 20;
        }
        else if (upside_down) {
            if (y == pipes[0] - 200) y = y;
            else if (y + 40 == pipes[0]) y -= 40;
            else y -= 20;
        }
    }
    else if (state_portal[0] == 5 && !touch[0]) {
        if (!mini) {
            if (pipe_x - 600 == 240 && y >= pipes[0] - 200 && y + 80 <= pipes[0]) mul_ten = 5, time_secret = 30000;
        }
        else if (mini) {
            if (pipe_x - 600 == 195 && y >= pipes[0] - 200 && y + 40 <= pipes[0]) mul_ten = 5, time_secret = 30000;
        }
    }

    else if (state_portal[0] == 6 && !touch[0]) {
        if (!mini) {
            if (pipe_x - 600 == 240 && y >= pipes[0] - 200 && y + 80 <= pipes[0]) point = max(point - 10, 0);
        }
        else if (mini) {
            if (pipe_x - 600 == 195 && y >= pipes[0] - 200 && y + 40 <= pipes[0]) point = max(point - 10, 0);
        }
    }

    else if (state_portal[0] == 7 && !touch[0]) {
        if (!mini) {
            if (pipe_x - 600 == 240 && y >= pipes[0] - 200 && y + 80 <= pipes[0]) point += 10;
        }
        else if (mini) {
            if (pipe_x - 600 == 195 && y >= pipes[0] - 200 && y + 40 <= pipes[0]) point += 10;
        }
    }

    else if (state_portal[0] == 8 && !touch[0]) {
        if (!mini) {
            if (pipe_x - 600 == 240 && y >= pipes[0] - 200 && y + 80 <= pipes[0]) time_shield = 30000;
        }
        else if (mini) {
            if (pipe_x - 600 == 195 && y >= pipes[0] - 200 && y + 40 <= pipes[0]) time_shield = 30000;
        }
    }
}

void check_play() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    int mx, my; SDL_GetMouseState(&mx, &my);
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) play = false, pause = true;
    else if ((mx - SCREEN_WIDTH + 10) * (mx - SCREEN_WIDTH + 10) + (my - 10) * (my - 10) <= 100 && SDL_MOUSEBUTTONDOWN == e.type) play = false, pause = true;
    if (time_shield <= 0 && !mini && pipe_x - 600 == 150 + 90 && (y + 80 > pipes[0] || y < pipes[0] - 200)) {
        if (!mute_sound) graphics.play(game_over);
        present_gameover();
    }
    else if (time_shield <= 0 && mini && pipe_x - 600 == 150 + 45 && (y + 40 > pipes[0] || y < pipes[0] - 200)) {
        if (!mute_sound) graphics.play(game_over);
        present_gameover();
    }
    else if (time_shield > 0 && !mini && pipe_x - 600 == 240 && (y + 80 > pipes[0] || y < pipes[0] - 200)) time_shield = 0, touch[0] = true;
    else if (time_shield > 0 && mini && pipe_x - 600 == 195 && (y + 40 > pipes[0] || y < pipes[0] - 200)) time_shield = 0, touch[0] = true;
}

void update() {
    change_bird();

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (!upside_down && !mini) /*Xuôi và to*/ {
        if (!touch[0]) {
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
        }
        else {
            if (currentKeyStates[SDL_SCANCODE_UP] && y >= 10) y -= 10;
            else if (currentKeyStates[SDL_SCANCODE_UP]);
            else if (y <= SCREEN_HEIGHT - 90) y += 10;
        }
        graphics.renderTexture(bird1[clip], x, y);
    }

    else if (upside_down && !mini) /*Ngược và to*/ {
        if (!touch[0]) {
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
        }
        else {
            if (currentKeyStates[SDL_SCANCODE_UP] && y <= SCREEN_HEIGHT - 90) y += 10;
            else if (currentKeyStates[SDL_SCANCODE_UP]);
            else if (y >= 10) y -= 10;
        }
        graphics.renderTexture(bird2[clip], x, y);
    }

    else if (!upside_down && mini) /*Xuôi và nhỏ*/ {
        if (!touch[0]) {
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
        }
        else {
            if (currentKeyStates[SDL_SCANCODE_UP] && y >= 20) y -= 20;
            else if (currentKeyStates[SDL_SCANCODE_UP]);
            else if (y <= SCREEN_HEIGHT - 60) y += 20;
        }
        graphics.renderTexture(bird3[clip], x + 22, y);
    }

    else if (upside_down && mini) /*Ngược và nhỏ*/ {
        if (!touch[0]) {
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
        }
        else {
            if (currentKeyStates[SDL_SCANCODE_UP] && y <= SCREEN_HEIGHT - 60) y += 20;
            else if (currentKeyStates[SDL_SCANCODE_UP]);
            else if (y >= 20) y -= 20;
        }
        graphics.renderTexture(bird4[clip], x + 22, y);
    }

    clip = (clip + 1) % 4; //Update 1 đoạn mới cho 2 loại chim (14 đoạn tất cả)

    check_play();
}

#endif // GAME_H
