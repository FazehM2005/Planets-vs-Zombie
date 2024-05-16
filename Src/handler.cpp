#include "handler.hpp"

Handler::Handler()
{
}

Handler::~Handler()
{
    for (auto z : zombies)
    {
        delete z;
    }
    for (auto zy : zombieyeti)
    {
        delete zy;
    }
    for (auto s : sun)
    {
        delete s;
    }
    for (auto pr : projectiles)
    {
        delete pr;
    }
    for (auto s : sunflowers)
    {
        delete s;
    }
    for (auto p : peashooters)
    {
        delete p;
    }
    for (auto i : iceshooters)
    {
        delete i;
    }
    for (auto w : wallnuts)
    {
        delete w;
    }
    wallnuts.clear();
}

void Handler::update(Vector2i *pos, RenderWindow *window, Event ev, Sprite sunflowerMSprite, Sprite peashooterMSprite, Sprite snowpeashooterMSprite, Sprite wallnutMSprite)
{

    Time zelapsed = zombie_clock.getElapsedTime();
    if (zelapsed.asMilliseconds() >= 20000)
    {
        zombie_clock.restart();
        add_zombie();
    }
    for (auto z : zombies)
    {
        z->update(window);
    }
    Time zyelapsed = zombieyeti_clock.getElapsedTime();
    if (zyelapsed.asMilliseconds() >= 45000)
    {
        zombieyeti_clock.restart();
        add_zombieyeti();
    }
    for (auto zy : zombieyeti)
    {
        zy->update();
    }
    Time selapsed = sun_clock.getElapsedTime();
    if (selapsed.asMilliseconds() >= 4000)
    {
        sun_clock.restart();
        add_sun(pos);
    }

    if (ev.type == Event::MouseButtonPressed)
    {
        if (ev.mouseButton.button == Mouse::Left)
        {

            Vector2i mousePos = Mouse::getPosition(*window);
            Vector2f worldPos = window->mapPixelToCoords(mousePos);
            for (auto it = sun.begin(); it != sun.end(); ++it)
            {
                if ((*it)->contains(mousePos))
                {
                    sun.erase(it);
                    score += 50;
                    break;
                }
            }

            if (sunflowerMSprite.getGlobalBounds().contains(worldPos) && score >= 50)
            {
                add_sunflower();
                score -= 50;
            }
            if (peashooterMSprite.getGlobalBounds().contains(worldPos) && score >= 100)
            {
                add_peashooter();
                score -= 100;
            }
            if (snowpeashooterMSprite.getGlobalBounds().contains(worldPos) && score >= 175)
            {
                add_iceshooter();
                score -= 175;
            }
            if (wallnutMSprite.getGlobalBounds().contains(worldPos) && score >= 50)
            {
                add_wallnut();
                score -= 50;
            }
        }
    }
    for (auto s : sunflowers)
    {
        s->update();
        s->handle_event(ev, window);
    }
    for (auto p : peashooters)
    {
        p->update();
        p->handle_event(ev, window);
    }
    for (auto i : iceshooters)
    {
        i->update();
        i->handle_event(ev, window);
    }
    for (auto w : wallnuts)
    {
        w->update();
        w->handle_event(ev, window);
    }

    handle_collision();
}

void Handler::render(RenderWindow *window)
{
    for (auto z : zombies)
    {
        z->render(window);
    }
    for (auto zy : zombieyeti)
    {
        zy->render(window);
    }
    for (auto s : sun)
    {
        if (rendered)
        {
            s->render(window);
        }
    }
    for (auto s : sunflowers)
    {
        s->render(window);
    }
    for (auto p : peashooters)
    {
        p->render(window);
    }
    for (auto i : iceshooters)
    {
        i->render(window);
    }
    for (auto w : wallnuts)
    {
        w->render(window);
    }
    scoreFont.loadFromFile(FONTS_PATH + "Nerd.ttf");
    scoreText.setFont(scoreFont);
    scoreText.setString(to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(125, 35);
    window->draw(scoreText);
}

void Handler::add_zombie()
{
    Zombie *z = new Zombie();
    zombies.push_back(z);
}

void Handler::add_zombieyeti()
{
    ZombieYeti *z = new ZombieYeti();
    zombieyeti.push_back(z);
}

void Handler::add_sun(Vector2i *pos)
{
    Sun *s = new Sun();
    sun.push_back(s);
    if (s->contains(*pos))
    {
        rendered = false;
    }
}
void Handler::add_sunflower()
{
    Sunflower *s = new Sunflower(90, 133);
    sunflowers.push_back(s);
}

void Handler::add_peashooter()
{
    Peashooter *p = new Peashooter(90, 230);
    peashooters.push_back(p);
}

void Handler::add_iceshooter()
{
    Iceshooter *i = new Iceshooter(90, 440);
    iceshooters.push_back(i);
}

void Handler::add_wallnut()
{
    Wallnut *w = new Wallnut(90, 330);
    wallnuts.push_back(w);
}

void Handler::handle_collision()
{
    vector<Wallnut *> trashwallnut;
    vector<Zombie *> trashzombie;
    vector<ZombieYeti *> trashzombieyeti;
    vector<Projectile *> trashprijectiles;
    for (auto w : wallnuts)
    {
        for (auto z : zombies)
        {
            FloatRect w_rect = w->get_rect();
            FloatRect z_rect = z->get_rect();
            if (z_rect.intersects(w_rect))
            {
                Time erease = wremove_clock.getElapsedTime();
                if (erease.asMilliseconds() >= 5000)
                {
                    z->zombiespeed = 0;
                    wallnutnerf -= 100;
                    trashwallnut.push_back(w);
                    wremove_clock.restart();
                }
                z->zombiespeed = -0.07;
            }
        }
    }
    for (auto w : trashwallnut)
    {
        wallnuts.erase(remove(wallnuts.begin(), wallnuts.end(), w), wallnuts.end());
        delete w;
    }
    for (auto p : peashooters)
    {
        p->get_projectiles() = projectiles;

        for (auto pr : projectiles)
        {
            for (auto z : zombies)
            {
                FloatRect pr_rect = pr->get_rect();
                FloatRect z_rect = z->get_rect();
                if (z_rect.intersects(pr_rect))
                {
                    int health = z->get_health();
                    health -= 50;
                    z->set_helth(health);
                    trashprijectiles.push_back(pr);
                }
            }
        }
        for (auto pr : trashprijectiles)
        {
            projectiles.erase(remove(projectiles.begin(), projectiles.end(), pr), projectiles.end());
            delete pr;
        }

    }

    for (auto z : zombies)
    {
        if (z->get_health() <= 0)
        {
            trashzombie.push_back(z);
        }
    }
    for (auto z : trashzombie)
    {
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());
        delete z;
    }
}
