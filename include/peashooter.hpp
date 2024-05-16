#pragma once

#include "global.hpp"
#include "projectile.hpp"

class Peashooter{
public:
    Peashooter(int x, int y);
    ~Peashooter();
    void render(RenderWindow *window);
    void update();
    void handle_event(Event ev , RenderWindow* window);
    vector<Projectile*> get_projectiles(){return projectiles;};
    void set_projectiles(const vector <Projectile*> newProjectiles){
        projectiles = newProjectiles;
    }
    
private:
    Clock clock , prclock;
    Texture peashootertexture;
    Sprite peashootersprite;
    IntRect rect;
    Vector2f pos;
    Vector2f offset;
    Vector2f projectile_pos;
    vector <Projectile*> projectiles;
    bool is_tagged = false;
    int poses[11] = {0,935,1880,2827,3776,4721,5668,6614,7577,8511,9407};
    int cur_rect = 0 ;
};