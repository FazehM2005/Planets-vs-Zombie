#include "global.hpp"
#include "zombie.hpp"


int Zombie::generateRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

Zombie::Zombie()
{
    zombieTexture.loadFromFile("Zombie.png");
    zombieSprite.setTexture(zombieTexture);
    IntRect rect ;
    rect.width=110;
    rect.height=191;
    zombieSprite.setTextureRect(rect);
    int randomZombiePos = generateRandomNumber(1,5);
    switch(randomZombiePos)
    {
        case 1 :
        zombieSprite.setPosition(975 , 60);
        break;
        case 2 :
        zombieSprite.setPosition(984 , 165);
        break;
        case 3 :
        zombieSprite.setPosition(993 , 260);
        break;
        case 4 :
        zombieSprite.setPosition(985 , 357);
        break;
        case 5 :
        zombieSprite.setPosition(989 , 450);
        break;

    }

    zombieSprite.setScale(0.6 , 0.6);
}

Zombie::~Zombie()
{

}

void Zombie::render(RenderWindow* window)
{
    zombieSprite.move(-0.025 , 0);
    window->draw(zombieSprite);
}

void Zombie::update()
{
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 6;
        IntRect rect;
        rect.width = 120; 
        rect.height = 191;
        rect.left = poses[cur_rect];
        zombieSprite.setTextureRect(rect);
    }

}

float Zombie::getZombiePosition()
{
    return zombieSprite.getPosition().x ;
}

void Zombie::gameOver()
{
    float zombieXPos = getZombiePosition();
    float GameoverLine = 228 ;

    if (zombieXPos = GameoverLine)
    {
        gameOverValue = true ;
    }
}
