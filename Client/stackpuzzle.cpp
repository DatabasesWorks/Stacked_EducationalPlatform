#include "stackpuzzle.h"



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
StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {

    b2Vec2 graf(0,0.98); // normalish gravity
    thisWorld->SetGravity(graf);

    //create a floor
    establishFloor();

    //or build a wall

    SpriteDefinition leftwalld(0,20, b2_staticBody,"leftwalld");
    leftwalld.setShape(4,0,500);
    leftwalld.setColor(sf::Color::Red);
    addComponent(leftwalld,true);


    int root_x = 100;
    int root_y = 1;
    int levelh = 50;
    sprite2dObject * root = createNode(root_x,root_y,b2_staticBody);


    SpriteDefinition pend;
    pend.setShape(4,50,50);
    pend.setPosition(100,120);
    pend.setDensity(1);
    pend.setColor(sf::Color::Red);
    pend.setType(b2_dynamicBody);
    sprite2dObject * underroot = new sprite2dObject(thisWorld,pend);
    root->connectRope(underroot);
    underroot->setSprite("");

    addComponent(root);
    addComponent(underroot);

    generateTree();



    for(int i = 0; i < 5; i++){
        generateStackPiece(400,i*-35);
    }
}  // or you can use the wrapper API below


//demo of using the rope and bar system
void StackPuzzle::generateTree(){

    int root_x = 100;
    int root_y = 50;
    int levelh = 50;

    // the only way I can think of not having to hard code these is using a recursive algorithm to build the tree
    sprite2dObject * root = createNode(root_x,root_y,b2_staticBody);
    sprite2dObject * underroot = createNode(root_x,root_y+levelh,b2_dynamicBody);
    sprite2dObject * hsp1_left = createNode(25,160,b2_dynamicBody);
    sprite2dObject * hsp1 = createNode(50,120,b2_dynamicBody);
    sprite2dObject * hsp1_right = createNode(75,160,b2_dynamicBody);
    sprite2dObject * hsp2_left = createNode(125,160,b2_dynamicBody);
    sprite2dObject * hsp2 = createNode(150,120,b2_dynamicBody);
    sprite2dObject * hsp2_right = createNode(175,160,b2_dynamicBody);

    root->changeColor(sf::Color::Yellow);

    hsp1->changeColor(sf::Color::Red);
    hsp2->changeColor(sf::Color::Green);

    SpriteDefinition def;
    def.setText("RRRRRRRRRRRRRAWWWWWWWWWWWWWWWWWWWR");
    def.setShape(4,40,40);
    def.setType(b2_dynamicBody);
    def.setDensity(1);
    def.setColor(sf::Color::Green);
    def.setPosition(10,100);
    addComponent(def,true);

    //create the body connections
    //bars are solid and will hold objects away at a fixed point
    //ropes will let the object swing. ( they aren't springy though unfortunately )
    root->connectRope(underroot);

    underroot->connectRope(hsp1);
    underroot->connectRope(hsp2);
    hsp1->connectBar(hsp2);

    hsp1->connectRope(hsp1_left);
    hsp1->connectRope(hsp1_right);
    hsp2->connectRope(hsp2_left);
    hsp2->connectRope(hsp2_right);

    hsp2_left->connectBar(hsp2_right);
    hsp1_left->connectBar(hsp1_right);

    //add all the components
    addComponent(root,true);
    addComponent(underroot,true);// the flags must be true if the objects aren't part of the collection
    addComponent(hsp1,true);
    addComponent(hsp2,true);
    addComponent(hsp1_left,true);
    addComponent(hsp2_left,true);
    addComponent(hsp1_right,true);
    addComponent(hsp2_right,true);
}

void StackPuzzle::generateStackPiece(int x, int y){
    SpriteDefinition stack_p;
    stack_p.setShape(4,20,1);
    stack_p.setFriction(0); // wraps the fixture and bodydef into one entity
    b2Vec2 vec(0,0);
    stack_p.setInitialVelocity(0,vec);
    stack_p.setDensity(55);
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
   // obj->moveBody(sprite2dObject::right,100);
    obj->ignoreObject();
    inactive_components.push_back(obj);
    // inactive objects will be collected by garbage collection if they are too far out from the screens view ( besides from above )
    components.pop_back();
}

void StackPuzzle::pushAction(){
    generateStackPiece(100,-200);
}
