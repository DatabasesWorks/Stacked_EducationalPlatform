#ifndef BINARYTREEPUZZLE_H
#define BINARYTREEPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <sprite2dobject.h>
#include <QTimer>


class TreePuzzle : public Puzzle

{
public:
    TreePuzzle();
    TreePuzzle(QSize size);
    void loadColors();
    ~TreePuzzle();
    void updateContact();
    void resetColors();
private:
    std::vector<std::string> boxes;
    std::vector<std::string> plats;
    sprite2dObject* curr;
    QTimer treetime;


public slots:
    void mousePressedSlot(QPointF qpoint);
    void mouseMovedSlot(QPointF qpoint);
    void mouseReleasedSlot(QPointF qpoint);
};

#endif // BINARYTREEPUZZLE_H
