#include "arraypuzzle.h"

ArrayPuzzle::ArrayPuzzle(QSize size) : Puzzle(size) {
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

ArrayPuzzle::ArrayPuzzle() : Puzzle(){}

ArrayPuzzle::~ArrayPuzzle() {}

void ArrayPuzzle::runAction(Action action){
    std::string d = action.description;
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
    bod = components[ind]->getBody();
    this->thisWorld->DestroyBody(bod);
    //might want to restrict the deletion if size = 1
    components.erase(components.begin() + ind);

    if(components.size() > 1){
        for(int i = ind; i < components.size(); i++){
            bod = components[i]->getBody();
            bod->SetTransform(b2Vec2(-40, 0), 0);
        }
    }
}

//void ArrayPuzzle::addAtIndexAction(int ind, sprite2dObject obj){
//}

void ArrayPuzzle::sortArrayAction(){
}
