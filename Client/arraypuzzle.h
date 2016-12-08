#ifndef ARRAYPUZZLE_H
#define ARRAYPUZZLE_H

#include <QString>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <sprite2dobject.h>
#include <array>
#include <algorithm>

class ArrayPuzzle : public Puzzle
{
public:
    ArrayPuzzle();
    ArrayPuzzle(QSize size);
    ~ArrayPuzzle();
    void virtual runAction(Qt::Key) override;
private:
    int activeIndex;
    void replaceAtIndexAction();
    void addAtIndexAction();
    void createEnvironment();
};

#endif // ARRAYPUZZLE_H
