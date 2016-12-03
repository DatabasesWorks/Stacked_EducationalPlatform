#include "stackpuzzle.h"

StackPuzzle::StackPuzzle() : Puzzle() {

    b2Vec2 graf(0,0.1); // gravity is set low here
    thisWorld->SetGravity(graf);

    //create a floor
    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    inactive_components.push_back(floor);

    //or alternatively
    for(int i = 0; i < 5; i++){
        this->addComponent("stack_"+i,4,100,5,100,-200+(i*35),b2_dynamicBody);
    }
}

StackPuzzle::~StackPuzzle() {

}

void StackPuzzle::runAction(Qt::Key key){
   if(key==Qt::Key_E){
       popAction();
   }
   if(key==Qt::Key_R){
       pushAction();
   }
}

std::string StackPuzzle::peekAction(){
   //need to extract component content string
   std::string s = "";
   return s;
}

#include <iostream>
void StackPuzzle::popAction(){
    if(components.size()<1)return;
    std::cout << "popping" << std::endl;
    sprite2dObject * obj = (components.front());
    obj->push(sprite2dObject::up,10000);
    inactive_components.push_back(obj);
    components.erase(components.begin());
}

void StackPuzzle::pushAction(){
    addComponent("stack_"+components.size(),4,100,5,100,-200,b2_dynamicBody);
}
