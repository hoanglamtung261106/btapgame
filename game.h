#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

#include "definition.h"
#include "graphics.h"

vector<int> conv(int point) {
    if (point == 0) return {0};
    vector<int> vec;
    while (point > 0) vec.push_back(point % 10), point /= 10;
    reverse(vec.begin(), vec.end());
    return vec;
}

void start_to_game() {
    Mix_HaltMusic();
    y = 150;
    upside_down = mini = false;
    for (int i = 0; i < 2; i++) pipes[i] = rand() % (SCREEN_HEIGHT - 200) + 200;
    for (int i = 0; i < 2; i++) state_portal[i] = rand() % 5;
    pipe_x = 1200;
    point = 0;
}

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
}

void check_play() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    int mx, my; SDL_GetMouseState(&mx, &my);
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) play = false, pause = true;
    else if ((mx - SCREEN_WIDTH + 10) * (mx - SCREEN_WIDTH + 10) + (my - 10) * (my - 10) <= 100 && SDL_MOUSEBUTTONDOWN == e.type) play = false, pause = true;
    if (!mini && pipe_x - 600 == 150 + 90 && (y + 80 > pipes[0] || y < pipes[0] - 200)) play = false, graphics.play(game_over), menu = true;
    else if (mini && pipe_x - 600 == 150 + 45 && (y + 40 > pipes[0] || y < pipes[0] - 200)) play = false, graphics.play(game_over), menu = true;
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

void gen_pipe() {
    for (int i = 0; i <= 1; i++) {
        graphics.renderTexture(pipe1, pipe_x - 600 * (1 - i), pipes[i]);
        graphics.renderTexture(pipe2, pipe_x - 600 * (1 - i), pipes[i] - 600);
        graphics.renderTexture(portal[state_portal[i]], pipe_x - 600 * (1 - i), pipes[i] - 195);
    }
    pipe_x -= 5;

    if (pipe_x - 500 < 0) {
        pipes.erase(pipes.begin());
        pipes.push_back(rand() % (SCREEN_HEIGHT - 200) / 40 * 40 + 200);

        state_portal.erase(state_portal.begin());
        state_portal.push_back(rand() % 10);
        pipe_x += 600;
    }
    graphics.renderTexture(pause_button, SCREEN_WIDTH - 20, 0);
}

void present_score() {
    graphics.renderTexture(score, 0, 0);
    vector<int> vpoint = conv(point);
    int d = 115;
    for (int i = 0; i < vpoint.size(); i++) graphics.renderTexture(digit[vpoint[i]], d, 0), d += space[vpoint[i]];
    if (pipe_x - 600 == 150) point++, graphics.play(get_score);
}

void present_menu() {
    int mx, my;
    SDL_GetMouseState(&mx, &my);

    graphics.renderTexture(background, 0, 0);
    graphics.renderTexture(button, 264, 230);
    graphics.renderTexture(button, 264, 300);
    graphics.renderTexture(button, 264, 370);

    if (mx >= 290 && mx <= 480 && my >= 256 && my <= 306) graphics.renderTexture(font_play2, 335, 266);
    else graphics.renderTexture(font_play, 335, 266);
    if (mx >= 290 && mx <= 480 && my >= 326 && my <= 376) graphics.renderTexture(font_settings2, 293, 336);
    else graphics.renderTexture(font_settings, 293, 336);
    if (mx >= 290 && mx <= 480 && my >= 256 + 140 && my <= 306 + 140) graphics.renderTexture(font_quit2, 340, 406);
    else graphics.renderTexture(font_quit, 340, 406);

    graphics.renderTexture(name, 25, 30);

    if (mx >= 290 && mx <= 480 && my >= 256 && my <= 306 && SDL_MOUSEBUTTONDOWN == e.type) {
        start_to_game(), menu = false, play = true;
    }
    else if (mx >= 290 && mx <= 480 && my >= 326 && my <= 376 && SDL_MOUSEBUTTONDOWN == e.type) settings = true, menu = false;
    else if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446 && SDL_MOUSEBUTTONDOWN == e.type) quit = true;
}

void present_pause() {
    int mx, my;
    SDL_GetMouseState(&mx, &my);

    graphics.renderTexture(background, 0, 0);
    graphics.renderTexture(font_music, 25, 25);
    graphics.renderTexture(font_sound, 25, 125);
    graphics.renderTexture(button, 264, 230);
    graphics.renderTexture(button, 264, 300);
    graphics.renderTexture(button, 264, 370);
    if (mx >= 290 && mx <= 480 && my >= 256 && my <= 306) graphics.renderTexture(font_resume2, 310, 266);
    else graphics.renderTexture(font_resume, 310, 266);

    if (mx >= 290 && mx <= 480 && my >= 326 && my <= 376) graphics.renderTexture(font_replay2, 310, 336);
    else graphics.renderTexture(font_replay, 310, 336);

    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446) graphics.renderTexture(font_menu2, 332, 406);
    else graphics.renderTexture(font_menu, 332, 406);


    if (!mute_music) graphics.renderTexture(unmute_button, 400, 25);
    else graphics.renderTexture(mute_button, 400, 25);

    if (!mute_sound) graphics.renderTexture(unmute_button, 400, 125);
    else graphics.renderTexture(mute_button, 400, 125);

    if (mx >= 290 && mx <= 480 && my >= 256 && my <= 306 && SDL_MOUSEBUTTONDOWN == e.type) {
        pause = false, play = true;
    }
    if (mx >= 290 && mx <= 480 && my >= 326 && my <= 376 && SDL_MOUSEBUTTONDOWN == e.type) {
        pause = false, play = true, start_to_game();
    }
    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446 && SDL_MOUSEBUTTONDOWN == e.type) {
        pause = false, menu = true;
    }
    if ((mx - 430) * (mx - 430) + (my - 55) * (my - 55) <= 3600 && SDL_MOUSEBUTTONDOWN == e.type) mute_music ^= 1;
    if ((mx - 430) * (mx - 430) + (my - 155) * (my - 155) <= 3600 && SDL_MOUSEBUTTONDOWN == e.type) mute_sound ^= 1;
}

void present_settings() {
    graphics.renderTexture(background, 0, 0);
    graphics.renderTexture(font_music, 25, 25);
    graphics.renderTexture(font_sound, 25, 125);
    graphics.renderTexture(button, 264, 370);

    if (!mute_music) graphics.renderTexture(unmute_button, 400, 25);
    else graphics.renderTexture(mute_button, 400, 25);

    if (!mute_sound) graphics.renderTexture(unmute_button, 400, 125);
    else graphics.renderTexture(mute_button, 400, 125);

    if (!state_music) graphics.renderTexture(font_gm1, 25, 225);
    else graphics.renderTexture(font_gm2, 25, 225);
    int mx, my;
    SDL_GetMouseState(&mx, &my);

    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446) graphics.renderTexture(font_menu2, 332, 406);
    else graphics.renderTexture(font_menu, 332, 406);

    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446 && SDL_MOUSEBUTTONDOWN == e.type) menu = true, settings = false;
    if (mx >= 595 && my <= 740 && my >= 230 && my <= 280 && SDL_MOUSEBUTTONDOWN == e.type) state_music ^= 1;
    if ((mx - 430) * (mx - 430) + (my - 55) * (my - 55) <= 3600 && SDL_MOUSEBUTTONDOWN == e.type) mute_music ^= 1;
    if ((mx - 430) * (mx - 430) + (my - 155) * (my - 155) <= 3600 && SDL_MOUSEBUTTONDOWN == e.type) mute_sound ^= 1;
}
#endif // GAME_H
