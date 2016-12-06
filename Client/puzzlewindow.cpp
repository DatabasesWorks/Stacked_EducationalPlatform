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
    spritesToDraw.clear();
    std::vector<sprite2dObject*> objs = puzzle->getAllComponents();
    for(auto ptr = objs.begin(); ptr < objs.end(); ptr++){
        sprite2dObject * obj = (*ptr);
        if(obj->getBody()!=nullptr&&!obj->marked()){
            spritesToDraw.push_back(obj);
        }
     }
}

void PuzzleWindow::SlowUpdate(){
    puzzle->collectGarbage();
}

//This is called by a timer and will draw every component into the set puzzle
//May need better exception handling on puzzle=0
void PuzzleWindow::OnUpdate()
{
    //Draw sprite on window
    puzzle->step(1/60.0f);
    updateSet();
    for(auto it = spritesToDraw.begin(); it < spritesToDraw.end(); it++)
    {
        sprite2dObject * obj = *it;
        RenderWindow::draw(obj->getShape());
        sf::Sprite * sprite = obj->getSprite();
        if(sprite!=nullptr){
            RenderWindow::draw(*sprite);
        }
        //if(obj->getText().getString()!=""){
        //    RenderWindow::draw(obj->getText());
        //}
   }
}

//For setting or changing the puzzle in the window
void PuzzleWindow::setPuzzle(Puzzle *puzzle)
{
    //disconnect
    QObject::disconnect(this, &PuzzleWindow::mousePressedSignal, this->puzzle, &Puzzle::mousePressedSlot);
    QObject::disconnect(this, &PuzzleWindow::mouseMovedSignal, this->puzzle, &Puzzle::mouseMovedSlot);
    QObject::disconnect(this, &PuzzleWindow::mouseReleasedSignal, this->puzzle, &Puzzle::mouseReleasedSlot);

    //change puzzle
    this->puzzle = puzzle;

    //reconnect
    QObject::connect(this, &PuzzleWindow::mousePressedSignal, this->puzzle, &Puzzle::mousePressedSlot);
    QObject::connect(this, &PuzzleWindow::mouseMovedSignal, this->puzzle, &Puzzle::mouseMovedSlot);
    QObject::connect(this, &PuzzleWindow::mouseReleasedSignal, this->puzzle, &Puzzle::mouseReleasedSlot);
}

//add some key capture for testing
void PuzzleWindow::keyPressEvent(QKeyEvent *event){
    puzzle->runAction(Qt::Key(event->key()));
}

//Mouse events:
void PuzzleWindow::mousePressEvent(QMouseEvent* e)
{
    emit mousePressedSignal(this->mapFromParent(e->pos())); //Emit QPoint?
}

void PuzzleWindow::mouseMoveEvent(QMouseEvent* e)
{
        emit mouseMovedSignal(this->mapFromParent(e->pos())); //Emit QPoint?
}

void PuzzleWindow::mouseReleaseEvent(QMouseEvent* e)
{
        emit mouseReleasedSignal(this->mapFromParent(e->pos()));  //Emit QPoint?
}


