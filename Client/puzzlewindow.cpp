#include "puzzlewindow.h"


//Default constructor set's puzzle to 0 -- exception handling in OnUpdate?
PuzzleWindow::PuzzleWindow(QWidget *Parent) : GraphicsObject(Parent)
{
    puzzle = 0;
}

//Initialize with a puzzle -- puzzle will be used to get sprite components
//PuzzleWindow::PuzzleWindow(QWidget *Parent, Puzzle *puzzle) : GraphicsObject(Parent)
//{
//    this->puzzle = puzzle;
//}

void PuzzleWindow::OnInit()
{
    //I do not think we need anything OnInit


    //DELETE LATER:
    Q_INIT_RESOURCE(sprites);
    QFile f(":/spritesheet.png");
    f.copy(QString("spritesheet.png"));

    //load the png that will be the "sprite"
    if (!tex.loadFromFile("spritesheet.png")) {
        //Error handling
        std::cout << "Failed to find texture" << std::endl;
    }


    // Setup the sprite
    spr.setTexture(tex);
    //END DELETE


}


//This is called by a timer and will draw every component into the set puzzle
//May need better exception handling on puzzle=0
void PuzzleWindow::OnUpdate()
{
    //Get all the drawing components from the puzzle
    if(puzzle!=0)
    {
         //attempt to get all components from puzzle
         components = puzzle->getAllComponents();
         for(sprite2dObject* s2d: components)
         {
             //Use sf::RenderWindow to draw each sprite component of puzzle
             RenderWindow::draw(*s2d->getSprite());
         }
    }
    else
    {
        //nullptr?


        //**DEMO** Delete later:
        //starting location of sprite
        spr.setPosition(sf::Vector2f(300, 200));
        this->draw(spr);
        spr.rotate(1);
        //END DELETE

     }


}

//For setting or changing the puzzle in the window
void PuzzleWindow::setPuzzle(Puzzle *puzzle)
{
    this->puzzle = puzzle;
}
