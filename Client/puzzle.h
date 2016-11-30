#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <QSize>
#include <QPoint>
#include <QImage>
#include <action.h>
#include <Box2D.h>
#include <sprite2dobject.h>
#include <iterator>


class Puzzle
{
public:

    Puzzle(QSize);

    //managing components
    void addComponent(sprite2dObject);
    sprite2dObject getComponent(unsigned int);
    std::vector<sprite2dObject> getComponents();
    void changeComponentImage(unsigned int, sf::Image);
    int getnumComponents();

    //polymorphic stuff
    virtual void runAction(Action action);

private:

    b2World *thisWorld;
    std::vector<sprite2dObject>components;
    QSize size;
    int numComponents;

};

#endif // PUZZLE_H
