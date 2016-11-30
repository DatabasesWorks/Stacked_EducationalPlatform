#include "stackpuzzle.h"

template<class T>
StackPuzzle<T>::StackPuzzle(){




}

template<class T>
StackPuzzle<T>::~StackPuzzle(){

}

template<class T>
void StackPuzzle<T>::runAction(Action action){
   double accel = action.acceleration;
   std::string d  = action.description;
   if(d=="pop"){

       // do something .


   }

}

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
