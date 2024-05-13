#pragma once
#include "global.hpp"


class Wallnut{
public:
    Wallnut(int x, int y);
    ~Wallnut();
    void render(RenderWindow *window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
private:
    Clock clock;
    Texture Wallnuttexture;
    Sprite Wallnutsprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
    int poses[5] = {0, 208, 419, 629, 837};
    int cur_rect = 0 ;
};