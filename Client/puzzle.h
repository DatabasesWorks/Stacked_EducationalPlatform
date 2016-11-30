#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <QSize>
#include <QPoint>
#include <QImage>
#include <action.h>
#include <Box2D.h>
#include <sprite2dobject.h>


class Puzzle
{
public:
    Puzzle(QSize);
    void addComponent(sprite2dObject);
    virtual sprite2dObject getComponent(unsigned int);
    virtual void changeComponentImage(unsigned int, const QImage);
    virtual void runAction(Action action);
    b2World *thisWorld;
private:
    std::vector<sprite2dObject>components;
    QSize size;
    int numComponents;
};

#endif // PUZZLE_H
