#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.
sprite2dObject::sprite2dObject()
{
}

//sprite2dObject::sprite2dObject(b2BodyDef newBodyDef)
//{
//    bodyDef = newBodyDef;
//}

static sf::Sprite addTexture(std::string filename) {
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        // failed to load
    }
    sf::Sprite sprite(texture);
    return sprite;
}
