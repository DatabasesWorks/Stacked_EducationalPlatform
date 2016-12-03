#include "arraypuzzle.h"
ArrayPuzzle::ArrayPuzzle() : Puzzle() {
    int x = 100;
    int y = -5;
    for(int i = 0; i < 5; i++){
        b2BodyDef * myBody = new b2BodyDef;
        myBody->active = true;
        myBody->type = b2_dynamicBody;
        b2PolygonShape * rectShape = new b2PolygonShape;
        rectShape->SetAsBox(20, 5);
        b2FixtureDef * rectFixtureDef = new b2FixtureDef;
        rectFixtureDef->shape = rectShape;
        rectFixtureDef->density = 1;

        myBody->position.Set(x-(5*i), y);
        sprite2dObject * sprite = new sprite2dObject("array_element_"+i, this->thisWorld, myBody);
        sprite->getBody()->CreateFixture(rectFixtureDef);
        components.push_back(sprite);
    }
}


ArrayPuzzle::~ArrayPuzzle() {}

void ArrayPuzzle::runAction(Qt::Key action){
    //std::string d = action.description;
    std::string d = "something";// "figured we can use keystrokes as a universal selector"
    int ind = 0;
    //maybe we can append the index to the end of the
    //description, remove it and use it as the index,
    //or we can just add an index property to the action class
    if(d == "delete"){
        deleteAtIndexAction(ind);
    }
    if(d == "add"){
       // addAtIndexAction(ind, );
    }
    if(d == "sort"){
        sortArrayAction();
    }
}

void ArrayPuzzle::deleteAtIndexAction(int ind){
    b2Body *bod;
    switch (components.size()) {
    case 1:
        bod = components[ind]->getBody();
        this->thisWorld->DestroyBody(bod);
        break;
    default:
        bod = components[ind]->getBody();
        this->thisWorld->DestroyBody(bod);
        for(int i = ind+1; i < components.size(); i++){
            bod = components[i]->getBody();
            bod->SetTransform(b2Vec2(-40, 0), 0);
        }
        break;
    }
}

//void ArrayPuzzle::addAtIndexAction(int ind, sprite2dObject obj){
//}

void ArrayPuzzle::sortArrayAction(){
}
