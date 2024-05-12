#pragma once

#include "global.hpp"


class Sunflower{
public:
    Sunflower(int x, int y);
    ~Sunflower();
    void render(RenderWindow *window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2f pos);
    void handle_mouse_release(Vector2f pos);
private:
    Texture sunflowertexture;
    Sprite sunflowersprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
};