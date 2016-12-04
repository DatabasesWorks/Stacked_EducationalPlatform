#include "listpuzzle.h"

ListPuzzle::ListPuzzle() : Puzzle() {
    establishGravity();
    establishFloor();

    this->addComponent("list body", 4, 10, 10, 100, 50, b2_dynamicBody);
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
    bod = components.back()->getBody();
    this->addComponent("list body", 4, 10, 10, bod->GetPosition().x - 10, bod->GetPosition().y - 10, b2_dynamicBody);
}

void ListPuzzle::pushBack(){
    this->addComponent("list body", 4, 10, 10, 100, 50, b2_dynamicBody);
}

void ListPuzzle::popFront(){
}

void ListPuzzle::popBack(){
}

void ListPuzzle::sortList(){
}
