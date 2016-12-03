#ifndef BINARYTREEPUZZLE_H
#define BINARYTREEPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <action.h>
#include <sprite2dobject.h>

class TreePuzzle : public Puzzle

{
public:
    TreePuzzle();
    TreePuzzle(QSize size);
    ~TreePuzzle();
};

#endif // BINARYTREEPUZZLE_H
