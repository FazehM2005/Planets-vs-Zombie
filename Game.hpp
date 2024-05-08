#pragma once

#include "score.hpp"

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
    Score* score;
    void initVariables() ;
    void initWindow() ;
    void initPlantsMenue();
};