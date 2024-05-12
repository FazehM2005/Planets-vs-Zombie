#include "sun.hpp"
#include "global.hpp"
#include "randomnum.hpp"


Sun::Sun()
{
    Suntexture.loadFromFile("sun.png");
    Sunsprite.setTexture(Suntexture);
    int randomSunPos = generateRandomNumber(1,4);
    switch(randomSunPos){
        case 1:
        Sunsprite.setPosition(352 , 0);
        break;
        case 2:
        Sunsprite.setPosition(493 , 0);
        break;
        case 3:
        Sunsprite.setPosition(668 , 0);
        break;
        case 4:
        Sunsprite.setPosition(826 , 0);
        break;
        default:
        break;
    }

    Sunsprite.setScale(0.07 , 0.07);
    IntRect sun_rect ;
    sun_rect.width = 750 ;
    sun_rect.height = 745 ;
    Sunsprite.setTextureRect(sun_rect);
}

Sun::~Sun()
{

}

void Sun::render(RenderWindow* window)
{   
    Sunsprite.move(0, 0.1);
    window->draw(Sunsprite);
}

bool Sun::contains(Vector2i &point)
{
    return Sunsprite.getGlobalBounds().contains(static_cast<float>(point.x) , static_cast<float>(point.y));
}
