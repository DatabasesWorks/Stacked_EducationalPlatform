#include "listpuzzle.h"

ListPuzzle::ListPuzzle(QSize size) : Puzzle(size) {
    establishGravity();
    establishFloor();

    instructionstream << "Keys:" << std::endl;
    instructionstream << "Press X/C to move left/right" << std::endl <<
                         "Press W/E to push front/back" << std::endl <<
                         "Press S/D to pop front/back" << std::endl <<
                         "Press Space/D to add/delete at selection" << std::endl <<
                         "Press Q/A to cycle through values" << std::endl <<
                         "Press R to reset" << std::endl <<
                         "Press Enter to submit solution" << std::endl;
    b2Vec2 pos(105,55);
    createInstructions(pos);

    instructionstream.str("");
    instructionstream << "The next added block will have the value:" << std::endl;
    b2Vec2 pos2(105,230);
    createInstructions(pos2);

    possibleValues.push_back("A");
    possibleValues.push_back("B");
    possibleValues.push_back("C");
    nextValueIndex = 0;
    nextValue = possibleValues[nextValueIndex];
    instructionstream.str("");
    instructionstream << nextValue << std::endl;
    b2Vec2 pos3(215,225);
    createInstructions(pos3);
    updateNextValueDisplay();

    addFirstBody();
}

void ListPuzzle::addFirstBody(std::string value) {
    std::string valueToAdd;
    bool addToWorkingSet = true;
    if (value.compare("") != 0) {
        valueToAdd = value;
        addToWorkingSet = false;
    } else {
        valueToAdd = nextValue;
    }

    this->addComponent("list body", 4, CubeSideLength, CubeSideLength, InitialXSpawn, YSpawn, b2_staticBody, false, false, valueToAdd);
    activeIndex = 0;
    colorActiveBody();
    if (addToWorkingSet) {
        workingSet.push_front(std::make_pair(valueToAdd, true));
    }
}

void ListPuzzle::reset() {
    if (components.size() > 0) {
        int size = components.size();
        components.clear();

        int stackingHeight = 1;
        if (size >= 20) {
            stackingHeight = size / 10;
        }

        std::list<std::pair<std::string, bool>>::iterator it = workingSet.begin();

        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, (InitialXSpawn - (size / 2 * deltaX) / stackingHeight), YSpawn, b2_staticBody, false, false, std::get<0>(*it));
        std::advance(it, 1);
        activeIndex = 0;
        int currentStackHeight = 1;
        for (int i = 1; i < size; i++) {
            if (currentStackHeight == stackingHeight) {
                pushBack(std::get<0>(*it));
                advanceActiveIndex();
                currentStackHeight = 1;
            } else {
                addAtActiveIndex(std::get<0>(*it));
                currentStackHeight++;
            }
            std::advance(it, 1);
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
    } else if (key == Qt::Key_Enter) {
        bool solved = checkSolution();
    } else if (key == Qt::Key_Q) {
        cycleNextValue(false);
    } else if (key == Qt::Key_A) {
        cycleNextValue(true);
    }
}

void ListPuzzle::pushFront(){
    if (components.size() == 0) {
        addFirstBody();
    } else {
        b2Body *bod;
        bod = components.front()->getBody();
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, bod->GetPosition().x - deltaX, YSpawn, b2_staticBody, false, true, nextValue);
        components.front()->changeColor(DefaultColor);
        activeIndex++;
        workingSet.push_front(std::make_pair(nextValue, true));
    }
}

void ListPuzzle::pushBack(std::string value){
    std::string valueToAdd;
    bool addToWorkingSet = true;
    if (value.compare("") != 0) {
        valueToAdd = value;
        addToWorkingSet = false;
    } else {
        valueToAdd = nextValue;
    }

    if (components.size() == 0) {
        addFirstBody(valueToAdd);
    } else {
        b2Body *bod;
        bod = components.back()->getBody();
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, bod->GetPosition().x + deltaX, YSpawn, b2_staticBody, false, false, valueToAdd);
        components.back()->changeColor(DefaultColor);
        if (addToWorkingSet) {
            workingSet.push_back(std::make_pair(valueToAdd, true));
        }
    }
}

void ListPuzzle::addAtActiveIndex(std::string value) {
    std::string valueToAdd;
    bool addToWorkingSet = true;
    if (value.compare("") != 0) {
        valueToAdd = value;
        addToWorkingSet = false;
    } else {
        valueToAdd = nextValue;
    }

    if (components.size() == 0) {
        addFirstBody(valueToAdd);
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
        this->addComponent("list body", 4, CubeSideLength, CubeSideLength, xToSpawn, yToSpawn, b2_staticBody, false, false, valueToAdd);
        sprite2dObject* newlyAdded = components.back();
        newlyAdded->changeColor(DefaultColor);
        components.pop_back();
        components.insert(components.begin() + activeIndex + 1 + jumps, newlyAdded);
        if (addToWorkingSet) {
            std::list<std::pair<std::string, bool>>::iterator it = workingSet.begin();
            std::advance(it, activeIndex);
            workingSet.insert(it, std::make_pair(valueToAdd, true));
        }
        advanceActiveIndex();

        forceSyncWithWorkingSet();
    }
}

void ListPuzzle::deleteAtActiveIndex() {
    if (components.size() > 0) {
        b2Body *bod;
        bod = components[activeIndex]->getBody();
        thisWorld->DestroyBody(bod);
        components.erase(components.begin() + activeIndex);
        std::list<std::pair<std::string, bool>>::iterator it = workingSet.begin();
        if (activeIndex > 0) {
            std::advance(it, activeIndex - 1);
        } else {
            std::advance(it, activeIndex);
        }
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

bool ListPuzzle::checkSolution() {
    std::stringstream workingStream;
    std::stringstream solutionStream;
    for (auto iter = workingSet.begin(); iter != workingSet.end(); iter++) {
        workingStream << std::get<0>(*iter);
    }
    std::string workingString = workingStream.str();
    for (auto iter = solutionSet.begin(); iter != solutionSet.end(); iter++) {
        solutionStream << *iter;
    }
    std::string solutionString = solutionStream.str();
    return (solutionString.compare(workingString) == 0);
}

void ListPuzzle::updateNextValueDisplay() {
    inactive_components[3]->setText(nextValue, sf::Color::White);
}

void ListPuzzle::cycleNextValue(bool scrollDown) {
    if (scrollDown) {
        if (nextValueIndex == ((int) possibleValues.size()) - 1) {
            nextValueIndex = 0;
        } else {
            nextValueIndex++;
        }
    } else {
        if (nextValueIndex == 0) {
            nextValueIndex = possibleValues.size() - 1;
        } else {
            nextValueIndex--;
        }
    }

    nextValue = possibleValues[nextValueIndex];
    updateNextValueDisplay();
}

void ListPuzzle::forceSyncWithWorkingSet() {
    int index = 0;
    for (auto iter = workingSet.begin(); iter != workingSet.end(); iter++) {
        components[index]->setText(std::get<0>(*iter), sf::Color::White);
        index++;
    }
}
