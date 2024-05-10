#pragma once
#include "global.hpp"
class Sun {

public:
    Sun();
    ~Sun();
    void render(RenderWindow* window);
    //void Suntime();


private:
    Sprite Sunsprite;
    Texture Suntexture;
    float Sunspeed;
};