#include "puzzle.h"

Puzzle::Puzzle(QSize size) {
    b2Vec2 gravity(0.0f, -10.0f);
    this->size=size;
    this->thisWorld = new b2World(gravity);
    this->numComponents = 0;
}

void Puzzle::addComponent(sprite2dObject obj){
    components.push_back(obj);
}

int Puzzle::getnumComponents(){
    return components.size();
}

void Puzzle::changeComponentImage(unsigned int i, sf::Image image){
    if(this->components.size()<i){
        unsigned int temp = 0;
        for(auto it = components.begin(); it < components.end(); it++){
            if(temp==i){
                static_cast<sprite2dObject>(*it).setSprite(image);
                break;
            }
        }

    }else{
        // throw exception
    }
}
sprite2dObject Puzzle::getComponent(unsigned int i){
    return components[i];
}

//polymorphic stuff
void Puzzle::runAction(Action){}

//returns vector of all of the sprites2dobjects/sprites
//(i.e. so they can be pulled and drawn by PuzzleWindow)
std::vector<sprite2dObject> Puzzle::getAllComponents()
{
    return components;
}
