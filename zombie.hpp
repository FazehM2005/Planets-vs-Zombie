#pragma once

#include "global.hpp"

class Zombie {
public:
    Zombie();
    ~Zombie();
    void render(RenderWindow* window); 
    void update();
    int generateRandomNumber(int min, int max);
    float getZombiePosition();
    bool gameOverValue = false ;
    void gameOver();

private:
    Clock clock;
    Event ev; 
    Texture zombieTexture ;
    Sprite zombieSprite ;
    int poses[7] = {0, 215, 408, 593, 798, 974, 1175};
    int cur_rect = 0 ;
};