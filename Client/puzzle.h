#ifndef PUZZLE_H
#define PUZZLE_H
#include <QObject>
#include <vector>
#include <QSize>
#include <QPoint>
#include <QImage>
#include <Box2D/Box2D.h>
#include <sprite2dobject.h>
#include <iterator>
#include <string>

class Puzzle : public QObject
{
    Q_OBJECT
public:

    Puzzle(QSize size, QObject *parent = 0);
    Puzzle(QObject *parent = 0);
    virtual ~Puzzle();
    //managing components
    void addComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type, bool ignored = false, bool pushFront = false);
    void replaceComponent(std::string name, int points, int width, int height, int x, int y, b2BodyType type, int ind, bool ignored = false);
    void changeComponentImage(unsigned int, sf::Image);
    void addComponent(SpriteDefinition, bool ignored = false, bool pushFront = false);
    void addComponent(sprite2dObject*, bool ignored = false, bool pushFront = false);
    sprite2dObject* getComponent(std::string name);
    std::vector<sprite2dObject*> getAllComponents();
    void collectGarbage();

    //phy engine step
    void step(float time);
    //polymorphic stuff

    virtual void runAction(Qt::Key);

protected:
    std::vector<sprite2dObject*> components;
    std::vector<sprite2dObject*> inactive_components;
    b2World *thisWorld;
    void establishGravity();
    void establishGravity(int gravityfactor);
    void establishFloor();
    void establishSides();
    sprite2dObject * getComponentAt(int,int);

private:
    void garbageCollection(std::vector<sprite2dObject*>&);
    QSize size;

public slots:
    virtual void mousePressedSlot(QPointF qpoint);
    virtual void mouseMovedSlot(QPointF qpoint);
    virtual void mouseReleasedSlot(QPointF qpoint);

};

#endif // PUZZLE_H
