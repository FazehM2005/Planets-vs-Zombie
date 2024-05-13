#include "iceshooter.hpp"


Iceshooter::Iceshooter(int x, int y)
{
    pos = Vector2f(x,y);
    Iceshootertexture.loadFromFile("Iceshooterplants.png");
    Iceshootersprite.setTexture(Iceshootertexture);
    Iceshootersprite.setScale(0.75 ,0.75);
    rect.left =16;
    rect.top =0;
    rect.width = 95;
    rect.height = 110;
    Iceshootersprite.setTextureRect(rect);
}


Iceshooter::~Iceshooter()
{
}

void Iceshooter::render(RenderWindow *window)
{
    window->draw(Iceshootersprite);
}

void Iceshooter::update(Vector2i pos)
{
    if(is_tagged){
        Vector2f target(static_cast<float>(pos.x) - Iceshootersprite.getTextureRect().width, static_cast<float>(pos.y) - Iceshootersprite.getTextureRect().height);
        Iceshootersprite.setPosition(target);
    }
    fix_position();

    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 100){
        clock.restart();
        cur_rect = (cur_rect + 1) % 11;
        IntRect rect;
        rect.width = 90; 
        rect.height = 110;
        rect.left = poses[cur_rect];
        Iceshootersprite.setTextureRect(rect);
    } 
}

void Iceshooter::handle_mouse_press(Vector2i mousePos)
{
    Vector2f spritePos = Iceshootersprite.getPosition();
    Vector2f spriteSize = {Iceshootersprite.getTextureRect().width * 0.25, Iceshootersprite.getTextureRect().height * 0.25};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.x >= spritePos.y && mousePos.x <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
}

void Iceshooter::handle_mouse_release(Vector2i pos)
{
    is_tagged = false;
    return;
}

void Iceshooter::fix_position()
{
    FloatRect rect = Iceshootersprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    Iceshootersprite.setPosition(rect.left, rect.top);
}