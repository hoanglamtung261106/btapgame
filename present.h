#ifndef PRESENT_H
#define PRESENT_H

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
    mul_ten = 1;
    time_secret = time_shield = -1;
}

void present_gameover() {
    highpoint = max(point, highpoint);
    graphics.prepareScene();
    while (y <= 1000) {
        graphics.prepareScene();
        graphics.renderTexture(background, 0, 0);
        for (int i = 0; i <= 1; i++) {
            graphics.renderTexture(pipe1, pipe_x - 600 * (1 - i), pipes[i]);
            graphics.renderTexture(pipe2, pipe_x - 600 * (1 - i), pipes[i] - 600);
            if (state_portal[i] <= 4) graphics.renderTexture(portal[state_portal[i]], pipe_x - 600 * (1 - i), pipes[i] - 195);
            else if (state_portal[i] >= 5 && state_portal[i] <= 8) {
                if (i == 0 && !mini && pipe_x - 600 > 240) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
                else if (i == 0 && mini && pipe_x - 600 > 195) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
                else if (i == 1) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
            }
        }
        graphics.renderTexture(pause_button, SCREEN_WIDTH - 20, 0);

        if (!upside_down && !mini) graphics.renderTexture(bird1[clip], x, y);
        else if (upside_down && !mini) graphics.renderTexture(bird2[clip], x, y);
        else if (!upside_down && mini) graphics.renderTexture(bird3[clip], x + 22, y);
        else if (upside_down && mini) graphics.renderTexture(bird4[clip], x + 22, y);

        graphics.renderTexture(score, 300, 0);
        vector<int> vpoint = conv(point);

        int d = 115 + 300;
        for (int i = 0; i < vpoint.size(); i++) graphics.renderTexture(digit[vpoint[i]], d, 0), d += space[vpoint[i]];

        if (mul_ten == 5) graphics.renderTexture(add5, d + 10, 0);

        y += 40;
        SDL_PollEvent(&e);
        graphics.presentScene();
        SDL_Delay(5);
    }
    start_to_game();
    SDL_Delay(1000);
}

void gen_pipe() {
    for (int i = 0; i <= 1; i++) {
        if (!touch[i]) graphics.renderTexture(pipe1, pipe_x - 600 * (1 - i), pipes[i]);
        if (!touch[i]) graphics.renderTexture(pipe2, pipe_x - 600 * (1 - i), pipes[i] - 600);
        if (!touch[i] && state_portal[i] <= 4) graphics.renderTexture(portal[state_portal[i]], pipe_x - 600 * (1 - i), pipes[i] - 195);
        else if (!touch[i] && state_portal[i] >= 5 && state_portal[i] <= 8) {
            if (i == 0 && !mini && pipe_x - 600 > 240) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
            else if (i == 0 && mini && pipe_x - 600 > 195) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
            else if (i == 1) graphics.renderTexture(portal[5], pipe_x - 600 * (1 - i), pipes[i] - 150);
        }
    }

    if (time_shield > 0) {
        if (!mini) graphics.renderTexture(round_shield1, x - 10, y - 15);
        else graphics.renderTexture(round_shield2, x + 22 - 5, y - 7);
    }

    if (pipe_x - 500 < 0) {
        pipes.erase(pipes.begin());
        pipes.push_back(rand() % (SCREEN_HEIGHT - 200) / 40 * 40 + 200);

        state_portal.erase(state_portal.begin());
        state_portal.push_back(rand() % 20);
        pipe_x += 600;
        touch[0] = touch[1] = false;
    }
    graphics.renderTexture(pause_button, SCREEN_WIDTH - 20, 0);
}

