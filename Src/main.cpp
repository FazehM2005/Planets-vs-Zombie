#include <iostream>

#include "Game.hpp"
#include "global.hpp"

using namespace std;


int main()
{
    Game game;

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;

}

