#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include "puzzlecomponent.h"
#include <QSize>
#include <QPoint>

class Puzzle
{
public:
    Puzzle();
    void moveComponent(unsigned int, QPoint);
    PuzzleComponent getComponentAt(QPoint);
    PuzzleComponent getComponent(unsigned int);
    void changeComponentImage(unsigned int, const QImage);
    void resize(QSize);
private:
    vector<PuzzleComponent> components;
    QSize size;
};

#endif // PUZZLE_H
