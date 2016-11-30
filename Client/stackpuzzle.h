#ifndef STACKPUZZLE_H
#define STACKPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <stack>
#include <QObject>
#include <puzzle.h>

class StackPuzzle : public Puzzle
{
public:
    StackPuzzle();
    ~StackPuzzle();
    void virtual runAction(Action action) override;
    sprite2dObject peekAction();
    void popAction(b2Body*);
    void pushAction();

private:
    std::stack <sprite2dObject> s;
};

#endif // STACKPUZZLE_H
