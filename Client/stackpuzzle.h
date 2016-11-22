#ifndef STACKPUZZLE_H
#define STACKPUZZLE_H

#include <stack>
template <class T>
class StackPuzzle
{
public:
    StackPuzzle();
    T peekAction();
    void popAction();
    void pushAction(T);

private:
    std::stack <T> s;
};

#endif // STACKPUZZLE_H
