#ifndef STACKPUZZLE_H
#define STACKPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <stack>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <sprite2dobject.h>
class StackPuzzle : public Puzzle
{
public:
    StackPuzzle();
    StackPuzzle(QSize size);
    ~StackPuzzle();
    void virtual runAction(Qt::Key action) override;
private:
    std::string peekAction();
    void popAction();
    void generateStackPiece(int,int);
    void generateTree();
    sprite2dObject * createNode(int,int, b2BodyType);
    void pushAction();
    std::stack <sprite2dObject> s;
};

#endif // STACKPUZZLE_H
