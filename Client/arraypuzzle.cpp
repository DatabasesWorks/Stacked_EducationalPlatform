#include "arraypuzzle.h"

template<class T>
void ArrayPuzzle<T>::deleteAtIndex(int ind){

}

template<class T>
void ArrayPuzzle<T>::addAtIndex(int ind, T val){
    arr[ind] = val;
}

template<class T>
void ArrayPuzzle<T>::sortArray(){
    std::sort(std::begin(arr), std::end(arr));
}
