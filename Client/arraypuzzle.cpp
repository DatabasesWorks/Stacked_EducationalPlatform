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

    setupInstructions();
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
    if(key == Qt::Key_Plus){

    }
    if(key == Qt::Key_Minus){

    }
    if(key == Qt::Key_Asterisk){

    }
    if(key == Qt::Key_Slash){
    }
    if(key == Qt::Key_ParenLeft){

    }
    if(key == Qt::Key_ParenRight){

    }
    if(key == Qt::Key_Return){
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

void ArrayPuzzle::setupInstructions(){
    instructionstream << "Welcome to the Array Puzzle, hip hip Array!" << std::endl;
    instructionstream << "Keys: Left and Right: change selected index." <<std::endl <<
                         "      E: replace data with new random number. " <<std::endl <<
                         "      R: Add selected data to equation." <<std::endl <<
                         "      (,),+,-,*,/: For selected operator." <<std::endl <<
                         "      Enter/Return: Perform arithmetic!" <<std::endl<<
                         "Good luck!" <<std::endl;

    b2Vec2 pos(280, 80);
    createInstructions(pos);

    instructionstream.str("");
    instructionstream<<"Get result: 13" <<std::endl <<
                       "Get result: 55" <<std::endl <<
                       "Get result: 233" <<std::endl;
    b2Vec2 pos2(50, 240);
    createInstructions(pos2);

}
