#include "stackpuzzle.h"

StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {

    b2BodyDef myBody;
    b2PolygonShape rectShape;
    rectShape.SetAsBox(2, 1);
    b2FixtureDef rectFixtureDef;
    rectFixtureDef.shape = &rectShape;
    rectFixtureDef.density = 1;

    int x = 0;
    int y = 0;
    std::string st = "";
    for(int i = 0; i < 5; i++) {
       myBody.position.Set(x, y+(2*i));
       sprite2dObject * sprite = new sprite2dObject(st, this->thisWorld, myBody);
       sprite.setFixture(rectFixtureDef);
       components.push_back(sprite);
    }
}

StackPuzzle::~StackPuzzle(){

}

void StackPuzzle::runAction(Action action){

   double accel = action.acceleration;
   double veloc = action.velocity;
   double direct = action.direction;
   std::string d  = action.description;
   b2Body * bod;
   if(d == "pop"){
       popAction(bod);
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

void StackPuzzle::popAction(b2Body* bod){
    bod = components.front()->getBody();
    bod->ApplyAngularImpulse(20, true);
    components.erase(components.begin());
}

void StackPuzzle::pushAction(){
    b2BodyDef myBody;
    b2PolygonShape rectShape;
    rectShape.SetAsBox(2, 1);
    b2FixtureDef rectFixtureDef;
    rectFixtureDef.shape = &rectShape;
    rectFixtureDef.density = 1;

    myBody.position.Set(0, 0);
    sprite2dObject * sprite = new sprite2dObject("", this->thisWorld, myBody);
    sprite.setFixture(rectFixtureDef);
    components.push_back(sprite);

}
