#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Sun.hpp"
#include "Sun.cpp"


int main() {
    RenderWindow window(VideoMode(800, 600), "Sunfall" );
    
    Sun sun(400, 0); // Initial position of the sun
    
    Clock clock;
    float sunSpawnTime = 5.0f; // Spawn a new sun every 5 seconds
    float elapsedTime = 0.0f;
    
    while (window.isOpen()) {
        Time dt = clock.restart();
        elapsedTime += dt.asSeconds();
        
        if (elapsedTime >= sunSpawnTime) {
            Sun newSun(rand() % 800, 0); // Randomize the x position of the new sun
            sun = newSun;
            elapsedTime = 0.0f;
        }
        
        sun.update();
        
        window.clear();
        sun.draw(window);
        window.display();
    }
    
    return 0;
}