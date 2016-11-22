#include "stackpuzzle.h"

template<class T>
T StackPuzzle<T>::peekAction(){
    return s.top();
}

template<class T>
void StackPuzzle<T>::popAction(){
    s.pop();
}

template<class T>
void StackPuzzle<T>::pushAction(T val){
    s.push(val);
}
