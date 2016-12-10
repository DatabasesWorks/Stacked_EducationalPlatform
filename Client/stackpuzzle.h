#ifndef STACKPUZZLE_H
#define STACKPUZZLE_H
#include <QGraphicsScene>
#include <QWidget>
#include <stack>
#include <QObject>
#include <puzzle.h>
#include <QSize>
#include <sprite2dobject.h>
#include <Box2D/Box2D.h>
#include <stdlib.h>
#include <sstream>
class StackPuzzle : public Puzzle
{
public:
    StackPuzzle();
    StackPuzzle(QSize size);
    ~StackPuzzle();
    void virtual runAction(Qt::Key action) override;
    void virtual step(float time) override;
private:

    //part of orig API
    std::string peekAction();
    std::atomic_bool waiting;
    std::atomic_bool produced;
    int currentanswer = 0;
    void generateQuestionValue(int,int);
    void generateStackSetWithAnswer();
    int timessolved = 0;
    std::vector<sprite2dObject*> inpit;
    void popAndSend(sprite2dObject *);
    void dropOperator();
    bool pitFull();
    void emptyPit();
    bool addToPit(sprite2dObject*);
    void updatePit(); //update logic
    void popAction();
    void pushAction();

    //world generation
    void generateStackPiece(int,int, int value = -1);
    void createStackContainer(int);
    void createBoundary(int,bool);
    void createInstructions(b2Vec2, int);
    void setActiveOperator(unsigned int);
    void generateNewQuestion();
    void startGame();
    void buildPuzzle();
    sprite2dObject * createNode(int,int, b2BodyType);
    sprite2dObject * left;
    sprite2dObject * right;
    sprite2dObject * middle;
    sprite2dObject * question;
    sprite2dObject * leftDisplay;
    sprite2dObject * rightDisplay;
    sprite2dObject * operatorDisplay;
    int itemlimit = 7;
    int operatorindex=0;
    std::vector<sprite2dObject*> operators;

    b2Vec2 ssize;
    std::stack <sprite2dObject> s;
};

#endif // STACKPUZZLE_H
