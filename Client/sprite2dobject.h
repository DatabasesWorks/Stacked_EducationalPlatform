#ifndef SPRITE2DOBJECT_H
#define SPRITE2DOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
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
    sf::ConvexShape getShape();
    void destroy();
    void bindToMouse();
    void unbind();
    void moveBody(Direction, int);
    void moveToPoint(int,int);
    void applyAngularForce(Direction,double);
    void connectRope(sprite2dObject*);
    void connectBar(sprite2dObject*);
    void ignoreObject();
    bool isIgnored();
    void changeColor(sf::Color color);
    void setName(std::string);
    std::string getName();
    void setFriction(double);
    void setDensity(double);
    void setSprite(std::string pathname);
    void setText(std::string, sf::Color c = sf::Color::White);
    sf::Text getText();
    sf::Sprite * getSprite();
    void mark();
    bool marked();
    bool inContact(sprite2dObject* s);
    b2Vec2 getSize();
    void scaleSize(int factor);

private:
    sf::Text text;
    sf::Font font;
    bool ignore = false;
    bool remove = false;
    std::vector<b2Joint*> joints;
    std::string name;
    sf::Color color;
    b2Body * body;
    sf::Sprite * sprite;
    int width = 0;
    int height = 0;
    double SCALE=1;
};

#endif // SPRITE2DOBJECT_H
