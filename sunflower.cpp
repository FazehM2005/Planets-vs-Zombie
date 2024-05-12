#include "sunflower.hpp"

Sunflower::Sunflower(int x, int y)
{
    pos = Vector2f(x,y);
    sunflowertexture.loadFromFile("sunflowerplant.png");
    sunflowersprite.setTexture(sunflowertexture);
    sunflowersprite.setScale(0.4 ,0.4);
    rect.width = 190;
    rect.height = 207;
    rect.top = 0;
    rect.left = 0;
    sunflowersprite.setTextureRect(rect);
}


Sunflower::~Sunflower()
{
}

void Sunflower::render(RenderWindow *window)
{
    window->draw(sunflowersprite);
}

void Sunflower::update(Vector2i pos)
{
    if(is_tagged){
        Vector2f target(static_cast<float>(pos.x) - sunflowersprite.getTextureRect().width, static_cast<float>(pos.y) - sunflowersprite.getTextureRect().height);
        sunflowersprite.setPosition(target);
    }
    fix_position();

    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 5;
        IntRect rect;
        rect.width = 190; 
        rect.height = 207;
        rect.left = poses[cur_rect];
        sunflowersprite.setTextureRect(rect);
    }
}

void Sunflower::handle_mouse_press(Vector2i mousePos)
{
    Vector2f spritePos = sunflowersprite.getPosition();
    Vector2f spriteSize = {sunflowersprite.getTextureRect().width * 2, sunflowersprite.getTextureRect().height * 2};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.x >= spritePos.y && mousePos.x <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
}

void Sunflower::handle_mouse_release(Vector2i pos)
{
    is_tagged = false;
    return;
}

void Sunflower::fix_position()
{
    FloatRect rect = sunflowersprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    sunflowersprite.setPosition(rect.left, rect.top);
}
