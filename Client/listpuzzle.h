#ifndef LISTPUZZLE_H
#define LISTPUZZLE_H

#include <puzzle.h>
#include <list>
#include <sprite2dobject.h>

class ListPuzzle : public Puzzle
{
public:
    ListPuzzle();
    ~ListPuzzle();
    void pushFront();
    void pushBack();
    void popFront();
    void popBack();
    void sortList();

private:
    std::list <sprite2dObject> l;
};

#endif // LISTPUZZLE_H
