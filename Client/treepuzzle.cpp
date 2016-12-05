#include "treepuzzle.h"
#include "cmath"
#include <iostream>

TreePuzzle::TreePuzzle(QSize size) : Puzzle(size)
{
    b2Vec2 graf(0,.2);
    thisWorld->SetGravity(graf);




//    SpriteDefinition triangledef(300,10,b2_dynamicBody,"testbox");
//    triangledef.setShape(3,0,0);
//    sprite2dObject *triangle = new sprite2dObject(thisWorld,triangledef);
//    components.push_back(triangle);
//    components.push_back(triangle);
//    components.push_back(triangle);

//    SpriteDefinition floordef(100,200, b2_staticBody,"testbox");

    this->establishFloor();
    this->establishGravity(100);
    this->establishSides();
//    floordef.setShape(4,1000,0); // set shape is (verticeCount, width, height ) -- if 0 the height/width will be 1.
//    sprite2dObject *floor = new sprite2dObject(thisWorld,floordef);
//    components.push_back(floor);

//    SpriteDefinition platdef(100,100, b2_staticBody,"plat");
//    platdef.setShape(4, 100, 0);
//    sprite2dObject *platform = new sprite2dObject(thisWorld,platdef);
//    components.push_back(platform);

    int sides = 4;
    int l = 50;
    int h = 0;

    int boxsize=15;
//    int tri=3;

    //platforms (i.e. tree)
    this->addComponent("plat_3",sides,l,h, 200, 50, b2_staticBody);
    this->addComponent("plat_1",sides,l,h, 100,100, b2_staticBody);
    this->addComponent("plat_5",sides,l,h, 300,100, b2_staticBody);
    this->addComponent("plat_0",sides,l,h, 50, 150, b2_staticBody);
    this->addComponent("plat_2",sides,l,h, 150, 150,b2_staticBody);
    this->addComponent("plat_4",sides,l,h, 250, 150,b2_staticBody);
    this->addComponent("plat_6",sides,l,h, 350, 150,b2_staticBody);

    //boxes (i.e. data to go into the tree)
    std::string name;
    for(int i = 0; i<10; i++)
    {   name = "box" +i;
        this->addComponent(name,sides,boxsize,boxsize, 10+i*16, 10, b2_dynamicBody);
    }




    //couldnt make a clean loop so hardcode above
//    for(int i = 0; i < 3; i++){

//       for(int j = 0; j < pow(2,i); j++){
//            this->addComponent("plat_"+j+i,4,50,5, (j*(i+1))*200/pow(2,i) , i*50+50,b2_staticBody);
//       }
//    }
//    for(int i = 1; i < 7; i++){
//        this->addComponent("plat_"+i,4,50,5, i*50, 50, b2_staticBody);
//    }

}


TreePuzzle::~TreePuzzle() {

}


void TreePuzzle::mousePressedSlot(QPoint qpoint)
{

    int x = qpoint.x();
    std::cout << "x" << x << std::endl;

    int y = qpoint.y();
    std::cout << "y" << y << std::endl;

    this->addComponent("name", 4 ,15,15, x-539, y-188, b2_dynamicBody);


}

void TreePuzzle::mouseMovedSlot(QPoint qpoint)
{

}

void TreePuzzle::mouseReleasedSlot(QPoint qpoint)
{

}

/*
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
 * */
