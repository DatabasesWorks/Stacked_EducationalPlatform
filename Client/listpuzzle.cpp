#include "listpuzzle.h"

ListPuzzle::ListPuzzle(QSize size) : Puzzle(size) {
    establishGravity();
    establishFloor();
    addFirstBody();
}

void ListPuzzle::addFirstBody() {
    this->addComponent("list body", 4, CubeSideLength, CubeSideLength, InitialXSpawn, YSpawn, b2_staticBody);
    activeIndex = 0;
    colorActiveBody();
    workingSet.push_front(std::make_pair("A", true));
}

void ListPuzzle::reset() {
    if (components.size() > 0) {
        int size = components.size();
        components.clear();

        int stackingHeight = 1;
        if (size >= 20) {
            stackingHeight = size / 10;
        }

        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, (InitialXSpawn - (size / 2 * deltaX) / stackingHeight), YSpawn, b2_staticBody);
        activeIndex = 0;
        int currentStackHeight = 1;
        for (int i = 1; i < size; i++) {
            if (currentStackHeight == stackingHeight) {
                pushBack();
                advanceActiveIndex();
                currentStackHeight = 1;
            } else {
                addAtActiveIndex();
                currentStackHeight++;
            }
        }

        uncolorActiveBody();
        activeIndex = 0;
        colorActiveBody();
    }
}

ListPuzzle::~ListPuzzle(){
}

void ListPuzzle::runAction(Qt::Key key) {
    if (key == Qt::Key_W) {
        pushFront();
    } else if (key == Qt::Key_E) {
        pushBack();
    } else if (key == Qt::Key_Space) {
        addAtActiveIndex();
    } else if (key == Qt::Key_S) {
        popFront();
    } else if (key == Qt::Key_D) {
        popBack();
    } else if (key == Qt::Key_X) {
        retreatActiveIndex();
    } else if (key == Qt::Key_C) {
        advanceActiveIndex();
    } else if (key == Qt::Key_R) {
        reset();
    } else if (key == Qt::Key_Delete) {
        deleteAtActiveIndex();
    }
}

void ListPuzzle::pushFront(){
    if (components.size() == 0) {
        addFirstBody();
    } else {
        b2Body *bod;
        bod = components.front()->getBody();
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, bod->GetPosition().x - deltaX, YSpawn, b2_staticBody, false, true);
        activeIndex++;
        workingSet.push_front(std::make_pair("A", true));
    }
}

void ListPuzzle::pushBack(){
    if (components.size() == 0) {
        addFirstBody();
    } else {
        b2Body *bod;
        bod = components.back()->getBody();
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, bod->GetPosition().x + deltaX, YSpawn, b2_staticBody);
        workingSet.push_back(std::make_pair("A", true));
    }
}

void ListPuzzle::addAtActiveIndex() {
    if (components.size() == 0) {
        addFirstBody();
    } else {
        b2Body *bod;
        bod = components[activeIndex]->getBody();
        int xToSpawn = bod->GetPosition().x;
        int yToSpawn = bod->GetPosition().y - deltaY;
        int jumps = 0;
        for (int i = activeIndex + 1; i < ((int) components.size()); i++) {
            if (components[i]->getBody()->GetPosition().x == xToSpawn) {
                yToSpawn = components[i]->getBody()->GetPosition().y - deltaY;
                jumps++;
            } else {
                break;
            }
        }
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, xToSpawn, yToSpawn, b2_staticBody);
        sprite2dObject* newlyAdded = components.back();
        components.pop_back();
        components.insert(components.begin() + activeIndex + 1 + jumps, newlyAdded);
        std::list<std::pair<std::string, bool>>::iterator it = workingSet.begin();
        std::advance(it, activeIndex);
        workingSet.insert(it, std::make_pair("A", true));
        advanceActiveIndex();
    }
}

void ListPuzzle::deleteAtActiveIndex() {
    if (components.size() > 0) {
        b2Body *bod;
        bod = components[activeIndex]->getBody();
        thisWorld->DestroyBody(bod);
        components.erase(components.begin() + activeIndex);
        std::list<std::pair<std::string, bool>>::iterator it = workingSet.begin();
        std::advance(it, activeIndex - 1);
        workingSet.erase(it);
        if (activeIndex == ((int) components.size())) {
            activeIndex--;
        }
        colorActiveBody();
    }
}

void ListPuzzle::popFront(){
    if (components.size() > 0) {
        uncolorActiveBody();

        b2Body *bod;
        bod = components.front()->getBody();
        thisWorld->DestroyBody(bod);
        components.erase(components.begin());
        workingSet.pop_front();

        if (activeIndex > 0) {
            activeIndex--;
        }
        colorActiveBody();
    }
}

void ListPuzzle::popBack(){
    if (components.size() > 0) {
        if (activeIndex == ((int) components.size()) - 1) {
            retreatActiveIndex();
        }

        b2Body *bod;
        bod = components.back()->getBody();
        thisWorld->DestroyBody(bod);
        components.pop_back();
        workingSet.pop_back();
    }
}

void ListPuzzle::colorActiveBody() {
    if (components.size() > 0) {
        components[activeIndex]->changeColor(ActiveColor);
    }
}

void ListPuzzle::uncolorActiveBody() {
    if (components.size() > 0) {
        components[activeIndex]->changeColor(DefaultColor);
    }
}

void ListPuzzle::advanceActiveIndex() {
    if (((int) components.size()) - 1 > activeIndex) {
        uncolorActiveBody();
        activeIndex++;
        colorActiveBody();
    }
}

void ListPuzzle::retreatActiveIndex() {
    if (0 < activeIndex) {
        uncolorActiveBody();
        activeIndex--;
        colorActiveBody();
    }
}
