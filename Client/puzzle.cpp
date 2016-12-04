#include "puzzle.h"

Puzzle::Puzzle() {
    b2Vec2 g(0,9.8);
    thisWorld = new b2World(g);
}

Puzzle::~Puzzle(){
    delete thisWorld;
}

void Puzzle::step(float time){
   thisWorld->Step(time,10,10);
   //apparently there are performance issues when the last two numbers are < 10
}

void Puzzle::addComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type){
    SpriteDefinition tempdef(x,y, type,name);
    tempdef.setShape(points,width,height); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *temp = new sprite2dObject(thisWorld,tempdef);
    components.push_back(temp);
}

void Puzzle::addIgnoredComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type){
    SpriteDefinition tempdef(x,y, type,name);
    tempdef.setShape(points,width,height); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *temp = new sprite2dObject(thisWorld,tempdef);
    inactive_components.push_back(temp);
}

void Puzzle::addComponent(SpriteDefinition def){
    sprite2dObject * temp = new sprite2dObject(thisWorld,def);
    components.push_back(temp);
}

void Puzzle::addIgnoredComponent(SpriteDefinition def){
    sprite2dObject * temp = new sprite2dObject(thisWorld,def);
    inactive_components.push_back(temp);
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

void Puzzle::establishGravity() {
    b2Vec2 graf(0,0.1); // gravity is set low here
    thisWorld->SetGravity(graf);
}

void Puzzle::establishFloor() {
    SpriteDefinition floordef(100,200, b2_staticBody,"floor");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    inactive_components.push_back(floor);
}

//here be dragons.
void Puzzle::garbageCollection(){
    int i = 0;
    for(auto it = inactive_components.begin(); it < inactive_components.end(); it++){
        sprite2dObject * obj = *it;
        if(obj==nullptr||obj->getBody()==nullptr){
            inactive_components.erase(inactive_components.begin()+i); // erase if we need to
            break;
        }
        else if(obj->isIgnored()){
            b2Vec2 vec(obj->getBody()->GetPosition());
            if(vec.x<-10000||vec.x>10000||vec.y>10000){ // magic numbers here << we should probably tie in some sort of size
                thisWorld->DestroyBody(obj->getBody());
                obj->destroy();
                inactive_components.erase(inactive_components.begin()+i); // erase if we need to
                break;
            }
        }
        i++;
    }
}
