#include "sunflower.hpp"

Sunflower::Sunflower(int x, int y)
{

    pos = Vector2f(x, y);
    sunflowertexture.loadFromFile(PICS_PATH + "sunflowerplant.png");
    sunflowersprite.setTexture(sunflowertexture);
    sunflowersprite.setScale(0.4, 0.4);
    rect.width = 190;
    rect.height = 207;
    rect.top = 0;
    rect.left = 0;
    sunflowersprite.setTextureRect(rect);
    sunflowersprite.setPosition(x, y);
}

Sunflower::~Sunflower()
{
}

void Sunflower::render(RenderWindow *window)
{
    window->draw(sunflowersprite);
}

void Sunflower::update()
{
    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 300)
    {
        clock.restart();
        cur_rect = (cur_rect + 1) % 6;
        IntRect rect;
        rect.width = 190;
        rect.height = 207;
        rect.left = poses[cur_rect];
        sunflowersprite.setTextureRect(rect);
    }
}

void Sunflower::handle_event(Event event, RenderWindow *window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        Vector2i mousePos = Mouse::getPosition(*window);
        Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (sunflowersprite.getGlobalBounds().contains(worldPos))
        {
            is_tagged = true;
            offset = sunflowersprite.getPosition() - worldPos;
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

        sunflowersprite.setPosition(worldPos + offset);
    }
}
