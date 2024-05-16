#pragma once

#include "global.hpp"


class Sunflower{
public:
    Sunflower(int x, int y);
    ~Sunflower();
    void render(RenderWindow *window);
    void update();
    void handle_event(Event ev , RenderWindow* window);
    Vector2f offset ;
private:
    Clock clock;
    Texture sunflowertexture;
    Sprite sunflowersprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    int poses[6] = {0, 199, 409, 610, 812, 1020};
    int cur_rect = 0 ;
};