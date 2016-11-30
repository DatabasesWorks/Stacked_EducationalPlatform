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
    ~sprite2dObject();
    sprite2dObject(std::string,b2World, b2BodyDef);
    b2Body * getBody();
    void setSprite(sf::Image);
    sf::Sprite * getSprite();
    void setFixture(b2FixtureDef);

private:
    b2Fixture * fixture;
    b2Body * body; //Body definitions
    sf::Sprite * sprite;
    double SCALE=1;
};

#endif // SPRITE2DOBJECT_H
