#ifndef LISTPUZZLE_H
#define LISTPUZZLE_H

#include <puzzle.h>
#include <list>
#include <string>
#include <sprite2dobject.h>
#include <iterator>
#include <sstream>
#include <utility>

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
    //void sortList();
    void addAtActiveIndex();
    void deleteAtActiveIndex();
    void virtual runAction(Qt::Key) override;
    void reset();
    bool checkSolution();

private:
    const int CubeSideLength = 10;
    const int YSpawn = 190;
    const int InitialXSpawn = 200;
    const int deltaX = 10;
    const int deltaY = 10;
    const sf::Color DefaultColor = sf::Color::White;
    const sf::Color ActiveColor = sf::Color::Yellow;

    std::list<std::pair<std::string, bool>> workingSet;
    std::list<std::string> solutionSet;
    int activeIndex;
    void colorActiveBody();
    void uncolorActiveBody();
    void advanceActiveIndex();
    void retreatActiveIndex();
    void addFirstBody();
};

#endif // LISTPUZZLE_H
