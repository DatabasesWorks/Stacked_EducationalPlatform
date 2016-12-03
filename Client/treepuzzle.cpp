#include "treepuzzle.h"

TreePuzzle::TreePuzzle() : Puzzle()
{
    b2Vec2 graf(0,.2);
    thisWorld->SetGravity(graf);
    SpriteDefinition triangledef(300,10,b2_dynamicBody,"testbox");
    triangledef.setShape(3,0,0);
    sprite2dObject *triangle = new sprite2dObject(thisWorld,triangledef);
    components.push_back(triangle);
    components.push_back(triangle);
    components.push_back(triangle);

    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    components.push_back(floor);

    //or alternatively
    for(int i = 0; i < 5; i++){
        this->addComponent("stack_"+i,4,100,5,100,600+(i*35),b2_dynamicBody);
    }

}


TreePuzzle::~TreePuzzle() {

}