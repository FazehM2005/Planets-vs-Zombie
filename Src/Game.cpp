#include "Game.hpp"
#include "score.hpp"
#include "sunflower.hpp"
#include "global.hpp"
#include "peashooter.hpp"
#include "gameover.hpp"
#include "iceshooter.hpp"

void Game::initVariables() {
    this->window = nullptr;
    this->score = new Score();
    this->peashooter = new Peashooter(700 ,200);
    this->handler = new Handler();
    this->gameover = new Gameover(); 
    this->sunflower = new Sunflower(700 , 400);
    this->iceshooter = new Iceshooter(900 , 400);
}

void Game::initWindow() {
    this->window = new RenderWindow(VideoMode(WIDTH , HEIGHT), "PlantsVsZombies", Style::Close);
    backgroundTexture.loadFromFile(PICS_PATH + "background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    music.openFromFile("game.ogg");
    music.setLoop(true);
    music.setVolume(75.f);
    music.play();
}

void Game::initSunflowerMenue() {
    sunflowerMTexture.loadFromFile(PICS_PATH + "sunflower.png");
    sunflowerMSprite.setTexture(sunflowerMTexture);
    sunflowerMSprite.setPosition(40 , 90);
    sunflowerMSprite.setScale(0.50 , 0.50);
    IntRect sunrect ;
    sunrect.width =200 ;
    sunrect.height = 192;
    sunflowerMSprite.setTextureRect(sunrect);

}

void Game::initPeashooterMenue()
{
    peashooterMTexture.loadFromFile(PICS_PATH + "peashooter.png");
    peashooterMSprite.setTexture(peashooterMTexture);
    peashooterMSprite.setPosition(43 , 190);
    peashooterMSprite.setScale(0.41 , 0.41);
    IntRect pearect ;
    pearect.width =233 ;
    pearect.height =213;
    peashooterMSprite.setTextureRect(pearect);
}

void Game::initSnowPeashooterMenue()
{
    snowpeashooterMTexture.loadFromFile(PICS_PATH + "snowpeashooter.png");
    snowpeashooterMSprite.setTexture(snowpeashooterMTexture);
    snowpeashooterMSprite.setPosition(43 , 380);
    snowpeashooterMSprite.setScale(0.19 , 0.19);
    IntRect spearect ;
    spearect.width =566 ;
    spearect.height =440;
    snowpeashooterMSprite.setTextureRect(spearect);
}

void Game::initWallNutMenue()
{
    wallnutMTexture.loadFromFile(PICS_PATH + "wallnut.png");
    wallnutMSprite.setTexture(wallnutMTexture);
    wallnutMSprite.setPosition(43 , 280);
    wallnutMSprite.setScale(0.5 , 0.5);
    IntRect nutrect ;
    nutrect.width =192 ;
    nutrect.height =184;
    wallnutMSprite.setTextureRect(nutrect);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initSunflowerMenue();
    this->initPeashooterMenue();
    this->initSnowPeashooterMenue();
    this->initWallNutMenue();
}

Game::~Game() {
    if (this->window != nullptr) {
        delete this->window;
    }
    if (this->score != nullptr) {
        delete this->score;
    }
    if (this->handler != nullptr){
        delete this->handler;
    }
    if (this->gameover != nullptr) { 
        delete this->gameover;
    }
    if (this->sunflower != nullptr) { 
        delete this->sunflower;
    }
    if (this->peashooter != nullptr) { 
        delete this->peashooter;
    }
    if (this->iceshooter != nullptr) { 
        delete this->iceshooter;
    }

}


const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvent() {
    while (this->window->pollEvent(ev)) { 
        switch (ev.type) {
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if (ev.key.code == Keyboard::Escape) {
                    this->window->close();
                }
                break;
  
        }
    }  
}

void Game::update() {

    Vector2i pos = Mouse::getPosition(*this->window);
    Vector2f worldPos = window->mapPixelToCoords(pos);
    this->pollEvent();
    this->handler->update(&pos , this->window ,ev, sunflowerMSprite, peashooterMSprite, snowpeashooterMSprite , wallnutMSprite);
    //this->sunflower->update(worldPos);
    //this->peashooter->update(worldPos);
    //this->iceshooter->update(worldPos);
    //this->plantsHandler->update(worldPos, this->window , ev, sunflowerMSprite, peashooterMSprite, snowpeashooterMSprite , wallnutMSprite);
}
void Game::render() {

    this->window->clear(Color::Black);
    this->window->draw(backgroundSprite);
    this->window->draw(sunflowerMSprite);
    this->window->draw(peashooterMSprite);
    this->window->draw(snowpeashooterMSprite);
    this->window->draw(wallnutMSprite);
    score->render(window);
    handler->render(window);
    //plantsHandler->render(window);
    this->window->display();
  
}

// void Game::handle_mouse_press(Event ev) {
//   if (ev.mouseButton.button == Mouse::Right)
//     return;
//     sunflower->handle_mouse_press(ev , this->window);
//     //peashooter->handle_mouse_press(pos);
//     //iceshooter->handle_mouse_press(pos);

// }
// void Game::handle_mouse_release(Event ev) {
//   if (ev.mouseButton.button == Mouse::Right)
//     return;
//   Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
//   sunflower->handle_mouse_release(pos);
//   peashooter->handle_mouse_release(pos);
//   iceshooter->handle_mouse_release(pos);

// }

// void Game::handle_mouse_move(Event ev)
// {
//     sunflower->handle_mouse_move(ev , this->window);
// }
