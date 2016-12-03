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
#include <QKeyEvent>

//This is a demo of an object that inherits from the Graphics Object class to draw a sprite
class GraphicsObjectTest : public GraphicsObject
{
public :

    explicit GraphicsObjectTest(QWidget *Parent = 0);
    void onInit();
    void onUpdate();
<<<<<<< HEAD
    Puzzle * currentPuzzle;
=======
    Puzzle * testpuzzle;
>>>>>>> e018ccd22082672e0d9a99c4795f90edbeef269d
    std::vector<sf::ConvexShape>drawnSprites;

private:
    sf::Texture tex;
    sf::Sprite spr;
    void OnInit();
    void OnUpdate();
    void updateSet();
    float rot=1;

protected:
    void keyPressEvent(QKeyEvent*);

};

#endif // GRAPHICSOBJECTTEST_H
