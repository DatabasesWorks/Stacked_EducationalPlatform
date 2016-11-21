#include "graphicsobjecttest.h"

GraphicsObjectTest::GraphicsObjectTest(QWidget* Parent):
    GraphicsObject(Parent)
{


}

void GraphicsObjectTest::OnInit()
{
    if(!tex.loadFromFile("/Users/tgardner/CS3505/A7/cs3505-a7-sprite-editor-stragglers/spritesheet.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
    }

    // Setup the sprite
    spr.setTexture(tex);
    spr.setPosition(sf::Vector2f(300, 200));

}

void GraphicsObjectTest::OnUpdate()
{

    RenderWindow::draw(spr);

//    // Rotate the sprite

//    mySprite.rotate(rot++);

//    // Draw it
//    draw(mySprite);

}
