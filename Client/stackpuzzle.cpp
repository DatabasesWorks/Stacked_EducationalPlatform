#include "stackpuzzle.h"


StackPuzzle::StackPuzzle(QSize size) : Puzzle(size) {

    b2Vec2 graf(0,1.1);
    thisWorld->SetGravity(graf);
    SpriteDefinition triangledef(100,10,b2_dynamicBody,"testbox");
    triangledef.setShape(3,0,0);
    sprite2dObject *triangle = new sprite2dObject(thisWorld,triangledef);
    components.push_back(triangle);

    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    components.push_back(floor);


    //or alternatively
    for(int i = 0; i < 5; i++){
        this->addComponent("stack_"+i,4,100,5,100,50+(i*10),b2_dynamicBody);
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
