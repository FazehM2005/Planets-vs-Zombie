#include "Game.hpp"
#include "score.hpp"
#include "global.hpp"

void Game::initVariables()
{
    this->window = nullptr;
    this->score = new Score();

}

void Game::initWindow()
{
    this->window = new RenderWindow(VideoMode(WIDTH , HEIGHT) , "PlantsVsZombies" , Style::Close);
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);

}
void Game::initPlantsMenue()
{
    plantsmenueTexture.loadFromFile("plantsmenue.png");
    plantsmenueSprite.setTexture(plantsmenueTexture);
    plantsmenueSprite.setPosition(30 , 85);
    plantsmenueSprite.setScale(0.60 , 0.60);
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlantsMenue();
}

Game::~Game()
{
    if (this->window != nullptr) {
        delete this->window;
    }
    if (this->score != nullptr) {
        delete this->score;
    }
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while (this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
        case Event::Closed:
            this->window->close();
            break;

        case Event::KeyPressed:
            if (ev.key.code == Keyboard::Escape)
            {
                this->window->close();
            }
            break;
        }
    }  
}


void Game::update()
{
    this->pollEvent();
}

void Game::render()
{
    this->window->clear(Color::Black);
    this->window->draw(backgroundSprite);
    this->window->draw(plantsmenueSprite);
    score->render(window);
    this->window->display();
} 

