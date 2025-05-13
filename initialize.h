#include "graphics.h"
#include "definition.h"

Graphics graphics;
SDL_Texture* background;

SDL_Texture* bird1[4];
SDL_Texture* bird2[4];
SDL_Texture* bird3[4];
SDL_Texture* bird4[4];

SDL_Texture* score;
SDL_Texture* highscore;
SDL_Texture* digit[10];
SDL_Texture* add5;
SDL_Texture* pipe1;
SDL_Texture* pipe2;
SDL_Texture* button;
SDL_Texture* pause_button;
SDL_Texture* mute_button;
SDL_Texture* unmute_button;
SDL_Texture* portal[10];
SDL_Texture* round_shield1;
SDL_Texture* round_shield2;
SDL_Texture* shield_icon;

SDL_Texture* font_play;
SDL_Texture* font_resume;
SDL_Texture* font_quit;
SDL_Texture* font_settings;
SDL_Texture* font_menu;
SDL_Texture* font_replay;

SDL_Texture* font_play2;
SDL_Texture* font_resume2;
SDL_Texture* font_quit2;
SDL_Texture* font_settings2;
SDL_Texture* font_menu2;
SDL_Texture* font_replay2;
SDL_Texture* font_level;
SDL_Texture* font_easy;
SDL_Texture* font_hard;

SDL_Texture* font_music;
SDL_Texture* font_sound;

SDL_Texture* name;
SDL_Texture* gift;

Mix_Chunk* get_score;
Mix_Chunk* game_over;
Mix_Chunk* get_secret;
Mix_Music* intro;
Mix_Chunk* good;
Mix_Chunk* bad;
Mix_Chunk* shield;
Mix_Chunk* off;

bool menu = true, pause = false, play = false, settings = false;
bool upside_down = false;
bool mini = false;
bool quit = false;
bool mute_music = false;
bool mute_sound = false;
bool is_game_over = false;
int mul_ten = 1, time_secret = -1, time_shield = -1;
bool touch[2] = {false, false};
bool hardgame = false;

SDL_Event e;
int clip = 0;
const int x = 150;
int y = 150, point = 0, highpoint;
int pipe_x = 1200; //xx la toa do x cua pipe

vector<int> pipes(2);
vector<int> state_portal(2);

int space[10] = {20, 17, 20, 20, 23, 19, 20, 20, 19, 20};

ifstream fi("highscore.txt");

void initialize() {
    srand(time(0));
    graphics.init();

    fi >> highpoint;
    get_score = graphics.loadSound("music/get_score.mp3");
    game_over = graphics.loadSound("music/die.mp3");
    get_secret = graphics.loadSound("music/claw_grab_best.wav");
    intro = graphics.loadMusic("music/RunningAway.mp3");
    good = graphics.loadSound("music/claw_grab_good.wav");
    bad = graphics.loadSound("music/claw_grab_bad.wav");
    shield = graphics.loadSound("music/shield.mp3");
    off = graphics.loadSound("music/off.mp3");

    name = graphics.loadTexture("image/font/bird_dash.png");

    font_play = graphics.loadTexture("image/font/play.png");
    font_resume = graphics.loadTexture("image/font/resume.png");
    font_quit = graphics.loadTexture("image/font/quit.png");
    font_settings = graphics.loadTexture("image/font/settings.png");
    font_menu = graphics.loadTexture("image/font/menu.png");
    font_replay = graphics.loadTexture("image/font/replay.png");

    font_play2 = graphics.loadTexture("image/font/play2.png");
    font_resume2 = graphics.loadTexture("image/font/resume2.png");
    font_quit2 = graphics.loadTexture("image/font/quit2.png");
    font_settings2 = graphics.loadTexture("image/font/settings2.png");
    font_menu2 = graphics.loadTexture("image/font/menu2.png");
    font_replay2 = graphics.loadTexture("image/font/replay2.png");

    font_level = graphics.loadTexture("image/font/level.png");
    font_easy = graphics.loadTexture("image/font/easy.png");
    font_hard = graphics.loadTexture("image/font/hard.png");

    font_music = graphics.loadTexture("image/font/music.png");
    font_sound = graphics.loadTexture("image/font/sound.png");

    bird1[0] = graphics.loadTexture("image/frame/frame-1.png");
    bird1[1] = graphics.loadTexture("image/frame/frame-2.png");
    bird1[2] = graphics.loadTexture("image/frame/frame-3.png");
    bird1[3] = graphics.loadTexture("image/frame/frame-4.png");

    bird2[0] = graphics.loadTexture("image/frame/frame2-1.png");
    bird2[1] = graphics.loadTexture("image/frame/frame2-2.png");
    bird2[2] = graphics.loadTexture("image/frame/frame2-3.png");
    bird2[3] = graphics.loadTexture("image/frame/frame2-4.png");

    bird3[0] = graphics.loadTexture("image/frame/frame3-1.png");
    bird3[1] = graphics.loadTexture("image/frame/frame3-2.png");
    bird3[2] = graphics.loadTexture("image/frame/frame3-3.png");
    bird3[3] = graphics.loadTexture("image/frame/frame3-4.png");

    bird4[0] = graphics.loadTexture("image/frame/frame4-1.png");
    bird4[1] = graphics.loadTexture("image/frame/frame4-2.png");
    bird4[2] = graphics.loadTexture("image/frame/frame4-3.png");
    bird4[3] = graphics.loadTexture("image/frame/frame4-4.png");

    button = graphics.loadTexture("image/button/button.png");
    pause_button = graphics.loadTexture("image/button/pause_button.png");
    mute_button = graphics.loadTexture("image/button/mute.png");
    unmute_button = graphics.loadTexture("image/button/unmute.png");
    round_shield1 = graphics.loadTexture("image/shield1.png");
    round_shield2 = graphics.loadTexture("image/shield2.png");
    shield_icon = graphics.loadTexture("image/shield_icon.png");

    score = graphics.loadTexture("image/font/score .png");
    highscore = graphics.loadTexture("image/font/high_score.png");
    background = graphics.loadTexture("image/background.png");

    pipe1 = graphics.loadTexture("image/pipe/pipe1.png");
    pipe2 = graphics.loadTexture("image/pipe/pipe2.png");

    add5 = graphics.loadTexture("image/font/add5.png");

    for (int i = 0; i < 10; i++) digit[i] = graphics.loadTexture(DIGIT[i]);

    for (int i = 0; i < 2; i++) pipes[i] = rand() % (SCREEN_HEIGHT - 200) + 200;
    for (int i = 0; i < 2; i++) state_portal[i] = rand() % 10;

    portal[0] = graphics.loadTexture("image/portal/down_or_up_portal.png");
    portal[1] = graphics.loadTexture("image/portal/up_portal.png");
    portal[2] = graphics.loadTexture("image/portal/down_portal.png");
    portal[3] = graphics.loadTexture("image/portal/mini_portal.png");
    portal[4] = graphics.loadTexture("image/portal/big_portal.png");
    portal[5] = graphics.loadTexture("image/gift.png");
}
