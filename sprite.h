#include <SDL.h>
#include <SDL_image.h>
#include "definition.h"
#include <bits/stdc++.h>

struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;

        SDL_Rect clip; //Clip là 1 hình chữ nhật
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0]; //x là tọa độ x
            clip.y = _clips[i][1]; //y là tọa độ y
            clip.w = _clips[i][2]; //w là width
            clip.h = _clips[i][3]; //h là height
            clips.push_back(clip);
        }
    }
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size(); //Dịch chuyển 1 đoạn
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};
