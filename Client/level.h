#ifndef LEVEL_H
#define LEVEL_H
#include "puzzle.h"
#include <QString>
#include <QSize>

class Level
{
public:
    Level();
    void resetProperties();
    Puzzle getPuzzle();
    bool isCompleted();
    QString serializeProperties();
private:
   // Puzzle puzzle(QSize(0,0));
    bool completed;
    int difficulty;
    QString description;

};

#endif // LEVEL_H
