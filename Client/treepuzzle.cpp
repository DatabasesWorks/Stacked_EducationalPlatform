#include "treepuzzle.h"
#include "cmath";

TreePuzzle::TreePuzzle() : Puzzle()
{
    b2Vec2 graf(0,1);
    thisWorld->SetGravity(graf);

    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");
    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
    components.push_back(floor);

    int w = 4;
    int l = 50;
    int h = 5;
    //sloppy hardcode
    this->addComponent("plat_3",w,l,h, 200, 50, b2_staticBody);
    this->addComponent("plat_1",w,l,h, 100,100, b2_staticBody);
    this->addComponent("plat_5",w,l,h, 300,100, b2_staticBody);
    this->addComponent("plat_0",w,l,h, 50, 150, b2_staticBody);
    this->addComponent("plat_2",w,l,h, 150, 150,b2_staticBody);
    this->addComponent("plat_4",w,l,h, 250, 150,b2_staticBody);
    this->addComponent("plat_6",w,l,h, 350, 150,b2_staticBody);

}


TreePuzzle::~TreePuzzle() {

}

/*
 * TREEE PUZZLE SOLUTION OUTLINE:
 * 1. add 7 ints to puzzle and generate array
 * 2. sort that array.
 * 3. for solution compare the indices of that array against the platform indices
 *
 * add draggable boxes with ints
 * if box is in contact with the correct platform
 * set colour of plat and box to green
 * if incorrect set red
 * if box and platform are not in contact with each other set default colour
 *
 * when all platforms are green puzzle is solved
 */
