#ifndef STACKPUZZLE_H
#define STACKPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <stack>
#include <QObject>
#include <puzzle.h>

template <class T>
class StackPuzzle : public QGraphicsScene, public Puzzle
{
public:
    StackPuzzle();
    ~StackPuzzle();
    void virtual runAction(Action action) override;
    T peekAction();
    void popAction();
    void pushAction(T);

private:
    std::stack <T> s;
};

#endif // STACKPUZZLE_H
