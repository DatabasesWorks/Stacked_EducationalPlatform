#include "arraypuzzle.h"
ArrayPuzzle::ArrayPuzzle(QSize size) : Puzzle(size){
    createEnvironment();
    for(int i = 0; i < 5; i++){
        this->addComponent("array_"+i, 4, 50, 25, 20+(i*45), -25, b2_dynamicBody);
        randomNum = rand() % 51;
        components[i]->setText(std::to_string(randomNum), sf::Color::Black);
    }
    activeIndex = 0;

    components[0]->changeColor(sf::Color::Blue);
}

ArrayPuzzle::~ArrayPuzzle() {}

void ArrayPuzzle::runAction(Qt::Key key){
    if(key == Qt::Key_Left){
        if(activeIndex != 0){
            components[activeIndex]->changeColor(sf::Color::White);
            activeIndex--;
            components[activeIndex]->changeColor(sf::Color::Blue);
        }
    }
    if(key == Qt::Key_Right){
        if(activeIndex < components.size()-1){
            components[activeIndex]->changeColor(sf::Color::White);
            activeIndex++;
            components[activeIndex]->changeColor(sf::Color::Blue);
        }
    }
    if(key == Qt::Key_E){
        replaceAtIndexAction();
    }
    if(key == Qt::Key_R){
        getNumAtActive();
    }
}

void ArrayPuzzle::replaceAtIndexAction(){

    sprite2dObject * old = components[activeIndex];
    SpriteDefinition def;
    def.setShape(4,50,25);
    def.setType(b2_dynamicBody);
    def.setColor(sf::Color::Red);
    def.setBorderColor(sf::Color::Red);
    sf::FloatRect rect = old->getShape().getGlobalBounds();
    def.setPosition(rect.left+rect.width/2,rect.top+rect.height/4);
    def.setInitialVelocity(0,b2Vec2(0,200));
    delete old;
    sprite2dObject * replacement = new sprite2dObject(thisWorld,def);
    components[activeIndex] = replacement;
    randomNum = rand() % 51;
    components[activeIndex]->setText(std::to_string(randomNum), sf::Color::Black);
}

void ArrayPuzzle::createEnvironment(){
    b2Vec2 grav(0, 0.98);
    thisWorld->SetGravity(grav);

    SpriteDefinition floordef(100, 200, b2_staticBody, "testbox");
    floordef.setShape(4, 1500, 0);

    SpriteDefinition leftwalld(0,20, b2_staticBody, "leftwalld");
    leftwalld.setShape(4,0,500);
    leftwalld.setColor(sf::Color::Red);
    addComponent(leftwalld, true);

    sprite2dObject *floor = new sprite2dObject(thisWorld, floordef);
    inactive_components.push_back(floor);
}

void ArrayPuzzle::addAtIndexAction(){
     b2Body *bod;
     int x;
     bod = components[activeIndex]->getBody();
     x = bod->GetPosition().x;
     int y = bod->GetPosition().y;
     this->thisWorld->DestroyBody(bod);
     //might want to restrict the deletion if size = 1
     //components.erase(components.begin() + activeIndex);
     this->replaceComponent("array_"+activeIndex, 4, 50, 25, x, y, b2_dynamicBody, activeIndex);
     components[activeIndex]->changeColor(sf::Color::Blue);
}

std::string ArrayPuzzle::getNumAtActive(){
    std::string num;
    num = components[activeIndex]->getText()->getString();
    return num;
}
