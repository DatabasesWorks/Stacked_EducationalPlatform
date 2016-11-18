#ifndef PUZZLECOMPONENT_H
#define PUZZLECOMPONENT_H
#include <QImage>

class PuzzleComponent
{
public:
    PuzzleComponent();
    QImage * getImage();
    void resize(QSize);
    void setPosition(QPoint);
    QPoint getPosition();
private:
    QImage * image;
    QSize size;
    QPoint position;
};

#endif // PUZZLECOMPONENT_H
