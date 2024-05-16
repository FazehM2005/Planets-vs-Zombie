#pragma once

#include "score.hpp"
#include "zombie.hpp"
#include "gameover.hpp"
#include "handler.hpp"
#include "sunflower.hpp"
#include "peashooter.hpp"
#include "iceshooter.hpp"

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
    Score* score;
    Handler* handler;
    Sunflower* sunflower;
    Peashooter* peashooter;
    Iceshooter* iceshooter;
    Gameover* gameover;
    void initVariables() ;
    void initWindow() ;
    void initSunflowerMenue();
    void initPeashooterMenue();
    void initSnowPeashooterMenue();
    void initWallNutMenue();
    Music music;
    // void handle_mouse_press(Event ev);
    // void handle_mouse_release(Event ev);
    // void handle_mouse_move(Event ev);

protected:
    Texture sunflowerMTexture;
    Sprite sunflowerMSprite ;
    Texture peashooterMTexture;
    Sprite peashooterMSprite ;
    Texture snowpeashooterMTexture;
    Sprite snowpeashooterMSprite ;
    Texture wallnutMTexture;
    Sprite wallnutMSprite ;
   
};