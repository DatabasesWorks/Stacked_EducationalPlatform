#include "puzzle.h"

Puzzle::~Puzzle(){

}


Puzzle::Puzzle(QSize size) {
    b2Vec2 gravity(0.0f, -10.0f);
    this->size=size;
    this->thisWorld = new b2World(gravity);
    this->numComponents = 0;
}

Puzzle::Puzzle(){

}

void Puzzle::step(float time){
   this->thisWorld->Step(time,1,1);
}


void Puzzle::addComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type){
    SpriteDefinition tempdef(x,y, type,name);
    tempdef.setShape(points,width,height); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *temp = new sprite2dObject(thisWorld,tempdef);
    components.push_back(temp);

}

void Puzzle::addComponent(sprite2dObject *obj){
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
                static_cast<sprite2dObject*>(*it)->setSprite(image);
                break;
            }
        }

    }else{
        // throw exception
    }
}
sprite2dObject Puzzle::getComponent(unsigned int i){
    return *components[i];
}

//polymorphic stuff
void Puzzle::runAction(Action){}

//returns vector of all of the sprites2dobjects/sprites
//(i.e. so they can be pulled and drawn by PuzzleWindow)
std::vector<sprite2dObject*> Puzzle::getAllComponents()
{
    return components;
}
