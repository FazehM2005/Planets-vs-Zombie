#include "system.hpp"



System::System(int width, int height){
        RenderWindow window{ VideoMode(width,height), "The game!" };
    backgroundT.loadFromFile("Backg.png");
    backgroundS.setTexture(backgroundT);
    while (window.isOpen())
        {
                Event windowEvent;
                while (window.pollEvent(windowEvent))
                {
                        if (windowEvent.type == Event::Closed)
                                window.close();
                }
                window.clear(Color::White);
                window.draw(backgroundS);
                window.display();
        }
}


System::~System() {}

