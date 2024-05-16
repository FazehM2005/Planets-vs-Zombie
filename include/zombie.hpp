#pragma once

#include "global.hpp"
#include "gameover.hpp"

class Zombie {
public:
    Zombie();
    ~Zombie();
    void render(RenderWindow* window); 
    void update(RenderWindow* window);
    Gameover* gameover;
    int generateRandomNumber(int min, int max);
    FloatRect get_rect();
    float zombiespeed = -0.07;
    int get_health() {return health;};
    void set_helth(int newhealth);

private:
    Clock clock;
    Event ev; 
    Texture zombieTexture ;
    Sprite zombieSprite ;
    int poses[7] = {0, 215, 408, 593, 798, 974, 1175};
    int cur_rect = 0 ;
    int health = 300 ;
};