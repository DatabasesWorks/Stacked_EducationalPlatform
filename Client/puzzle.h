#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <QSize>
#include <QPoint>
#include <QImage>
#include <action.h>
#include <Box2D.h>
#include <sprite2dobject.h>
#include <iterator>


class Puzzle
{
public:

    Puzzle();
    ~Puzzle();
    //managing components
    void addComponent(sprite2dObject*);
    void addInactiveComponent(sprite2dObject*);
    void addComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type);
    void addInactiveComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type);
    virtual sprite2dObject getComponent(unsigned int);
    std::vector<sprite2dObject*> getAllComponents();
    std::vector<sprite2dObject*> getComponents();
    void changeComponentImage(unsigned int, sf::Image);
    int getnumComponents();
    void step(float time);
    //polymorphic stuff
    virtual void runAction(Qt::Key);

protected:
    std::vector<sprite2dObject*> components;
    std::vector<sprite2dObject*> inactive_components;
    b2World *thisWorld;

private:

    QSize size;
    int numComponents;

};

#endif // PUZZLE_H
