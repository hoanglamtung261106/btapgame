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
SDL_Texture* pipe1;
SDL_Texture* pipe2;
SDL_Texture* button;
SDL_Texture* pause_button;
SDL_Texture* mute_button;
SDL_Texture* unmute_button;
SDL_Texture* portal[10];

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

SDL_Texture* font_music;
SDL_Texture* font_sound;
SDL_Texture* font_gm1;
SDL_Texture* font_gm2;

SDL_Texture* name;
SDL_Texture* gift;

Mix_Music* music1;
Mix_Music* music2;
Mix_Chunk* get_score;
Mix_Chunk* game_over;
Mix_Chunk* get_secret;
Mix_Chunk* intro;

bool menu = true, pause = false, play = false, settings = false;
bool upside_down = false;
bool mini = false;
bool quit = false;
bool mute_music = false;
bool mute_sound = false;
bool state_music = 0;
bool is_game_over = false;
int mul_ten = 1;

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
    music1 = graphics.loadMusic("music/glorious_morning.mp3");
    music2 = graphics.loadMusic("music/glorious_morning_2.mp3");
    get_score = graphics.loadSound("music/get_score.mp3");
    game_over = graphics.loadSound("music/die.mp3");
    get_secret = graphics.loadSound("music/claw_grab_best.wav");
    intro = graphics.loadSound("music/level_intro.wav");

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

    font_music = graphics.loadTexture("image/font/music.png");
    font_sound = graphics.loadTexture("image/font/sound.png");
    font_gm1 = graphics.loadTexture("image/font/gm1.png");
    font_gm2 = graphics.loadTexture("image/font/gm2.png");

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

    score = graphics.loadTexture("image/font/score .png");
    highscore = graphics.loadTexture("image/font/high_score.png");
    background = graphics.loadTexture("image/background.png");

    pipe1 = graphics.loadTexture("image/pipe/pipe1.png");
    pipe2 = graphics.loadTexture("image/pipe/pipe2.png");

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
