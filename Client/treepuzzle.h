#ifndef BINARYTREEPUZZLE_H
#define BINARYTREEPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <sprite2dobject.h>

class TreePuzzle : public Puzzle

{
public:
    TreePuzzle();
    TreePuzzle(QSize size);
    ~TreePuzzle();
private:
    std::vector<sf::Color*> colors;

public slots:
    void mousePressedSlot(QPoint qpoint);
    void mouseMovedSlot(QPoint qpoint);
    void mouseReleasedSlot(QPoint qpoint);
};

#endif // BINARYTREEPUZZLE_H
