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
#include <sstream>
#include <iostream>
#include "calculator.cpp"

class ArrayPuzzle : public Puzzle
{
public:
    ArrayPuzzle();
    ArrayPuzzle(QSize size);
    ~ArrayPuzzle();
    void virtual runAction(Qt::Key) override;
private:
    int activeIndex;
    //for the sprite text
    int randomNum;
    int equationCount;
    bool question1Done;
    bool question2Done;
    void replaceAtIndexAction();
    void addAtIndexAction();
    void createEnvironment();
    std::string getNumAtActive();
    void setupInstructions();
    void setupQuestion();
    void setupEquation(std::string);
    void clearEquation();
    const static int firstAnswer = 13;
    const static int secondAnswer = 55;
};

#endif // ARRAYPUZZLE_H
