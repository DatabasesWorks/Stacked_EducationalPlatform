#ifndef SPRITE2DOBJECT_H
#define SPRITE2DOBJECT_H

#include "SFML/Graphics.hpp"
//#include "Box2D/Dynamics/b2Body.h"

// A class to integrate SFML sprites with Box2D shapes and bodies.
class sprite2dObject : public sf::Sprite//, public b2Body
{
public:
    sprite2dObject();
    static sf::Sprite addTexture();

//private:
//    b2BodyDef bodyDef; //Body definitions
};

#endif // SPRITE2DOBJECT_H
