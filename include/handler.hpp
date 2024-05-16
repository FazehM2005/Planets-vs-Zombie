#pragma once

#include "global.hpp"
#include "zombie.hpp"
#include "zombieyeti.hpp"
#include "sun.hpp"
#include "projectile.hpp"
#include "peashooter.hpp"
#include "iceshooter.hpp"   
#include "sunflower.hpp"
#include "wallnut.hpp"

class Handler{
public:
    Handler();
    ~Handler();
    void update(Vector2i* pos , RenderWindow* window , Event ev, Sprite sunflowerMSprite, Sprite peashooterMSprite, Sprite snowpeashooterMSprite , Sprite wallnutMSprite);
    void render(RenderWindow *window);
    bool rendered = true ;
    int wallnutnerf = 500 ;
private:
    Font scoreFont;
    Text scoreText;
    int score = 50;
    mt19937 rng;
    Clock zombie_clock , zombieyeti_clock , sun_clock , wremove_clock , clock; 
    Peashooter* peashooter;
    vector < Zombie* > zombies;
    vector < ZombieYeti* > zombieyeti;
    vector <Sun*> sun;
    vector <Projectile *> projectiles;
    vector<Sunflower *> sunflowers;
    vector<Peashooter *> peashooters;
    vector<Iceshooter *> iceshooters;
    vector<Wallnut *> wallnuts;
    void add_zombie();
    void add_zombieyeti();
    void add_sun(Vector2i* pos);
    void add_sunflower();
    void add_peashooter();
    void add_iceshooter();
    void add_wallnut();
    void handle_collision();

};