#include <spritedefinition.h>
#include <cmath>
#include <math.h>

SpriteDefinition::SpriteDefinition(int x, int y, b2BodyType type, std::string s){
    body = new b2BodyDef;
    body->active=true;
    body->type = type ;
    body->position.x=x;
    body->position.y=y;
    name = s;
    color = sf::Color::Green;
}

SpriteDefinition::SpriteDefinition(){
    body = new b2BodyDef;
    body->active=true;
}


SpriteDefinition::~SpriteDefinition(){

}


void SpriteDefinition::friction(bool yes){
    b2FixtureDef * def = (fixtures.front());
    if(yes){
        def->friction=1;
    }else if (!yes) {
        def->friction=0;
    }


}
void SpriteDefinition::setColor(sf::Color color){
   this->color=color;
}

void SpriteDefinition::setShape(int count, int width, int height){
    b2PolygonShape * shape = new b2PolygonShape;
    b2FixtureDef * def = new b2FixtureDef;
    def->density=1;

    //SETUP
    if(width<9)width=10; // filter bad input
    if(height<9)height=10;
    if(count < 3)count = 3;
    else if(count > 8)count = 8;
    double alpha = 0;
    if(count == 4){ //the way the alg works it makes it crooked.
       alpha = M_PI/4; //so we are just straightening things out
    }else if(count ==3){
       alpha = 3*M_PI/2;
    }

    //GATHER POINTS
    std::vector<b2Vec2> points;
    for(int i = 0; i < count; i++){
        int tempx =0;
        int tempy =0;
        tempx+= (width) * std::cos(alpha + (2 * M_PI * i / count));
        tempx+= body->position.x;
        tempy+= (height) * std::sin(alpha + (2 * M_PI * i / count));
        tempy+= body->position.y;
        b2Vec2 vec(tempx,tempy);
        points.push_back(vec);
    }

    //CREATE SHAPE and return
    shape->Set(&*points.begin(),count);
    def->shape = shape;
    fixtures.push_back(def);
}
