#pragma once

#include "global.hpp"


class Peashooter{
public:
    Peashooter(int x, int y);
    ~Peashooter();
    void render(RenderWindow *window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
private:
    Clock clock;
    Texture peashootertexture;
    Sprite peashootersprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
    int poses[11] = {39,337,639,944,1247,1550,1854,2159,2454,2734,2974};
    int cur_rect = 0 ;
};