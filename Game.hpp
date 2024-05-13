#pragma once

#include "score.hpp"
#include "zombie.hpp"
#include "gameover.hpp"
#include "handler.hpp"
#include "sunflower.hpp"
#include "peashooter.hpp"

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
    Texture sunflowerMTexture;
    Sprite sunflowerMSprite ;
    Texture peashooterMTexture;
    Sprite peashooterMSprite ;
    Texture snowpeashooterMTexture;
    Sprite snowpeashooterMSprite ;
    Texture wallnutMTexture;
    Sprite wallnutMSprite ;
    Score* score;
    Handler* handler;
    Sunflower* sunflower;
    Peashooter* peashooter;
    Gameover* gameover;
    void initVariables() ;
    void initWindow() ;
    void initSunflowerMenue();
    void initPeashooterMenue();
    void initSnowPeashooterMenue();
    void initWallNutMenue();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
};