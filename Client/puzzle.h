#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include "puzzlecomponent.h"
#include <QSize>
#include <QPoint>
#include <action.h>
#include <bmi2intrin.h>
#include <Box2D.h>

class Puzzle
{
public:
    Puzzle();
    void moveComponent(unsigned int, QPoint);
    PuzzleComponent getComponentAt(QPoint);
    PuzzleComponent getComponent(unsigned int);
    void changeComponentImage(unsigned int, const QImage);
    void resize(QSize);
    virtual void runAction(Action action);
    b2World *thisWorld;
private:
    std::vector<PuzzleComponent> components;
    QSize size;
};

#endif // PUZZLE_H
