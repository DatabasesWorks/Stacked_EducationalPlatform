#include "puzzle.h"

Puzzle::Puzzle() {
    b2Vec2 g(0,9.8);
    thisWorld = new b2World(g);
    size=size;
    numComponents = 0;
}

Puzzle::~Puzzle(){
    delete thisWorld;
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

void Puzzle::addInactiveComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type){
    SpriteDefinition tempdef(x,y, type,name);
    tempdef.setShape(points,width,height); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *temp = new sprite2dObject(thisWorld,tempdef);
    inactive_components.push_back(temp);
}

void Puzzle::addInactiveComponent(sprite2dObject *obj){
    inactive_components.push_back(obj);
}

void Puzzle::addComponent(sprite2dObject *obj){
    components.push_back(obj);
}

int Puzzle::getnumComponents(){
    return components.size();
}

sprite2dObject Puzzle::getComponent(unsigned int i){
    return *components[i];
}

//polymorphic stuff
void Puzzle::runAction(Qt::Key){}

//returns vector of all of the sprites2dobjects/sprites
//(i.e. so they can be pulled and drawn by PuzzleWindow)
std::vector<sprite2dObject*> Puzzle::getAllComponents()
{
    std::vector<sprite2dObject*> vec;
    vec.insert(vec.end(), components.begin(), components.end());
    vec.insert(vec.end(), inactive_components.begin(), inactive_components.end());
    return vec;
}
