#include "stackpuzzle.h"

StackPuzzle::StackPuzzle() : Puzzle() {

    b2Vec2 graf(0,0.09); // gravity is set low here
    thisWorld->SetGravity(graf);

    //create a floor
    SpriteDefinition ceilingd(0,0, b2_staticBody,"ceiling");
    SpriteDefinition floord(0,200, b2_staticBody,"floor");
    SpriteDefinition leftwalld(0,0, b2_staticBody,"leftwalld");
    SpriteDefinition rightwalld(200,0, b2_staticBody,"rightwalld");

    ceilingd.setShape(4,1000,0);
    ceilingd.setColor(sf::Color::Yellow);
    floord.setShape(4,1000,0);
    floord.setColor(sf::Color::Blue);
    leftwalld.setShape(4,0,1000);
    leftwalld.setColor(sf::Color::Red);
    rightwalld.setShape(4,0,400);
    rightwalld.setColor(sf::Color::White);

    //  sprite2dObject *ceiling = new sprite2dObject(thisWorld,ceilingd);
    sprite2dObject *floor = new sprite2dObject(thisWorld,floord);
    sprite2dObject *lwall = new sprite2dObject(thisWorld,leftwalld);
    sprite2dObject *rwall = new sprite2dObject(thisWorld,rightwalld);

   // inactive_components.push_back(ceiling);
    inactive_components.push_back(floor);
    inactive_components.push_back(lwall);
    inactive_components.push_back(rwall);

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
    obj->moveBody(sprite2dObject::up,7);
    obj->moveBody(sprite2dObject::right,10);
    inactive_components.push_back(obj);
    components.erase(components.begin());
}

void StackPuzzle::pushAction(){
    addComponent("stack_"+components.size(),4,100,5,100,-200,b2_dynamicBody);
}
