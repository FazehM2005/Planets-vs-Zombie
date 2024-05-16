#pragma once
#include "global.hpp"


class Wallnut{
public:
    Wallnut(int x, int y);
    ~Wallnut();
    void render(RenderWindow *window);
    void update();
    void handle_event(Event ev , RenderWindow* window);
    Vector2f offset ;
    FloatRect get_rect();
 
private:
    Clock clock;
    Texture Wallnuttexture;
    Sprite Wallnutsprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    int poses[5] = {0, 208, 419, 629, 837};
    int cur_rect = 0 ;
};