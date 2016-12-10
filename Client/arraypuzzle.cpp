#include "arraypuzzle.h"
ArrayPuzzle::ArrayPuzzle(QSize size) : Puzzle(size){
    createEnvironment();
    for(int i = 0; i < 5; i++){
        this->addComponent("array_"+i, 4, 50, 25, 20+(i*45), -25, b2_dynamicBody);
        randomNum = rand() % 8+1;
        components[i]->setText(std::to_string(randomNum), sf::Color::Black);
    }
    activeIndex = 0;

    components[0]->changeColor(sf::Color::Magenta);

    setupInstructions();
    setupQuestion();

    equationCount = 0;
}

ArrayPuzzle::~ArrayPuzzle() {}

void ArrayPuzzle::runAction(Qt::Key key){
    if(key == Qt::Key_Left){
        if(activeIndex != 0){
            components[activeIndex]->changeColor(sf::Color::White);
            activeIndex--;
            components[activeIndex]->changeColor(sf::Color::Magenta);
        }
    }
    if(key == Qt::Key_Right){
        if(activeIndex < components.size()-1){
            components[activeIndex]->changeColor(sf::Color::White);
            activeIndex++;
            components[activeIndex]->changeColor(sf::Color::Magenta);
        }
    }
    if(key == Qt::Key_E){
        replaceAtIndexAction();
    }
    if(key == Qt::Key_R){
        setupEquation(getNumAtActive());
        equationCount++;
    }
    if(key == Qt::Key_Plus){
        setupEquation("+");
        equationCount++;

    }
    if(key == Qt::Key_Minus){
        setupEquation("-");
        equationCount++;
    }
    if(key == Qt::Key_Asterisk){
        setupEquation("*");
        equationCount++;
    }
    if(key == Qt::Key_Slash){
        setupEquation("/");
        equationCount++;
    }
    if(key == Qt::Key_ParenLeft){
        setupEquation("(");
        equationCount++;
    }
    if(key == Qt::Key_ParenRight){
        setupEquation(")");
        equationCount++;
    }
    if(key == Qt::Key_Return){
        Calculator c;
        //std::cout << c.calculate ("(20+10)*3/2-3") << std::endl;
        std::string equation = getComponent("equation_box",false)->getText()->getString();
        //std::cout << c.calculate(equation)<< std::endl;
        if(!question1Done && (equation.length() > 0)){
            if(firstAnswer == c.calculate(equation)){
                question1Done = true;
                getComponent("question_1",false)->setTextColor(sf::Color::Green);
                clearEntireEquation();
                setupQuestion();
            }                
        }
        else if(!question2Done && (equation.length() > 0)){
            if(secondAnswer == c.calculate(equation)){
                question2Done = true;
                getComponent("question_2",false)->setTextColor(sf::Color::Green);
                foreach (sprite2dObject* obj, components) {
                    obj->applyAngularForce(sprite2dObject::up, rand() % 500);
                }
            }
        }
    }
    if(key == Qt::Key_Backspace){
        //std::cout<<"backspace" <<std::endl;
        if(equationCount != 0){
            clearEquation();
            equationCount--;
        }
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
    delete old;
    sprite2dObject * replacement = new sprite2dObject(thisWorld,def);
    components[activeIndex] = replacement;
    randomNum = rand() % 8+1;
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

    //just set this up once. Before it was creating a text over the other one
    b2Vec2 pos_(300, 450);
    std::string equation = "equation_box";
    SpriteDefinition box;
    box.name=equation;
    box.setShape(4, 0, 0);
    box.setType(b2_staticBody);
    box.setBorderColor(sf::Color::Transparent);
    box.setColor(sf::Color::Transparent);
    box.setPosition(pos_.x,pos_.y);
    sprite2dObject * obj = new sprite2dObject(thisWorld, box);
    obj->setText("", sf::Color::White);
    obj->ignoreObject();
    addComponent(obj, true);

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
     components[activeIndex]->changeColor(sf::Color::Magenta);
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
                         "      Backspace: Deletes last input."<<std::endl<<
                         "      Enter/Return: Perform arithmetic!" <<std::endl<<
                         "Good luck!" <<std::endl;

    b2Vec2 pos(280, 80);
    createInstructions(pos);
}


void ArrayPuzzle::setupQuestion(){
    instructionstream.str("");
    b2Vec2 pos2(100, 450);
    if(!question1Done){
       if(getComponent("question_1",false)==nullptr){
            createTextBox(pos2.x,pos2.y,"Get result : 13","question_1");
       }
    }
    else if(!question2Done){
        pos2.y+=10;
        if(getComponent("question_2",false)==nullptr){
            createTextBox(pos2.x,pos2.y,"Get result: 55","question_2");
       }
    }
   //    if(!question1Done){
   //        instructionstream<<"Get result: 13" <<std::endl;
   //        createInstructions(pos2);
   //    }
   //    else if(!question2Done){
   //        instructionstream<<"Get result: 55" <<std::endl;
   //        b2Vec2 pos2(50, 250);
   //        createInstructions(pos2);
   //    }
}

void ArrayPuzzle::setupEquation(std::string s){
    sprite2dObject * obj = getComponent("equation_box",false);
    if(obj !=nullptr){
        std::string nextString = obj->getText()->getString().toAnsiString();
        nextString.append(s);
        obj->setText(nextString, sf::Color::White);
    }
}

void ArrayPuzzle::clearEquation(){
    sprite2dObject * obj = getComponent("equation_box",false);
    if(obj !=nullptr){
        std::string newString = obj->getText()->getString().toAnsiString();
        newString.pop_back();
        obj->setText(newString, sf::Color::White);
    }
}

void ArrayPuzzle::clearEntireEquation(){
    while(equationCount != 0){
        clearEquation();
        equationCount--;
    }
}

