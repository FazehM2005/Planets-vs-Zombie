#include "peashooter.hpp"


Peashooter::Peashooter(int x, int y)
{
    pos = Vector2f(x,y);
    peashootertexture.loadFromFile("peashooterplants.png");
    peashootersprite.setTexture(peashootertexture);
    peashootersprite.setScale(0.25 ,0.25);
    rect.left =39;
    rect.top =21;
    rect.width = 291;
    rect.height = 338;
    peashootersprite.setTextureRect(rect);
}


Peashooter::~Peashooter()
{
}

void Peashooter::render(RenderWindow *window)
{
    window->draw(peashootersprite);
}

void Peashooter::update(Vector2i pos)
{
    if(is_tagged){
        Vector2f target(static_cast<float>(pos.x) - peashootersprite.getTextureRect().width, static_cast<float>(pos.y) - peashootersprite.getTextureRect().height);
        peashootersprite.setPosition(target);
    }
    fix_position();

    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 200){
        clock.restart();
        cur_rect = (cur_rect + 1) % 11;
        IntRect rect;
        rect.width = 285; 
        rect.height = 339;
        rect.left = poses[cur_rect];
        peashootersprite.setTextureRect(rect);
    } 
}

void Peashooter::handle_mouse_press(Vector2i mousePos)
{
    Vector2f spritePos = peashootersprite.getPosition();
    Vector2f spriteSize = {peashootersprite.getTextureRect().width * 0.25, peashootersprite.getTextureRect().height * 0.25};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.x >= spritePos.y && mousePos.x <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
}

void Peashooter::handle_mouse_release(Vector2i pos)
{
    is_tagged = false;
    return;
}

void Peashooter::fix_position()
{
    FloatRect rect = peashootersprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    peashootersprite.setPosition(rect.left, rect.top);
}
