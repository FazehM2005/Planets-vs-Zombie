#include "handler.hpp"

Handler::Handler (){
   
}

Handler::~Handler(){
    for(auto z : zombies){
        delete z;
    }
    for(auto zy : zombieyeti){
        delete zy;
    }
    for(auto s : sun){
        delete s;
    }
}

void Handler::update(Vector2i* pos , RenderWindow* window){

    Time zelapsed = zombie_clock.getElapsedTime();
    if(zelapsed.asMilliseconds() >= 20000){
        zombie_clock.restart();
        add_zombie();
    }
        for(auto z : zombies){
        z->update(window);
    }
    Time zyelapsed = zombieyeti_clock.getElapsedTime();
    if(zyelapsed.asMilliseconds() >= 45000){
        zombieyeti_clock.restart();
        add_zombieyeti();
    }
        for(auto zy : zombieyeti){
        zy->update();
    }
    Time selapsed = sun_clock.getElapsedTime();
    if(selapsed.asMilliseconds() >= 4000){
        sun_clock.restart();
        add_sun(pos);
    }
}


void Handler::render(RenderWindow *window){
    for(auto z : zombies){
        z->render(window);
    }
    for(auto zy : zombieyeti){
        zy->render(window);
    }
    for(auto s : sun){
        if(rendered){
            s->render(window);   
        } 
    }
}
   
void Handler::add_zombie(){
    Zombie* z = new Zombie();
    zombies.push_back(z);
}

void Handler::add_zombieyeti(){
    ZombieYeti* z = new ZombieYeti();
    zombieyeti.push_back(z);
}

void Handler::add_sun(Vector2i* pos)
{
    Sun* s = new Sun();
    sun.push_back(s);
    if(s->contains(pos)){
        rendered = false ;
    }
}
