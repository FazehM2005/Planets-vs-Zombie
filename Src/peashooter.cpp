#include "peashooter.hpp"

Peashooter::Peashooter(int x, int y)
{
    pos = Vector2f(x, y);
    peashootertexture.loadFromFile(PICS_PATH + "peashooterplants.png");
    peashootersprite.setTexture(peashootertexture);
    peashootersprite.setScale(0.08, 0.08);
    rect.left = 0;
    rect.top = 0;
    rect.width = 903;
    rect.height = 1155;
    peashootersprite.setTextureRect(rect);
    peashootersprite.setPosition(x, y);
}

Peashooter::~Peashooter()
{
}

void Peashooter::render(RenderWindow *window)
{
    window->draw(peashootersprite);
    for (auto pr : projectiles)
    {
        pr->render(window);
    }
}

void Peashooter::update()
{
    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 150)
    {
        clock.restart();
        cur_rect = (cur_rect + 1) % 11; 
        IntRect rect;
        rect.width = 903;
        rect.height = 1155;
        rect.left = poses[cur_rect];
        peashootersprite.setTextureRect(rect);
    }
    projectile_pos = Vector2f(peashootersprite.getPosition().x + 40, peashootersprite.getPosition().y + 15);

    Time selapsed = prclock.getElapsedTime();
    if (selapsed.asMilliseconds() >= 1600)
    {
        prclock.restart();
        Projectile *pr = new Projectile(projectile_pos);
        projectiles.push_back(pr);
    }
    for (auto pr : projectiles)
    {
        pr->update();
    }

}

void Peashooter::handle_event(Event event, RenderWindow *window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        Vector2i mousePos = Mouse::getPosition(*window);
        Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (peashootersprite.getGlobalBounds().contains(worldPos))
        {
            is_tagged = true;
            offset = peashootersprite.getPosition() - worldPos;
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

        peashootersprite.setPosition(worldPos + offset);
    }
}
