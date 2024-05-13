#include "wallnut.hpp"

Wallnut::Wallnut(int x, int y)
{
    pos = Vector2f(x,y);
    Wallnuttexture.loadFromFile("wall_nut.png");
    Wallnutsprite.setTexture(Wallnuttexture);
    Wallnutsprite.setScale(0.4 ,0.4);
    rect.width = 204;
    rect.height = 238;
    rect.top = 0;
    rect.left = 6;
    Wallnutsprite.setTextureRect(rect);
}


Wallnut::~Wallnut()
{
}

void Wallnut::render(RenderWindow *window)
{
    window->draw(Wallnutsprite);
}

void Wallnut::update(Vector2i pos)
{
    if(is_tagged){
        Vector2f target(static_cast<float>(pos.x) - Wallnutsprite.getTextureRect().width, static_cast<float>(pos.y) - Wallnutsprite.getTextureRect().height);
        Wallnutsprite.setPosition(target);
    }
    fix_position();

    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 5;
        IntRect rect;
        rect.width = 204;
        rect.height = 238;
        rect.left = poses[cur_rect];
        Wallnutsprite.setTextureRect(rect);
    }
}

void Wallnut::handle_mouse_press(Vector2i mousePos)
{
    Vector2f spritePos = Wallnutsprite.getPosition();
    Vector2f spriteSize = {Wallnutsprite.getTextureRect().width * 2, Wallnutsprite.getTextureRect().height * 2};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.x >= spritePos.y && mousePos.x <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
}

void Wallnut::handle_mouse_release(Vector2i pos)
{
    is_tagged = false;
    return;
}

void Wallnut::fix_position()
{
    FloatRect rect = Wallnutsprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    Wallnutsprite.setPosition(rect.left, rect.top);
}