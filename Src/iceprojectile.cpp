#include "iceprojectiles.hpp"

Iceprojectile::Iceprojectile(Vector2f p){
    pos = p;
    texture.loadFromFile(PICS_PATH + "Iceprojectile.png") ;
    sprite.setTexture(texture);
    sprite.setScale(0.07, 0.07);
}

Iceprojectile::~Iceprojectile(){

}

void Iceprojectile::render(RenderWindow* window){
    window->draw(sprite);
}

void Iceprojectile::update(){
    pos.x += speed ;
    sprite.setPosition(pos);
}

bool Iceprojectile::is_out(){
    return sprite.getPosition().x > WIDTH + 50;
}

FloatRect Iceprojectile::get_rect(){
    return sprite.getGlobalBounds();
}