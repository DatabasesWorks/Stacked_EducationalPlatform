#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include <vector>
#include "level.h"
#include <QImage>

class DataStructure
{
public:
    DataStructure();
    void changeLevel(int);
    bool progress();
    Level getCurrentLevel();
private:
    std::vector<Level> levels;
    QImage backgroundTemplate;
    int currentLevel;
};

#endif // DATASTRUCTURE_H
