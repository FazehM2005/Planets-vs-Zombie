#pragma once

#include "global.hpp"


class Iceshooter{
public:
    Iceshooter(int x, int y);
    ~Iceshooter();
    void render(RenderWindow *window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
private:
    Clock clock;
    Texture Iceshootertexture;
    Sprite Iceshootersprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
    int poses[11] = {0,87,179,271,363,453,545,636,726,817,900};
    int cur_rect = 0 ;
};