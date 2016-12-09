#include "stackpuzzle.h"
#include <sstream>

StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {

    b2Vec2 graf(0,0.98); // normalish gravity
    thisWorld->SetGravity(graf);

    ssize.x=60;
    ssize.y=10;

    createBoundary(0,true);
    createBoundary(390,true);
    createBoundary(270,false);

    instructionstream << "Keys:" << std::endl;
    instructionstream << "Press R to push a random value to the stack," << std::endl <<
                         "Press E to pop and ignore the value" << std::endl <<
                         "Press W to pop into the pit" << std::endl <<
                         "Press Space to drop an operator into the pit" <<std::endl <<
                         "Use the Arrow Keys to Change Operator" << std::endl;

    b2Vec2 pos(250,40);
    createInstructions(pos);
    buildPuzzle();
    b2Vec2 pos2(300,150);
    instructionstream.str("");
    instructionstream << "Operators" << std::endl;
    createInstructions(pos2);


    setActiveOperator(operatorindex);


//make platform independent------
    createStackContainer(100);
    for(int i =0; i < 5; i++)
        generateStackPiece(100,0-i*20);




 }

void StackPuzzle::buildPuzzle(){
     SpriteDefinition mul;
     SpriteDefinition div;
     SpriteDefinition plus;
     SpriteDefinition minus;
     mul.name="mul";
     div.name="div";
     plus.name="plus";
     minus.name="minus";
     mul.setText("*");
     div.setText("/");
     plus.setText("+");
     minus.setText("-");

     //try to clean up the code a bit
     std::vector<SpriteDefinition*> defs;
     defs.push_back(&mul);
     defs.push_back(&div);
     defs.push_back(&plus);
     defs.push_back(&minus);

     int startingindex = 400;
     for(auto it = defs.begin(); it < defs.end(); it++){
        int halfs =25;
        SpriteDefinition * def = *it;
        def->setShape(4,halfs,halfs);
        def->setType(b2_staticBody);
        def->setPosition(startingindex,300);
        def->setColor(sf::Color::Green);
        def->setBorderColor(sf::Color::White);
        sprite2dObject * obj = new sprite2dObject(thisWorld,*def);
        obj->ignoreObject();
        addComponent(obj,true);
        operators.push_back(obj);
        startingindex+=halfs*1.5;
     }
}

void StackPuzzle::createStackContainer(int x){
     SpriteDefinition left;
     SpriteDefinition right;
     std::vector<SpriteDefinition*> defs;
     defs.push_back(&left);
     defs.push_back(&right);
     for(auto it = defs.begin(); it < defs.end(); it++){
         SpriteDefinition * def = *it;
         def->setShape(4,0,400);
         def->setShape(4,0,400);
         def->setColor(sf::Color::Transparent);
         def->setBorderColor(sf::Color::Blue);
         def->setType(b2_staticBody);
     }
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

void StackPuzzle::setActiveOperator(unsigned int toset){
    unsigned int c = 0;
    if(toset < operators.size()){
        operatorindex = toset;
        for(auto it = operators.begin(); it < operators.end(); it++){
            sprite2dObject * spr = *it;
            if(c==operatorindex){
                spr->changeColor(sf::Color::Blue);
            }
            else{
                spr->changeColor(sf::Color::Green);
            }
            c++;
        }
    }
}

void StackPuzzle::runAction(Qt::Key key){
   if(key==Qt::Key_E){
       popAction();
   }else
   if(key==Qt::Key_R){
       pushAction();
   }else
   if(key==Qt::Key_Left){
      if(operatorindex>0){
        operatorindex--;
        setActiveOperator(operatorindex);
      }
   }else
   if(key==Qt::Key_Right){
      if(operatorindex<3){
        operatorindex++;
        setActiveOperator(operatorindex);
      }
   }//else

}




std::string StackPuzzle::peekAction(){
   //need to extract component content string
   std::string s = "";
   return s;
}

void StackPuzzle::generateStackPiece(int x,int y){
    SpriteDefinition stack_p;
    stack_p.setShape(4,ssize.x,ssize.y);
    stack_p.setBorderColor(sf::Color::Green);
    stack_p.setDensity(50);
    stack_p.setColor(sf::Color::Red);
    stack_p.setText("1");
    stack_p.setPosition(x,y);
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
    generateStackPiece(100,0);
}
