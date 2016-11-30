#include "stackpuzzle.h"

template<class T>
StackPuzzle<T>::StackPuzzle(){


    b2PolygonShape rectShape;
    //This sets the shape as a rectangle
    rectShape.SetAsBox(2, 1);

    b2FixtureDef rectFixtureDef;
    rectFixtureDef.shape = &rectShape;
    rectFixtureDef.density = 1;
    b2Body * bod;

    //We need to decide what we want the default stack to look like.
    foreach (sprite2dObject obj, components) {
        bod = obj.getBody();
        bod->CreateFixture(&rectFixtureDef);
    }

}

template<class T>
StackPuzzle<T>::~StackPuzzle(){

}

template<class T>
void StackPuzzle<T>::runAction(Action action){
   double accel = action.acceleration;
   std::string d  = action.description;
   if(d == "pop"){




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
