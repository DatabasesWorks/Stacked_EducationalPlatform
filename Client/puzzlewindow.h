#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>
#include "SFML/Graphics.hpp"
#include <sprite2dObject.h>
#include <iostream>
#include <puzzle.h>
#include <QDir>
#include <QString>
#include <SFML/Graphics.hpp>


class PuzzleWindow : public GraphicsObject
{
public:
    explicit PuzzleWindow(QWidget *Parent=0);
//    PuzzleWindow(QWidget *Parent = 0, Puzzle *puzzle=0);
    void onInit();
    void onUpdate();
    void setPuzzle(Puzzle *puzzle);

private:
    std::vector<sprite2dObject> components;
    Puzzle* puzzle;
    void OnInit();
    void OnUpdate();

    //demo objects
    sf::Sprite spr;
    sf::Texture tex;
};

#endif // PUZZLEWINDOW_H
