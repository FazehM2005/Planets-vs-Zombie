#pragma once

#include "global.hpp"

class Game{
public:
    Game();
    ~Game();
    const bool running() const;
    void pollEvent();
    void update();
    void render(); 

private:
    RenderWindow* window ;
    Event ev; 
    Texture backgroundTexture ;
    Sprite backgroundSprite ;
    Texture plantsmenueTexture;
    Sprite plantsmenueSprite ;
    void initVariables() ;
    void initWindow() ;
    void initPlantsMenue();
};