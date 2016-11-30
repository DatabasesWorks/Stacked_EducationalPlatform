#ifndef SPRITE2DOBJECT_H
#define SPRITE2DOBJECT_H

#include "SFML/Graphics.hpp"
#include "Box2D/Dynamics/b2Body.h"
#include <Box2D.h>
#include <Box2D/Box2D.h>
#include <exceptions.h>

// A class to integrate SFML sprites with Box2D shapes and bodies.
class sprite2dObject{

public:

    sprite2dObject();
    sprite2dObject(std::string,b2World, b2BodyDef);
    b2Body * getBody();
    sf::Sprite * getSprite();

private:

    b2Body * body; //Body definitions
    sf::Sprite * sprite;
};

#endif // SPRITE2DOBJECT_H
