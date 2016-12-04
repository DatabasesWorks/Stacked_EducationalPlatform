#include "listpuzzle.h"

ListPuzzle::ListPuzzle() : Puzzle() {
    establishGravity();
    establishFloor();

    this->addComponent("list body", 4, 10, 10, 100, -200, b2_dynamicBody);
}

void ListPuzzle::pushFront(){

}

void ListPuzzle::pushBack(){

}

void ListPuzzle::popFront(){

}

void ListPuzzle::popBack(){

}

void ListPuzzle::sortList(){

}
