#ifndef LISTPUZZLE_H
#define LISTPUZZLE_H

#include <list>

template <class T>
class ListPuzzle
{
public:
    ListPuzzle();
    void pushFront(T);
    void pushBack(T);
    void popFront();
    void popBack();
    void sortList();

private:
    std::list<T> l;
};

#endif // LISTPUZZLE_H
