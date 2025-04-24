#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 768; //Chiều rộng của screen là 800
const int SCREEN_HEIGHT = 512; //Chiều cao của screen là 600
const char* WINDOW_TITLE = "BIRD DASH"; //Tiêu đề

const char* SCORE_FONT = "score .png";
const char* DIGIT[10] = {"0.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png"};
const char* PIPE1 = "pipe1.png";
const char* PIPE2 = "pipe2.png";
const char* BACKGROUND = "background.png";
const char* BIRD_SPRITE_FILE = "83127-sprite-area-line-animated-bird-film.png"; //Chim xuôi
const int BIRD_CLIPS[][4] = { //BIRD_CLIPS[i] là một đoạn của BIRD_SPRITE_FILE, có 4 chỉ số theo thứ tự là x, y, w, h
    {0, 0, 182, 168},
    {181, 0, 182, 168},
    {364, 0, 182, 168},
    {547, 0, 182, 168},
    {728, 0, 182, 168},

    {0, 170, 182, 168},
    {181, 170, 182, 168},
    {364, 170, 182, 168},
    {547, 170, 182, 168},
    {728, 170, 182, 168},

    {0, 340, 182, 168},
    {181, 340, 182, 168},
    {364, 340, 182, 168},
    {547, 340, 182, 168},
};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS)/sizeof(int)/4; //Ảnh chim xuôi chia ra 14 cảnh

const char* BIRD2_SPRITE_FILE = "83127-sprite-area-line-animated-bird-film (2).png"; //Chim ngược
const int BIRD2_CLIPS[][4] = { //Định nghĩa tương tự cho BIRD2_SPRITE_FILE
    {0, 0, 182, 168},
    {181, 0, 182, 168},
    {364, 0, 182, 168},
    {547, 0, 182, 168},
    {728, 0, 182, 168},

    {0, 170, 182, 168},
    {181, 170, 182, 168},
    {364, 170, 182, 168},
    {547, 170, 182, 168},
    {728, 170, 182, 168},

    {0, 340, 182, 168},
    {181, 340, 182, 168},
    {364, 340, 182, 168},
    {547, 340, 182, 168},
};
const int BIRD2_FRAMES = sizeof(BIRD2_CLIPS)/sizeof(int)/4; //Ảnh chim ngược chia ra 14 cảnh

#endif
