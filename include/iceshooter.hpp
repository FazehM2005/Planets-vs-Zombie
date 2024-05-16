#pragma once

#include "global.hpp"
#include "iceprojectiles.hpp"


class Iceshooter{
public:
    Iceshooter(int x, int y);
    ~Iceshooter();
    void render(RenderWindow *window);
    void update();
    void handle_event(Event ev , RenderWindow* window);
    vector <Iceprojectile*> get_projectiles(){return iceprojectiles;};
private:
    Clock clock , prclock;
    Texture Iceshootertexture;
    Sprite Iceshootersprite;
    IntRect rect;
    Vector2f pos;
    Vector2f offset ;
    Vector2f projectile_pos;
    vector <Iceprojectile*> iceprojectiles;
    bool is_tagged = false;
    int poses[11] = {0,943,1890,2837,3787,4729,5675,6617,7545,8472,9386};
    int cur_rect = 0 ;
};