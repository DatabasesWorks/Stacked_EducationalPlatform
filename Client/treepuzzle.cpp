#include "treepuzzle.h"
#include "cmath"
#include <iostream>
#include <math.h>
#include <puzzle.h>
#include <random>
#include <set>

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

    int boxsize=35;

    //platforms (i.e. tree)
    this->addComponent("plat_3",sides,l,h, 200, 50, b2_staticBody);
    this->addComponent("plat_1",sides,l,h, 100,100, b2_staticBody);
    this->addComponent("plat_5",sides,l,h, 300,100, b2_staticBody);
    this->addComponent("plat_0",sides,l,h, 50, 150, b2_staticBody);
    this->addComponent("plat_2",sides,l,h, 150, 150,b2_staticBody);
    this->addComponent("plat_4",sides,l,h, 250, 150,b2_staticBody);
    this->addComponent("plat_6",sides,l,h, 350, 150,b2_staticBody);


    //create random values for boxes
    std::vector<int> values;
    int r = std::rand()%50+1;
    values.push_back(r);
    while(values.size()< 7){
        r = std::rand()%50+1;
        for(int i = 0; i<values.size(); i++){
            if(values.at(i) == r){
                break;
            }
            if(i == values.size()-1){
                values.push_back(r);
            }
        }
    }
    std::sort(values.begin(), values.end());

    //create random array to shuffle boxes
    int randArray[] = {0,1,2,3,4,5,6};

    for(int i=0; i<7; i++){
        int r = std::rand()%7;
        int x = randArray[r];
        randArray[r] = randArray[i];
        randArray[i] = x;
    }

    //boxes (i.e. data to go into the tree)
    std::string name;

    for(int i = 0; i<7; i++)
    {
        SpriteDefinition stack_p;
        stack_p.setShape(4, boxsize, boxsize);
        stack_p.setDensity(50);
        stack_p.setPosition(100+randArray[i]*100,390);
        stack_p.setText(std::to_string(values[i]));
        stack_p.setType(b2_dynamicBody);
        name = "box_" + std::to_string(i);       
        sprite2dObject* s = new sprite2dObject(thisWorld, stack_p);
        s->setName(name);
        addComponent(s);
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
//    std::cout<<"X box_0 " << getComponent("box_0")->getBody()->GetPosition().x;
//   std::cout<<"Y box_0 " << getComponent("box_0")->getBody()->GetPosition().y << std::endl;
    int scale = 1;

    int x = (qpoint.x())/scale;
//    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
//    std::cout << "y" << y << std::endl;

//    this->addComponent("name", 4 ,15,15,x, y, b2_dynamicBody);

    sprite2dObject* b = getComponentAt(x,y); //reverse and accommodate offset ie +90?

//    std::cout << "BUG?" << std::endl;

    if(b!=nullptr && b->getName().find("box") != -1){
        curr = b;
        curr->bindToMouse();
    }


}

void TreePuzzle::mouseMovedSlot(QPointF qpoint)
{

    int scale = 1;

    int x = (qpoint.x())/scale;
//    std::cout << "x" << x << std::endl;

    int y = (qpoint.y())/scale;
//    std::cout << "y" << y << std::endl;
    if(curr != nullptr){
        curr->moveToPoint(x, y);

    }

}

void TreePuzzle::mouseReleasedSlot(QPointF)
{
    if(curr!=nullptr)
    {
        curr->unbind();
    }

    curr = nullptr;
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
            int boxl = box.length();
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
            else if (inContact && !namesMatch)
            {
                getComponent(box)->changeColor(sf::Color::Red);
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
