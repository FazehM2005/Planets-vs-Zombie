#include "global.hpp"
#include "score.hpp"

Score::Score()
{
    scoreTexture.loadFromFile("score.png");
    scoreSprite.setTexture(scoreTexture);
    scoreSprite.setPosition(21 , 10);
    scoreSprite.setScale(0.5 , 0.5);
    scoreFont.loadFromFile("Nerd.ttf");
    scoreText.setFont(scoreFont);
    scoreText.setString("100");
    scoreText.setCharacterSize(24); 
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(125, 35);
}

Score::~Score()
{

}

void Score::render(RenderWindow* window)
{
    window->draw(scoreSprite);
    window->draw(scoreText);
}