void present_score() {
    graphics.renderTexture(score, 300, 0);

    if (pipe_x - 600 == 150) {
        if (!mute_sound && !touch[0]) {
            if (state_portal[0] == 5) graphics.play(get_secret);
            else if (state_portal[0] == 6) graphics.play(bad);
            else if (state_portal[0] == 7) graphics.play(good);
            else if (state_portal[0] == 8) graphics.play(shield);
            else graphics.play(get_score);
        }
        if (state_portal[0] != 6 && state_portal[0] != 7) point += mul_ten;
    }

    pipe_x -= 5;

    if (time_secret == 0 || time_shield == 0) {
        if (!mute_sound) graphics.play(off);
    }
    time_secret -= 15;
    time_shield -= 15;
    if (time_secret < 0) time_secret = -1, mul_ten = 1;
    if (time_shield < 0) time_shield = -1;

    vector<int> vpoint = conv(point);

    int d = 115 + 300;
    for (int i = 0; i < vpoint.size(); i++) graphics.renderTexture(digit[vpoint[i]], d, 0), d += space[vpoint[i]];

    if (mul_ten == 5) graphics.renderTexture(add5, d + 10, 0);
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

    vector<int> vpoint = conv(highpoint);
    graphics.renderTexture(highscore, 240, 180);
    int d = 240 + 259;
    for (int i = 0; i < vpoint.size(); i++) graphics.renderTexture(digit[vpoint[i]], d, 180), d += space[vpoint[i]];

    if (mx >= 290 && mx <= 480 && my >= 256 && my <= 306 && SDL_MOUSEBUTTONDOWN == e.type) {
        Mix_HaltChannel(-1), start_to_game(), menu = false, play = true;
    }
    else if (mx >= 290 && mx <= 480 && my >= 326 && my <= 376 && SDL_MOUSEBUTTONDOWN == e.type) Mix_HaltChannel(-1), settings = true, menu = false;
    else if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446 && SDL_MOUSEBUTTONDOWN == e.type) Mix_HaltChannel(-1), quit = true;
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
    if ((mx - 430) * (mx - 430) + (my - 55) * (my - 55) <= 900 && SDL_MOUSEBUTTONDOWN == e.type) mute_music ^= 1;
    if ((mx - 430) * (mx - 430) + (my - 155) * (my - 155) <= 900 && SDL_MOUSEBUTTONDOWN == e.type) mute_sound ^= 1;
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

    int mx, my;
    SDL_GetMouseState(&mx, &my);

    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446) graphics.renderTexture(font_menu2, 332, 406);
    else graphics.renderTexture(font_menu, 332, 406);

    if (mx >= 290 && mx <= 480 && my >= 396 && my <= 446 && SDL_MOUSEBUTTONDOWN == e.type) menu = true, settings = false;
    if ((mx - 430) * (mx - 430) + (my - 55) * (my - 55) <= 900 && SDL_MOUSEBUTTONDOWN == e.type) mute_music ^= 1;
    if ((mx - 430) * (mx - 430) + (my - 155) * (my - 155) <= 900 && SDL_MOUSEBUTTONDOWN == e.type) mute_sound ^= 1;
    if (mute_music) Mix_HaltMusic();
}

void present_bar() {
    if (time_secret > 0 && time_shield <= 0) {
        graphics.renderTexture(add5, SCREEN_WIDTH - 370, SCREEN_HEIGHT - 32);
        graphics.drawSomething(SCREEN_WIDTH - 310, SCREEN_HEIGHT - 30, time_secret);
    }
    else if (time_shield > 0 && time_secret <= 0) {
        graphics.renderTexture(shield_icon, SCREEN_WIDTH - 350, SCREEN_HEIGHT - 35);
        graphics.drawSomething(SCREEN_WIDTH - 310, SCREEN_HEIGHT - 30, time_shield);
    }
    else if (time_shield > 0 && time_secret > 0) {
        graphics.renderTexture(add5, SCREEN_WIDTH - 370, SCREEN_HEIGHT - 62);
        graphics.drawSomething(SCREEN_WIDTH - 310, SCREEN_HEIGHT - 30, time_shield);
        graphics.renderTexture(shield_icon, SCREEN_WIDTH - 350, SCREEN_HEIGHT - 35);
        graphics.drawSomething(SCREEN_WIDTH - 310, SCREEN_HEIGHT - 60, time_secret);
    }
}

#endif
