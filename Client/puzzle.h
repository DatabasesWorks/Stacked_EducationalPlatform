#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <QSize>
#include <QPoint>
#include <QImage>
#include <Box2D/Box2D.h>
#include <sprite2dobject.h>
#include <iterator>
#include <string>

class Puzzle
{
public:

    Puzzle();
    virtual ~Puzzle();
    //managing components
    void addComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type, bool ignored = false);
    void changeComponentImage(unsigned int, sf::Image);
    void addComponent(SpriteDefinition, bool ignored = false);
    std::vector<sprite2dObject*> getAllComponents();
    void garbageCollection();

    //phy engine step
    void step(float time);
    //polymorphic stuff

    virtual void runAction(Qt::Key);

protected:
    std::vector<sprite2dObject*> components;
    std::vector<sprite2dObject*> inactive_components;
    b2World *thisWorld;
    void establishGravity();
    void establishFloor();

private:
    QSize size;

};

#endif // PUZZLE_H
