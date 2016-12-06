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
    void loadColors();
    ~TreePuzzle();
private:
    std::vector<sf::Color*> colors;

public slots:
    void mousePressedSlot(QPointF qpoint);
    void mouseMovedSlot(QPointF qpoint);
    void mouseReleasedSlot(QPointF qpoint);
};

#endif // BINARYTREEPUZZLE_H
