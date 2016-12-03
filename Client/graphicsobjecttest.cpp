#include "graphicsobjecttest.h"
#include <QDir>
#include <QString>



StackPuzzle test;
//This is a demo of an object that inherits from the Graphics Object class to draw a sprite
GraphicsObjectTest::GraphicsObjectTest(QWidget *Parent) :
    GraphicsObject(Parent) {
    QSize s(100,100);
//    testpuzzle = new StackPuzzle(s);
    testpuzzle = new TreePuzzle(s);
}

void GraphicsObjectTest::OnInit() {


    updateSet();

    //There may be better way to get directory
    //Q_INIT_RESOURCE(sprites);
    //QFile f(":/spritesheet.png");
    //f.copy(QString("spritesheet.png"));

    //load the png that will be the "sprite"
//    if (!tex.loadFromFile("spritesheet.png")) {
//        //Error handling
//        std::cout << "Failed to find texture" << std::endl;
//    }

//    // Setup the sprite
//    spr.setTexture(tex);

//    //starting location of sprite
//    spr.setPosition(sf::Vector2f(300, 200));
}


void GraphicsObjectTest::updateSet(){
    drawnSprites.clear();
    std::vector<sprite2dObject*> objs = testpuzzle->getAllComponents();
    for(auto ptr = objs.begin(); ptr < objs.end(); ptr++){
        sprite2dObject obj = (**ptr);
        drawnSprites.push_back(*obj.getShape());
    }
}


void GraphicsObjectTest::OnUpdate() {
    //Draw sprite on window
    this->testpuzzle->step(1);
    updateSet();
    for(auto it = drawnSprites.begin(); it < drawnSprites.end(); it++)
    {
        sf::ConvexShape obj = static_cast<sf::ConvexShape>(*it);
        sf::Vector2f d= obj.getPosition();
        std::cout << d.x << d.y << std::endl;
         RenderWindow::draw(*it);
    }

}
