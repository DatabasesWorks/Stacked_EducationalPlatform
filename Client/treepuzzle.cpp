#include "treepuzzle.h"
#include "cmath"
#include <iostream>
#include <math.h>
#include <puzzle.h>

TreePuzzle::TreePuzzle(QSize size) : Puzzle(size)
{

    QObject::connect(&treetime, SIGNAL(timeout()), this, SLOT(updateContact()));
    treetime.start(100);
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
//        std::cout << name << std::endl;
        this->addComponent(name,sides,boxsize,boxsize, 50+i*50, 185, b2_dynamicBody);
    }
    for(auto it = components.begin(); it < components.end(); it++)
    {
       sprite2dObject * obj = *it;
       if(obj->getName().find("box") != -1){
           boxes.push_back(obj->getName());
            sf::Color color = sf::Color::Magenta;
            obj->changeColor(color);
       }
       else if(obj->getName().find("plat") != -1){
           plats.push_back(obj->getName());
           sf::Color color = sf::Color::Yellow;
           obj->changeColor(color);
      }
    }

}


TreePuzzle::~TreePuzzle() {

}


void TreePuzzle::mousePressedSlot(QPointF qpoint)
{
    std::cout<<"X box_0 " << getComponent("box_0")->getBody()->GetPosition().x;
   std::cout<<"Y box_0 " << getComponent("box_0")->getBody()->GetPosition().y << std::endl;
    int scale = 1;

    int x = (qpoint.x())/scale;
//    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
//    std::cout << "y" << y << std::endl;

//    this->addComponent("name", 4 ,15,15,x, y, b2_dynamicBody);

    sprite2dObject* b = getComponentAt(50,190); //reverse and accommodate offset ie +90?

    std::cout << "BUG?" << std::endl;
    if(b!=NULL){
        curr = getComponentAt(50,190);
        std::cout << "BUG?" << std::endl;
//        curr->bindToMouse();
    }


}

void TreePuzzle::mouseMovedSlot(QPointF qpoint)
{

    int scale = 1;

    int x = (qpoint.x())/scale;
//    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
//    std::cout << "y" << y << std::endl;
    if(curr != NULL){
        curr->moveToPoint(x, y);
    }

}

void TreePuzzle::mouseReleasedSlot(QPointF)
{
//    curr->unbind();
//    std::string val = curr->getText();

//    curr->scaleSize(.5);
    curr = NULL;
}

void TreePuzzle::updateContact()
{
    for(int i = 0; i < 7; i++)
    {
        std::string  box = boxes[i];
        for(int j = 0; j < 7 ; j++)
        {
            std::string  plat = plats[j];
            bool inContact = getComponent(box)->inContact(getComponent(plat));
            int boxl =box.length();
            int platl = plat.length();
            bool namesMatch = (box[boxl-1] == plat[platl-1]);

            if(inContact && namesMatch)
            {
                getComponent(box)->changeColor(sf::Color::Green);
                getComponent(plat)->changeColor(sf::Color::Green);
            }
            else if (!inContact && namesMatch)
            {
                getComponent(box)->changeColor(sf::Color::Magenta);
                getComponent(plat)->changeColor(sf::Color::Yellow);
            }
        }
    }
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
