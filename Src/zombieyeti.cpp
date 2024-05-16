#include "global.hpp"
#include "zombieyeti.hpp"


int ZombieYeti::generateRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
    return 0;
}

ZombieYeti::ZombieYeti()
{
    zombieYetiTexture.loadFromFile(PICS_PATH + "ZombieYeti.png");
    zombieYetiSprite.setTexture(zombieYetiTexture);
    IntRect rect ;
    rect.width=138;
    rect.height=225;
    zombieYetiSprite.setTextureRect(rect);
    zombieYetiSprite.setScale(0.62 ,0.62);
    int randomZombiePos = generateRandomNumber(1,5);
    switch(randomZombiePos)
    {
        case 1 :
        zombieYetiSprite.setPosition(975 , 45);
        break;
        case 2 :
        zombieYetiSprite.setPosition(984 , 143);
        break;
        case 3 :
        zombieYetiSprite.setPosition(993 , 243);
        break;
        case 4 :
        zombieYetiSprite.setPosition(985 , 335);
        break;
        case 5 :
        zombieYetiSprite.setPosition(989 , 430);
        break;

    }
}

ZombieYeti::~ZombieYeti()
{
}

void ZombieYeti::render(RenderWindow *window)
{
    zombieYetiSprite.move(-0.025 , 0);
    window->draw(zombieYetiSprite);
}

void ZombieYeti::update()
{
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 6;
        IntRect rect;
        rect.width = 143; 
        rect.height = 225;
        rect.left = poses[cur_rect];
        zombieYetiSprite.setTextureRect(rect);
    }
}


void ZombieYeti::gameOver()
{
}
