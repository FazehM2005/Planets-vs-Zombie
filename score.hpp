#pragma once

#include "global.hpp"

class Score{
public:
    Score();
    ~Score();
    void render(RenderWindow* window); 

private:
    Texture scoreTexture ;
    Sprite scoreSprite ;

};