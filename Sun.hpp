#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Sun{

public:
    Sun(float x, float y);
    
    void update();
    void draw(RenderWindow& window);

private:
    Sprite sprite;
    Texture texture;
    float speed;
};
