#ifndef SPRITE2DOBJECT_H
#define SPRITE2DOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/Joints/b2DistanceJoint.h>
#include <Box2D/Box2D.h>
#include <exceptions.h>
#include <spritedefinition.h>
#include <cmath>
#include <math.h>
#include <vector>

// A class to integrate SFML sprites with Box2D shapes and bodies.
class sprite2dObject{

public:
    enum Direction {
        left,right,up,down
    };

    sprite2dObject();
    ~sprite2dObject();
    sprite2dObject(std::string,b2World*, b2BodyDef*);
    sprite2dObject(b2World*,SpriteDefinition);
    b2Body * getBody();
    sf::ConvexShape* getShape();
    void push(Direction, int);
    void connect(sprite2dObject*,b2World*,int);

private:
    std::vector<b2Joint*> joints;
    b2Body * body;
    int width = 0;
    int height = 0;
    double SCALE=1;
};

#endif // SPRITE2DOBJECT_H
