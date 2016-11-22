#ifndef ARRAYPUZZLE_H
#define ARRAYPUZZLE_H

#include <QString>
#include <array>
#include <algorithm>

template <class T>
class ArrayPuzzle
{
public:
    ArrayPuzzle();
    //Do we want to delete and shift, then copy to new array? or do we want to simulate resizable arrays and use vectors?
    void deleteAtIndex(int);

    void addAtIndex(int, T);
    void sortArray();

private:
    std::array<T, 10> arr;
};

#endif // ARRAYPUZZLE_H
