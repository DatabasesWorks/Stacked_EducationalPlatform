#ifndef SPRITEDEFINITION_H
#define SPRITEDEFINITION_H
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2Body.h>
#include <vector>
#include <string>
#include <SFML/Graphics/Color.hpp>

// a class to act as a template ( following the body definition approach )
class SpriteDefinition
{
public:
    SpriteDefinition(int, int, b2BodyType, std::string);
    SpriteDefinition();
    ~SpriteDefinition();
    void setText(std::string);
    void setDensity(double);
    void dampen(double amount);
    void setFriction(double);
    void setPosition(int,int);
    void setInitialVelocity(double,b2Vec2);
    void setColor(sf::Color);
    void setShape(int,int,int);
    void setType(b2BodyType);
    b2BodyDef * body;
    b2FixtureDef * fixture;
    std::string name;
    sf::Color color;
    std::string text;

};

#endif // SPRITEDEFINITION_H
