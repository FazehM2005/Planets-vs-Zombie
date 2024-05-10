#pragma once

#include "global.hpp"
#include "Sun.hpp"
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
    Sun* sun;
    void initVariables() ;
    void initWindow() ;
    void initPlantsMenue();
};
