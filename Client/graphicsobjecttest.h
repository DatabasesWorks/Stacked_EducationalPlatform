#ifndef GRAPHICSOBJECTTEST_H
#define GRAPHICSOBJECTTEST_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>
#include <stackpuzzle.h>
#include <treepuzzle.h>
#include <sprite2dobject.h>
#include <vector>
#include <QSize>

//This is a demo of an object that inherits from the Graphics Object class to draw a sprite
class GraphicsObjectTest : public GraphicsObject
{
public :

    explicit GraphicsObjectTest(QWidget *Parent = 0);
    void onInit();
    void onUpdate();
    Puzzle * testpuzzle;
    std::vector<sf::ConvexShape>drawnSprites;

private:
    sf::Texture tex;
    sf::Sprite spr;
    void OnInit();
    void OnUpdate();
    void updateSet();
    float rot=1;

};

#endif // GRAPHICSOBJECTTEST_H
