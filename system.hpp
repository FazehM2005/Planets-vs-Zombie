#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace sf;


class System {
    public:
    System(int width, int height);
    virtual ~System();
    RenderWindow window;
    //void render(int width, int height);
    
    private:
    Texture backgroundT;
    Sprite backgroundS;

};