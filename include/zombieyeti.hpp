#pragma once

#include "global.hpp"

class ZombieYeti {
public:
    ZombieYeti();
    ~ZombieYeti();
    void render(RenderWindow* window); 
    void update();
    int generateRandomNumber(int min, int max);
    bool gameOverValue = false ;
    void gameOver();

private:
    Clock clock;
    Event ev; 
    Texture zombieYetiTexture ;
    Sprite zombieYetiSprite ;
    int poses[6] = {0, 186, 379, 583, 761, 954};
    int cur_rect = 0 ;
};