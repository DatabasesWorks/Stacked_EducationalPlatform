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
}

SpriteDefinition::SpriteDefinition(){


}

void SpriteDefinition::setShape(int count, int width, int height){
    b2PolygonShape * shape = new b2PolygonShape;
    int size = 10;
    std::vector<b2Vec2> points;

    double alpha = 0;
    if(count == 4){
        alpha = M_PI/4;
    }else if(count ==3){
        alpha = 3*M_PI/2;
    }

    for(int i = 0; i < count; i++){
        int tempx =0;
        int tempy =0;
        tempx+= (size+width) * std::cos(alpha + (2 * M_PI * i / count));
        tempx+= body->position.x;
        tempy+= (size+height) * std::sin(alpha + (2 * M_PI * i / count));
        tempy+= body->position.y;
        b2Vec2 vec(tempx,tempy);
        points.push_back(vec);
    }
    shape->Set(&*points.begin(),count);

    b2FixtureDef * def = new b2FixtureDef;
    def->density=1;
    def->shape = shape;
    fixtures.push_back(def);
}

SpriteDefinition::~SpriteDefinition(){

}



