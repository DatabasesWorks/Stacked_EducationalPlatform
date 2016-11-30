#include "puzzle.h"

Puzzle::Puzzle(QSize size) {
    b2Vec2 gravity(0.0f, -10.0f);

    this->size=size;
    this->thisWorld = new b2World(gravity);
    this->numComponents = 0;
}

void Puzzle::addComponent(sprite2dObject obj){
    components.push_back(obj);
    numComponents++;
}

std::vector<sprite2dObject> Puzzle::getComponents(){
   return components;
}

int Puzzle::getnumComponents(){
    return numComponents;
}

void Puzzle::changeComponentImage(unsigned int, const QImage){
    //todo

}
sprite2dObject Puzzle::getComponent(unsigned int i){
    return components[i];
}

//polymorphic stuff
void Puzzle::runAction(Action){}
