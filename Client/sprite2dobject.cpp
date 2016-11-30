#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.

sprite2dObject::sprite2dObject(std::string filename, b2World world, b2BodyDef def) // call the super constructor
{
    sf::Texture texture;
    if(!texture.loadFromFile(imagename)){
        //throw exception
        filenotfoundexception ex(filename);
        throw ex;
    }
    sprite=new sf::Sprite(texture);
    body = world.CreateBody(&def);

}

sf::Sprite * sprite2dObject::getSprite(){
    return sprite;
}

b2Body * sprite2dObject::getBody(){
    return body;
}
