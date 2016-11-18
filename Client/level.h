#ifndef LEVEL_H
#define LEVEL_H
#include "puzzle.h"
#include <QString>

class Level
{
public:
    Level();
    void resetProperties();
    Puzzle getPuzzle();
    bool isCompleted();
    QString serializeProperties();
private:
    Puzzle puzzle;
    bool completed;
    int difficulty;
    QString description;

};

#endif // LEVEL_H
