#include "puzzle.h"

Puzzle::Puzzle(QSize size) {
    this->size=size;
}

void Puzzle::addComponent(sprite2dObject){

//todo

}

void Puzzle::changeComponentImage(unsigned int, const QImage){}
sprite2dObject Puzzle::getComponent(unsigned int){}
void Puzzle::runAction(Action){}

//returns vector of all of the sprites2dobjects/sprites
//(i.e. so they can be pulled and drawn by PuzzleWindow)
std::vector<sprite2dObject> Puzzle::getAllComponents()
{
    return components;
}
