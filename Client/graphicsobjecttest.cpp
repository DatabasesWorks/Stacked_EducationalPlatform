#include "graphicsobjecttest.h"
#include <QDir>
#include <QString>


//This is a demo of an object that inherits from the Graphics Object class to draw a sprite
GraphicsObjectTest::GraphicsObjectTest(QWidget *Parent) :
    GraphicsObject(Parent) {
}

void GraphicsObjectTest::OnInit() {
    //There may be better way to get directory
    Q_INIT_RESOURCE(sprites);
    QFile f(":/spritesheet.png");
    f.copy(QString("spritesheet.png"));

//***DELETE****
//    QString qst = f.filname;
//    std::string filepath = qst.toStdString();
//    std::cout<<filepath;

//    QDir dir = QDir::current();
//    dir.cdUp();
//    dir.absoluteFilePath("spritesheet.png");
//    QString qst = dir.currentPath();
//    std::string filepath = qst.toStdString();
//    std::cout<<filepath;
//****END DELETE***/////

    //load the png that will be the "sprite"
    if (!tex.loadFromFile("spritesheet.png")) {
        //Error handling
        std::cout << "Failed to find texture" << std::endl;
    }

    // Setup the sprite
    spr.setTexture(tex);

    //starting location of sprite
    spr.setPosition(sf::Vector2f(300, 200));
}

void GraphicsObjectTest::OnUpdate() {
    //Draw sprite on window
    RenderWindow::draw(spr);

    //Manipulate the sprite
    spr.rotate(rot);
    rot += .001;
}
