#pragma once

#include "global.hpp"

class Iceprojectile{
public:
    Iceprojectile(Vector2f pos);
    ~Iceprojectile();
    void render(RenderWindow* window);
    void update();
    bool is_out();
    FloatRect get_rect();
private:
    const int speed = 2;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};