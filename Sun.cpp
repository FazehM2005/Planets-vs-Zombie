#include "Sun.hpp"


Sun::Sun(float x, float y) {
    //RenderWindow window{ VideoMode(800,600), "The sun!" };
    texture.loadFromFile("sun.png");
    //sprite.setTexture(texture);
    /*while (window.isOpen())
        {
                Event windowEvent;
                while (window.pollEvent(windowEvent))
                {
                        if (windowEvent.type == Event::Closed)
                                window.close();
                }
                
                window.draw(sprite);
                window.display();
        }*/
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.45 , 0.45);
    speed = 0.01f; // Adjust speed as needed
}

void Sun::update() {
    sprite.move(0, speed);
}

void Sun::draw(sf::RenderWindow& window) {
    window.clear(Color::Black);
    window.draw(sprite);
    window.display();
}