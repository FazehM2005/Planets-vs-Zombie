#include "global.hpp"
#include "score.hpp"

Score::Score()
{
    scoreTexture.loadFromFile(PICS_PATH + "score.png");
    scoreSprite.setTexture(scoreTexture);
    scoreSprite.setPosition(50 , 20);
    scoreSprite.setScale(0.055 , 0.055);

}

Score::~Score()
{

}

void Score::render(RenderWindow* window)
{
    window->draw(scoreSprite);
}