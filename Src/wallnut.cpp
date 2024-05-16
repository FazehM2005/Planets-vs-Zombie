#include "wallnut.hpp"

Wallnut::Wallnut(int x, int y)
{
    pos = Vector2f(x, y);
    Wallnuttexture.loadFromFile(PICS_PATH + "wall_nut.png");
    Wallnutsprite.setTexture(Wallnuttexture);
    Wallnutsprite.setScale(0.3, 0.3);
    rect.width = 204;
    rect.height = 238;
    rect.top = 0;
    rect.left = 6;
    Wallnutsprite.setTextureRect(rect);
    Wallnutsprite.setPosition(x,y);
}

Wallnut::~Wallnut()
{
}

void Wallnut::render(RenderWindow *window)
{
    window->draw(Wallnutsprite);
}

void Wallnut::update()
{
    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 300)
    {
        clock.restart();
        cur_rect = (cur_rect + 1) % 5;
        IntRect rect;
        rect.width = 204;
        rect.height = 238;
        rect.left = poses[cur_rect];
        Wallnutsprite.setTextureRect(rect);
    }
}

void Wallnut::handle_event(Event event, RenderWindow *window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        Vector2i mousePos = Mouse::getPosition(*window);
        Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (Wallnutsprite.getGlobalBounds().contains(worldPos))
        {
            is_tagged = true;
            offset = Wallnutsprite.getPosition() - worldPos;
        }
    }
    else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
    {
        is_tagged = false;
    }
    else if (event.type == Event::MouseMoved && is_tagged)
    {
        sf::Vector2i mousePos = Mouse::getPosition(*window);
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        Wallnutsprite.setPosition(worldPos + offset);
    }
}

FloatRect Wallnut::get_rect()
{
    return Wallnutsprite.getGlobalBounds();
}
