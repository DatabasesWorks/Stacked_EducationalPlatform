#include "arraypuzzle.h"
ArrayPuzzle::ArrayPuzzle() : Puzzle() {

    b2Vec2 grav(0, 0.1);
    thisWorld->SetGravity(grav);

    SpriteDefinition floordef(100, 200, b2_staticBody, "testbox");
    floordef.setShape(4, 1500, 0);
    sprite2dObject *floor = new sprite2dObject(thisWorld, floordef);
    inactive_components.push_back(floor);

    for(int i = 0; i < 5; i++){
        this->addComponent("array_"+i, 4, 100, 25, 100+(i*75), -200, b2_dynamicBody);
    }
}


ArrayPuzzle::~ArrayPuzzle() {}

void ArrayPuzzle::runAction(Qt::Key key){
    std::string d = "something";// "figured we can use keystrokes as a universal selector"
    int ind = 0;
    if(key == Qt::Key_E){
        deleteAtIndexAction(ind);
    }
    if(key == Qt::Key_R){
       // addAtIndexAction(ind, );
    }
    if(key == Qt::Key_S){
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
