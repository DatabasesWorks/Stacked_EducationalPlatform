#include "stackpuzzle.h"


StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {

    b2Vec2 graf(0,0.98); // normalish gravity
    thisWorld->SetGravity(graf);

    ssize.x=60;
    ssize.y=10;

    createBoundary(0,true);
    createBoundary(390,true);
    createBoundary(270,false);
//make platform independent------
    createStackContainer(100);
    for(int i =0; i < 5; i++)
        generateStackPiece(100);




}

void buildPuzzle(){


}



void StackPuzzle::createStackContainer(int x){
     SpriteDefinition left;
     SpriteDefinition right;
     left.setShape(4,0,800);
     left.setColor(sf::Color::Transparent);
     left.setBorderColor(sf::Color::Blue);
     right.setShape(4,0,800);
     right.setColor(sf::Color::Transparent);
     right.setBorderColor(sf::Color::Blue);
     left.setType(b2_staticBody);
     right.setType(b2_staticBody);
     left.setPosition(x-ssize.x,0);
     right.setPosition(x+ssize.x,0);
     addComponent(left,true);
     addComponent(right,true);
}

void StackPuzzle::createBoundary(int value, bool horz){

    SpriteDefinition def;
    def.setType(b2_staticBody);

    def.name="boundary_value"+value;
    def.color=sf::Color::Transparent;
    if(!horz){
        def.setPosition(0,value);
        def.setShape(4,1600,0);
    }else{
        def.setPosition(value,0);
        def.setShape(4,0,1200);
    }
    addComponent(def,true);

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

void StackPuzzle::generateStackPiece(int x){
    SpriteDefinition stack_p;
    stack_p.setShape(4,ssize.x,ssize.y);
    stack_p.setBorderColor(sf::Color::Green);
    stack_p.setDensity(50);
    stack_p.setColor(sf::Color::Red);
    stack_p.setPosition(x,0);
    stack_p.setText("rawr");
    stack_p.setType(b2_dynamicBody);
    addComponent(stack_p);
}

sprite2dObject * StackPuzzle::createNode(int x, int y, b2BodyType type){
    SpriteDefinition node;
    node.setType(type);
    node.setPosition(x,y);
    node.setShape(4,0,0);
    node.dampen(.1);
    node.setDensity(10);
    node.setColor(sf::Color::Blue);
    return new sprite2dObject(thisWorld,node);
}

#include <iostream>
void StackPuzzle::popAction(){
    if(components.size()<1)return;
    sprite2dObject * obj = (components.back());
    obj->moveBody(sprite2dObject::up,7);
   // obj->moveBody(sprite2dObject::right,100);
    obj->ignoreObject();
    inactive_components.push_back(obj);
    // inactive objects will be collected by garbage collection if they are too far out from the screens view ( besides from above )
    components.pop_back();
}

void StackPuzzle::pushAction(){
    generateStackPiece(100);
}
