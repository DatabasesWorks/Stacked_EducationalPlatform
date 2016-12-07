#include "treepuzzle.h"
#include "cmath"
#include <iostream>
#include <math.h>
#include <puzzle.h>

TreePuzzle::TreePuzzle(QSize size) : Puzzle(size)
{

    this->establishFloor();
    this->establishGravity(100);
    this->establishSides();
    int sides = 4;
    int l = 50;
    int h = 0;

    int boxsize=25;

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
    for(int i = 0; i<7; i++)
    {
        name = "box_" + std::to_string(i);
        std::cout << name << std::endl;
        this->addComponent(name,sides,boxsize,boxsize, 50+i*50, 185, b2_dynamicBody);
    }
    for(auto it = components.begin(); it < components.end(); it++)
    {
       sprite2dObject * obj = *it;
       if(obj->getName().find("box") != -1){
            sf::Color color = sf::Color::Magenta;
            obj->changeColor(color);
       }
       else if(obj->getName().find("plat") != -1){
           sf::Color color = sf::Color::Yellow;
           obj->changeColor(color);
      }
    }

}


TreePuzzle::~TreePuzzle() {

}


void TreePuzzle::mousePressedSlot(QPointF qpoint)
{
    int scale = 1;

    int x = (qpoint.x())/scale;
    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
    std::cout << "y" << y << std::endl;

//    this->addComponent("name", 4 ,15,15,x, y, b2_dynamicBody);

//    int i = 0;
//    sprite2dObject* s = getComponent("name");
//    s->moveToPoint(x+100,y+100);
    sprite2dObject* b = getComponent("box_0");


    if(b!=NULL){
        std::cout << b->getName() <<std::endl;
        curr = b;
        curr->bindToMouse();
    }

}

void TreePuzzle::mouseMovedSlot(QPointF qpoint)
{
    int scale = 1;

    int x = (qpoint.x())/scale;
    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
    std::cout << "y" << y << std::endl;
    if(curr != NULL){
        curr->moveToPoint(x,y);
    }
}

void TreePuzzle::mouseReleasedSlot(QPointF qpoint)
{
    curr->unbind();
    curr = NULL;
}


void TreePuzzle::loadColors()
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
