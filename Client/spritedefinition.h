#ifndef SPRITEDEFINITION_H
#define SPRITEDEFINITION_H
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2Body.h>
#include <vector>
#include <string>
#include <SFML/Graphics/Color.hpp>

class SpriteDefinition
{
public:
    b2BodyDef * body;
    std::vector<b2FixtureDef *> fixtures;
    SpriteDefinition(int, int, b2BodyType, std::string);
    SpriteDefinition();
    ~SpriteDefinition();
    std::string name;
    sf::Color color;
    void setColor(sf::Color);
    void friction(bool);
    void setShape(int,int,int);

};

#endif // SPRITEDEFINITION_H
