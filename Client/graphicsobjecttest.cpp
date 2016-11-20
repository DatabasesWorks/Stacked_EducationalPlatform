#include "graphicsobjecttest.h"

GraphicsObjectTest::GraphicsObjectTest(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime):
    GraphicsObject(Parent, Position, Size, 0)
{


}

GraphicsObjectTest::~GraphicsObjectTest()
{

}

void GraphicsObjectTest::OnInit()
{
    // Load the image
    myImage.loadFromFile("datas/qt/sfml.png");

    // Setup the sprite
    mySprite.setTexture(myImage);
    mySprite.setOrigin(mySprite.getScale() / 2.f);

}

void GraphicsObjectTest::OnUpdate()
{
    // Clear screen
    clear(sf::Color(0, 128, 0));

    // Rotate the sprite

    mySprite.rotate(rot++);

    // Draw it
    draw(mySprite);

}
