#include "puzzlewindow.h"


//Default constructor set's puzzle to 0 -- exception handling in OnUpdate?
PuzzleWindow::PuzzleWindow(QWidget *Parent) : GraphicsObject(Parent)
{
    puzzle = 0;
    QObject::connect(&slowUpdateTimer,&QTimer::timeout, this, &PuzzleWindow::SlowUpdate);
    slowUpdateTimer.start(1000);
}

void PuzzleWindow::OnInit()
{
    // any init code for the game environment
    updateSet();
}

//copied form graphics object test
void PuzzleWindow::updateSet(){
    drawnSprites.clear();
    std::vector<sprite2dObject*> objs = puzzle->getAllComponents();
    for(auto ptr = objs.begin(); ptr < objs.end(); ptr++){
        sprite2dObject obj = (**ptr);
        if(obj.getBody()!=nullptr){
            drawnSprites.push_back(obj.getShape());
        }
     }
}

void PuzzleWindow::SlowUpdate(){
    puzzle->garbageCollection();
}

//This is called by a timer and will draw every component into the set puzzle
//May need better exception handling on puzzle=0
void PuzzleWindow::OnUpdate()
{
    //Draw sprite on window
    puzzle->step(1/30.0f);
    updateSet();
    for(auto it = drawnSprites.begin(); it < drawnSprites.end(); it++)
    {
        RenderWindow::draw(*it);
    }
    //old code from Tyler
//    //Get all the drawing components from the puzzle
//    if(puzzle!=0)
//    {
//         //attempt to get all components from puzzle
//         components = puzzle->getAllComponents();
//         for(sprite2dObject* s2d: components)
//         {
//             //Use sf::RenderWindow to draw each sprite component of puzzle
//             RenderWindow::draw(*s2d->getShape());
//         }
//    }
//    else
//    {
//        //nullptr?


//        //**DEMO** Delete later:
//        //starting location of sprite
//        spr.setPosition(sf::Vector2f(300, 200));
//        this->draw(spr);
//        spr.rotate(1);
//        //END DELETE

//     }


}

//For setting or changing the puzzle in the window
void PuzzleWindow::setPuzzle(Puzzle *puzzle)
{
    this->puzzle = puzzle;
}

//add some key capture for testing
void PuzzleWindow::keyPressEvent(QKeyEvent *event){
    puzzle->runAction(Qt::Key(event->key()));
}
