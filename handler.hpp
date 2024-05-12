#pragma once

#include "global.hpp"
#include "zombie.hpp"
#include "zombieyeti.hpp"
#include "sun.hpp"

class Handler{
public:
    Handler ();
    ~Handler();
    void update(Vector2i* pos , RenderWindow* window);
    void render(RenderWindow *window);
    bool rendered = true ;
private:
    mt19937 rng;
    Clock zombie_clock , zombieyeti_clock , sun_clock; 
    vector < Zombie* > zombies;
    vector < ZombieYeti* > zombieyeti;
    vector <Sun*> sun;
    void add_zombie();
    void add_zombieyeti();
    void add_sun(Vector2i* pos);
};