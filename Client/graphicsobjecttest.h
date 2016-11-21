#ifndef GRAPHICSOBJECTTEST_H
#define GRAPHICSOBJECTTEST_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>

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
    int rot=1;

};

#endif // GRAPHICSOBJECTTEST_H
