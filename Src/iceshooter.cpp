#include "iceshooter.hpp"

Iceshooter::Iceshooter(int x, int y)
{
    pos = Vector2f(x, y);
    Iceshootertexture.loadFromFile(PICS_PATH + "Iceshooterplants.png");
    Iceshootersprite.setTexture(Iceshootertexture);
    Iceshootersprite.setScale(0.09, 0.09);
    rect.left = 0;
    rect.top = 0;
    rect.width = 903;
    rect.height = 919;
    Iceshootersprite.setTextureRect(rect);
    Iceshootersprite.setPosition(x,y);
}

Iceshooter::~Iceshooter()
{
}

void Iceshooter::render(RenderWindow *window)
{
    window->draw(Iceshootersprite);
    for (auto pr : iceprojectiles)
    {
        pr->render(window);
    }
}

void Iceshooter::update()
{

    Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 100)
    {
        clock.restart();
        cur_rect = (cur_rect + 1) % 11;
        IntRect rect;
        rect.width = 900;
        rect.height = 919;
        rect.left = poses[cur_rect];
        Iceshootersprite.setTextureRect(rect);
    }
    projectile_pos = Vector2f(Iceshootersprite.getPosition().x + 45, Iceshootersprite.getPosition().y + 9);

    Time selapsed = prclock.getElapsedTime();
    if (selapsed.asMilliseconds() >= 1200)
    {
        prclock.restart();
        Iceprojectile *pr = new Iceprojectile(projectile_pos);
        iceprojectiles.push_back(pr);
    }
    for (auto pr : iceprojectiles)
    {
        pr->update();
    }
}

void Iceshooter::handle_event(Event event, RenderWindow *window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        Vector2i mousePos = Mouse::getPosition(*window);
        Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (Iceshootersprite.getGlobalBounds().contains(worldPos))
        {
            is_tagged = true;
            offset = Iceshootersprite.getPosition() - worldPos;
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

        Iceshootersprite.setPosition(worldPos + offset);
    }
}
