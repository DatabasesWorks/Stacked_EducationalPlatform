#include "treepuzzle.h"
#include "cmath"
#include <iostream>
#include <math.h>

TreePuzzle::TreePuzzle(QSize size) : Puzzle(size)
{
    b2Vec2 graf(0,1);
    thisWorld->SetGravity(graf);

    this->establishFloor();
    this->establishGravity(100);
    this->establishSides();
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



}


TreePuzzle::~TreePuzzle() {

}


void TreePuzzle::mousePressedSlot(QPointF qpoint)
{
    int scale = 2;

    int x = (qpoint.x())/scale;
    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
    std::cout << "y" << y << std::endl;

    this->addComponent("name", 4 ,15,15,x, y, b2_dynamicBody);


}

void TreePuzzle::mouseMovedSlot(QPointF qpoint)
{

}

void TreePuzzle::mouseReleasedSlot(QPointF qpoint)
{

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
<<<<<<< HEAD
 */
