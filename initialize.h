#include "graphics.h"
#include "definition.h"

Graphics graphics;
SDL_Texture* background;
SDL_Texture* bird1[4];
SDL_Texture* bird2[4];
SDL_Texture* bird3[4];
SDL_Texture* bird4[4];
SDL_Texture* score;
SDL_Texture* digit[10];
SDL_Texture* pipe1;
SDL_Texture* pipe2;

SDL_Texture* portal[5];

vector<int> pipes(2);
vector<int> state_portal(2);

int space[10] = {20, 17, 20, 20, 23, 19, 20, 20, 19, 20};

void initialize() {
    srand(time(0));
    graphics.init();

    bird1[0] = graphics.loadTexture("frame-1.png");
    bird1[1] = graphics.loadTexture("frame-2.png");
    bird1[2] = graphics.loadTexture("frame-3.png");
    bird1[3] = graphics.loadTexture("frame-4.png");

    bird2[0] = graphics.loadTexture("frame2-1.png");
    bird2[1] = graphics.loadTexture("frame2-2.png");
    bird2[2] = graphics.loadTexture("frame2-3.png");
    bird2[3] = graphics.loadTexture("frame2-4.png");

    bird3[0] = graphics.loadTexture("frame3-1.png");
    bird3[1] = graphics.loadTexture("frame3-2.png");
    bird3[2] = graphics.loadTexture("frame3-3.png");
    bird3[3] = graphics.loadTexture("frame3-4.png");

    bird4[0] = graphics.loadTexture("frame4-1.png");
    bird4[1] = graphics.loadTexture("frame4-2.png");
    bird4[2] = graphics.loadTexture("frame4-3.png");
    bird4[3] = graphics.loadTexture("frame4-4.png");

    score = graphics.loadTexture(SCORE_FONT);
    background = graphics.loadTexture(BACKGROUND);

    pipe1 = graphics.loadTexture(PIPE1);
    pipe2 = graphics.loadTexture(PIPE2);

    for (int i = 0; i < 10; i++) digit[i] = graphics.loadTexture(DIGIT[i]);

    for (int i = 0; i < 2; i++) pipes[i] = rand() % (SCREEN_HEIGHT - 200) + 200;
    for (int i = 0; i < 2; i++) state_portal[i] = rand() % 5;

    portal[1] = graphics.loadTexture("up_portal.png");
    portal[2] = graphics.loadTexture("down_portal.png");
    portal[3] = graphics.loadTexture("mini_portal.png");
    portal[4] = graphics.loadTexture("big_portal.png");
}
