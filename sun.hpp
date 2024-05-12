#pragma once
#include "global.hpp"
class Sun {

public:
    Sun();
    ~Sun();
    void render(RenderWindow* window);
    bool contains(Vector2i& point);

private:
    Sprite Sunsprite;
    Texture Suntexture;
    float Sunspeed;
};