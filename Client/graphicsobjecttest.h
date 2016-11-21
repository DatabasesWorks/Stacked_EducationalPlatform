#ifndef GRAPHICSOBJECTTEST_H
#define GRAPHICSOBJECTTEST_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>

//This is a demo of an object that inherits from the Graphics Object class to draw a sprite
class GraphicsObjectTest : public GraphicsObject
{
public :

    explicit GraphicsObjectTest(QWidget *Parent = 0);
    void onInit();
    void onUpdate();

private:
    sf::Texture tex;
    sf::Sprite spr;
    void OnInit();
    void OnUpdate();
    float rot=1;

};

#endif // GRAPHICSOBJECTTEST_H
