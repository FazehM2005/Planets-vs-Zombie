#pragma once

#include "global.hpp"


class Sunflower{
public:
    Sunflower(int x, int y);
    ~Sunflower();
    void render(RenderWindow *window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
private:
    Clock clock;
    Texture sunflowertexture;
    Sprite sunflowersprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
    int poses[6] = {0, 199, 409, 610, 812, 1020};
    int cur_rect = 0 ;
};