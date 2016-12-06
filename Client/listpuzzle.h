#ifndef LISTPUZZLE_H
#define LISTPUZZLE_H

#include <puzzle.h>
#include <list>
#include <sprite2dobject.h>

class ListPuzzle : public Puzzle
{
public:
    ListPuzzle();
    ListPuzzle(QSize);
    ~ListPuzzle();
    void pushFront();
    void pushBack();
    void popFront();
    void popBack();
    void sortList();
    void virtual runAction(Qt::Key) override;

private:
    //std::list <sprite2dObject> l;
    const int CubeSideLength = 10;
    const int YSpawn = 195;
};

#endif // LISTPUZZLE_H
