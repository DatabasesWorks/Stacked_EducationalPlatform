#ifndef LISTPUZZLE_H
#define LISTPUZZLE_H

#include <puzzle.h>
#include <list>
#include <sprite2dobject.h>

class ListPuzzle : public Puzzle
{
public:
    ListPuzzle();
    ListPuzzle(QSize);
    ~ListPuzzle();
    void pushFront();
    void pushBack();
    void popFront();
    void popBack();
    void sortList();
    void virtual runAction(Qt::Key) override;

private:
    const int CubeSideLength = 10;
    const int YSpawn = 195;
    const int InitialXSpawn = 200;
    const sf::Color DefaultColor = sf::Color::White;
    const sf::Color ActiveColor = sf::Color::Yellow;

    //std::list <sprite2dObject> l;
    int activeIndex;
    void colorActiveBody();
    void uncolorActiveBody();
    void advanceActiveIndex();
    void retreatActiveIndex();
};

#endif // LISTPUZZLE_H
