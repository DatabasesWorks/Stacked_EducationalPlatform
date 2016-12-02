#include "stackpuzzle.h"


StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {
    int x = 100;
    int y = -5;
     b2Vec2 graf(0,-.001);
    thisWorld->SetGravity(graf);
    SpriteDefinition def(100,10, b2_dynamicBody,"testbox");
    def.setShape(3,0,0);
    sprite2dObject *sprite = new sprite2dObject(thisWorld,def);

    SpriteDefinition def2(100,20, b2_dynamicBody,"testbox");
    def2.setShape(4,100,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *sprite2 = new sprite2dObject(thisWorld,def2);

    components.push_back(sprite);
    components.push_back(sprite2);

}











StackPuzzle::StackPuzzle() : Puzzle() {

}

StackPuzzle::~StackPuzzle() {

}

void StackPuzzle::runAction(Action action){
   std::string d  = action.description;

   if(d == "pop"){
       popAction();
   }
   if(d == "push"){
       pushAction();
   }

}
std::string StackPuzzle::peekAction(){
   //need to extract component content string
   std::string s = "";
   return s;
}

void StackPuzzle::popAction(){
    b2Body * bod;
    bod = components.front()->getBody();
    bod->ApplyAngularImpulse(20, true);
    components.erase(components.begin());
}

void StackPuzzle::pushAction(){
//    b2BodyDef * myBody = new myBody;
//    b2PolygonShape rectShape;
//    rectShape.SetAsBox(2, 1);
//    b2FixtureDef rectFixtureDef;
//    rectFixtureDef.shape = &rectShape;
//    rectFixtureDef.density = 1;

//    myBody.position.Set(0, 0);
//    sprite2dObject * sprite = new sprite2dObject("", *this->thisWorld, myBody);
//    sprite->setFixture(rectFixtureDef);
//    components.push_back(sprite);

}
