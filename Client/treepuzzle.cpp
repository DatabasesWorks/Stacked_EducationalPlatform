#include "treepuzzle.h"
#include "cmath";

TreePuzzle::TreePuzzle() : Puzzle()
{
    b2Vec2 graf(0,.2);
    thisWorld->SetGravity(graf);
//    SpriteDefinition triangledef(300,10,b2_dynamicBody,"testbox");
//    triangledef.setShape(3,0,0);
//    sprite2dObject *triangle = new sprite2dObject(thisWorld,triangledef);
//    components.push_back(triangle);
//    components.push_back(triangle);
//    components.push_back(triangle);

    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    components.push_back(floor);

//    SpriteDefinition platdef(100,100, b2_staticBody,"plat");
//    platdef.setShape(4, 100, 0);
//    sprite2dObject *platform = new sprite2dObject(thisWorld,platdef);
//    components.push_back(platform);

    int w = 4;
    int l = 50;
    int h = 5;
    this->addComponent("plat_0",w,l,h, 200, 50, b2_staticBody);
    this->addComponent("plat_1",w,l,h, 100,100, b2_staticBody);
    this->addComponent("plat_2",w,l,h, 300,100, b2_staticBody);
    this->addComponent("plat_3",w,l,h, 50, 150, b2_staticBody);
    this->addComponent("plat_4",w,l,h, 150, 150,b2_staticBody);
    this->addComponent("plat_5",w,l,h, 250, 150,b2_staticBody);
    this->addComponent("plat_6",w,l,h, 350, 150,b2_staticBody);

    //failed to make loop so just hardcoded above
//    for(int i = 0; i < 3; i++){

//       for(int j = 0; j < pow(2,i); j++){
//            this->addComponent("plat_"+j+i,4,50,5, (j*(i+1))*200/pow(2,i) , i*50+50,b2_staticBody);
//       }
//    }
    for(int i = 1; i < 8; i++){
        this->addComponent("plat_"+i,4,50,5, i*50, 200-(i/4)*50, b2_staticBody);
    }

}


TreePuzzle::~TreePuzzle() {

}
