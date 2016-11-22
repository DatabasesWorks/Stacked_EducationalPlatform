#include "listpuzzle.h"

template <class T>
void ListPuzzle<T>::pushFront(T val){
    l.push_front(val);
}

template <class T>
void ListPuzzle<T>::pushBack(T val){
    l.push_back(val);
}

template <class T>
void ListPuzzle<T>::popFront(){
    l.pop_front();
}

template <class T>
void ListPuzzle<T>::popBack(){
    l.pop_back();
}

template <class T>
void ListPuzzle<T>::sortList(){
    l.sort();
}
