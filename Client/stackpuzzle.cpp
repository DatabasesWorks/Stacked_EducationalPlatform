#include "stackpuzzle.h"


StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {
    int x = 100;
    int y = -5;
    for(int i = 0; i < 5; i++) {
      b2BodyDef * myBody = new b2BodyDef;
      myBody->active=true;
      myBody->type = b2_dynamicBody;
      b2PolygonShape * rectShape = new b2PolygonShape;
      rectShape->SetAsBox(20, 5);
      b2FixtureDef * rectFixtureDef = new b2FixtureDef;
      rectFixtureDef->shape = rectShape;
      rectFixtureDef->density = 100;

      myBody->position.Set(x, y-(5*i));
      sprite2dObject * sprite = new sprite2dObject("stack_element_"+i, this->thisWorld, myBody);
      sprite->getBody()->CreateFixture(rectFixtureDef);
      components.push_back(sprite);
    }
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
