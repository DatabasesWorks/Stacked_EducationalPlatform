#include "graphicsobjecttest.h"
#include <QDir>
#include <QString>

StackPuzzle test;


GraphicsObjectTest::GraphicsObjectTest(QWidget *Parent) :
    GraphicsObject(Parent) {
    currentPuzzle = new StackPuzzle;
//  testpuzzle = new TreePuzzle(s);

}

void GraphicsObjectTest::OnInit() {
    // any init code for the game environment
    updateSet();
}

void GraphicsObjectTest::updateSet(){
    drawnSprites.clear();
    std::vector<sprite2dObject*> objs = currentPuzzle->getAllComponents();
    for(auto ptr = objs.begin(); ptr < objs.end(); ptr++){
        sprite2dObject obj = (**ptr);
        drawnSprites.push_back(*obj.getShape());
    }
}

void GraphicsObjectTest::OnUpdate() {
    //Draw sprite on window
    currentPuzzle->step(.09);
    updateSet();
    for(auto it = drawnSprites.begin(); it < drawnSprites.end(); it++)
    {
        RenderWindow::draw(*it);
    }
}

#include <iostream>
//add some key capture for testing
void GraphicsObjectTest::keyPressEvent(QKeyEvent *event){
  currentPuzzle->runAction(Qt::Key(event->key()));
}
