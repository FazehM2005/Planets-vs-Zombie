#pragma once

#include "global.hpp"

class Gameover{
public:
    Gameover();
    ~Gameover();
    void render(RenderWindow* window); 

private:
 
    Texture gameoverTexture ;
    Sprite gameoverSprite ;

};