#include "stackpuzzle.h"

StackPuzzle::StackPuzzle() : Puzzle() {

    b2Vec2 graf(0,0.09); // gravity is set low here
    thisWorld->SetGravity(graf);

    //create a floor
    establishFloor();

    //or build a wall
    SpriteDefinition leftwalld(0,0, b2_staticBody,"leftwalld");
    leftwalld.setShape(4,0,500);
    leftwalld.setColor(sf::Color::Red);
    addComponent(leftwalld,true);

    //one-liner
    addComponent("rightwalld",4,0,500,200,0,b2_staticBody, true);

    for(int i = 0; i < 5; i++){
        generateStackPiece(100,i*-35);
    }
}  // or you can use the wrapper API below

void StackPuzzle::generateStackPiece(int x, int y){
    SpriteDefinition stack_p;
    stack_p.setShape(4,100,5);
    stack_p.setFriction(0); // wraps the fixture and bodydef into one entity
    b2Vec2 vec(0,0);
    stack_p.setInitialVelocity(0,vec);
    stack_p.setDensity(5);
    stack_p.setColor(sf::Color::Cyan);
    stack_p.setPosition(x,y);
    stack_p.setType(b2_dynamicBody);
    addComponent(stack_p);
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
    sprite2dObject * obj = (components.back());
    obj->moveBody(sprite2dObject::up,7);
    obj->moveBody(sprite2dObject::right,10);
    obj->ignoreObject();
    inactive_components.push_back(obj);
    // inactive objects will be collected by garbage collection if they are too far out from the screens view ( besides from above )
    components.pop_back();
}

void StackPuzzle::pushAction(){
    generateStackPiece(100,-200);
}
