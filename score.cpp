#include "global.hpp"
#include "score.hpp"

Score::Score()
{
    scoreTexture.loadFromFile("score.png");
    scoreSprite.setTexture(scoreTexture);
    scoreSprite.setPosition(21 , 10);
    scoreSprite.setScale(0.5 , 0.5);
}

Score::~Score()
{

}

void Score::render(RenderWindow* window)
{
    window->draw(scoreSprite);
}