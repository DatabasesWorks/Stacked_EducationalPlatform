#include "listpuzzle.h"

ListPuzzle::ListPuzzle(QSize size) : Puzzle(size) {
    establishGravity();
    establishFloor();

    this->addComponent("list body", 4, CubeSideLength, CubeSideLength, 100, YSpawn, b2_dynamicBody);
}

ListPuzzle::~ListPuzzle(){

}

void ListPuzzle::runAction(Qt::Key key) {
    if (key == Qt::Key_Left) {
        pushFront();
    } else if (key == Qt::Key_Right) {
        pushBack();
    }
}

void ListPuzzle::pushFront(){
    b2Body *bod;
    bod = components.front()->getBody();
    this->addComponent("list body", 4, 10, 10, bod->GetPosition().x - 10, bod->GetPosition().y, b2_dynamicBody, false, true);
}

void ListPuzzle::pushBack(){
    b2Body *bod;
    bod = components.back()->getBody();
    this->addComponent("list body", 4, 10, 10, bod->GetPosition().x + 10, bod->GetPosition().y, b2_dynamicBody);
}

void ListPuzzle::popFront(){
}

void ListPuzzle::popBack(){
}

void ListPuzzle::sortList(){
}
