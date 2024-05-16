#include "projectile.hpp"

Projectile::Projectile(Vector2f p){
    pos = p;
    texture.loadFromFile(PICS_PATH + "peaprojectile.png") ;
    sprite.setTexture(texture);
    sprite.setScale(0.07, 0.07);
}

Projectile::~Projectile(){

}

void Projectile::render(RenderWindow* window){
    window->draw(sprite);
}

void Projectile::update(){
    pos.x += speed ;
    sprite.setPosition(pos);
}

bool Projectile::is_out(){
    return sprite.getPosition().x > WIDTH + 50;
}

FloatRect Projectile::get_rect(){
    return sprite.getGlobalBounds();
}