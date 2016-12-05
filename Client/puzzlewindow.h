#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>
#include "SFML/Graphics.hpp"
#include <sprite2dobject.h>
#include <iostream>
#include <puzzle.h>
#include <sprite2dobject.h>
#include <QDir>
#include <vector>
#include <QSize>
#include <QString>
#include <QKeyEvent>
#include <SFML/Graphics.hpp>
#include <QTimer>


class PuzzleWindow : public GraphicsObject
{
public:
    explicit PuzzleWindow(QWidget *Parent=0);
    void onInit();
    void onUpdate();
    void setPuzzle(Puzzle *puzzle);

private:

    std::vector<sprite2dObject *> spritesToDraw;
    Puzzle* puzzle;
    QTimer slowUpdateTimer;

    void OnInit();
    void OnUpdate();

    //demo objects
    sf::Sprite spr;
    sf::Texture tex;
    void updateSet();
    float rot=1;

protected slots:
    void SlowUpdate();

protected:
    void keyPressEvent(QKeyEvent*);
};

#endif // PUZZLEWINDOW_H
