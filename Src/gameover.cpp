#include "global.hpp"
#include "gameover.hpp"

Gameover::Gameover()
{
    gameoverTexture.loadFromFile(PICS_PATH + "sprite.png");
    gameoverSprite.setTexture(gameoverTexture);
    gameoverSprite.setPosition(100 ,100 );
}

Gameover::~Gameover()
{
}

void Gameover::render(RenderWindow* window)
{
    window->draw(gameoverSprite);
}
