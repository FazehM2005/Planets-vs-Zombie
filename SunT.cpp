#include "Sun.hpp"
#include "global.hpp"
#include "randomNum.hpp"


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

    
    
    Sunsprite.setScale(0.45 , 0.45);
    Sunspeed = 0.01f;
}

Sun::~Sun()
{

}

void Sun::render(RenderWindow* window)
{   
    Sunsprite.move(0, Sunspeed);
    window->draw(Sunsprite);
}




