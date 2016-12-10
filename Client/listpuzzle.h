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
    void pushBack(std::string value = "");
    void popFront();
    void popBack();
    //void sortList();
    void addAtActiveIndex(std::string value = "");
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
    const sf::Color DefaultColor = sf::Color::Blue;
    const sf::Color ActiveColor = sf::Color::Red;

    std::list<std::pair<std::string, bool>> workingSet;
    std::list<std::string> solutionSet;
    int activeIndex;
    std::vector<std::string> possibleValues;
    std::string nextValue;
    int nextValueIndex;
    void colorActiveBody();
    void uncolorActiveBody();
    void advanceActiveIndex();
    void retreatActiveIndex();
    void addFirstBody(std::string value = "");
    void updateNextValueDisplay();
    void cycleNextValue(bool scrollDown);
    void forceSyncWithWorkingSet();
};

#endif // LISTPUZZLE_H
