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

void start_to_game(int& y, bool& upside_down, bool& mini, int& clip, int& pipe_x, int& point) {
    y = 150;
    upside_down = mini = false;
    for (int i = 0; i < 2; i++) pipes[i] = rand() % (SCREEN_HEIGHT - 200) + 200;
    for (int i = 0; i < 2; i++) state_portal[i] = rand() % 5;
    pipe_x = 1200;
    point = 0;
}
void update(Graphics& graphics, int& clip, bool& upside_down, bool& mini, int& x, int& y, int& pipe_x) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (pipe_x == 800 && state_portal[0] == 0) upside_down ^= 1;
    else if (pipe_x == 800 && state_portal[0] == 1) upside_down = true;
    else if (pipe_x == 800 && state_portal[0] == 2) upside_down = false;
    else if (pipe_x == 800 && state_portal[0] == 3) {
        mini = true;
        if (!upside_down) {
            y += 10;
            if (y % 20 != 0) y += 10;
        }
        else {
            y -= 10;
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

    //Phần code khi chim chạm vào cột
    if (currentKeyStates[SDL_SCANCODE_SPACE]) play = false, pause = true;
    if (!mini && pipe_x - 600 == 150 + 90 && (y + 80 > pipes[0] || y < pipes[0] - 200)) play = false, menu = true;
    else if (mini && pipe_x - 600 == 150 + 45 && (y + 40 > pipes[0] || y < pipes[0] - 200)) play = false, menu = true;
}

void gen_pipe(int& xx) {
    for (int i = 0; i <= 1; i++) {
        graphics.renderTexture(pipe1, xx - 600 * (1 - i), pipes[i]);
        graphics.renderTexture(pipe2, xx - 600 * (1 - i), pipes[i] - 600);
        graphics.renderTexture(portal[state_portal[i]], xx - 600 * (1 - i), pipes[i] - 195);
    }
    xx -= 5;

    if (xx - 500 < 0) {
        pipes.erase(pipes.begin());
        pipes.push_back(rand() % (SCREEN_HEIGHT - 200) / 40 * 40 + 200);

        state_portal.erase(state_portal.begin());
        state_portal.push_back(rand() % 10);
        xx += 600;
    }
}

void present_score(int& point, int& pipe_x) {
    graphics.renderTexture(score, 0, 0);
    vector<int> vpoint = conv(point);
    int d = 115;
    for (int i = 0; i < vpoint.size(); i++) graphics.renderTexture(digit[vpoint[i]], d, 0), d += space[vpoint[i]];
    if (pipe_x - 600 == 150) point++;
}

void update(Graphics& graphics) {

}
#endif // GAME_H
