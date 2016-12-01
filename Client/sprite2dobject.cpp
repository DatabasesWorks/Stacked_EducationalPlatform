#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.
sprite2dObject::sprite2dObject(){


}

//
sprite2dObject::~sprite2dObject(){

}

sprite2dObject::sprite2dObject(std::string description, b2World* world, b2BodyDef* def) // call the super constructor
{
    description.begin();
    //do something w/ description
    sprite=new sf::Sprite;
    body = world->CreateBody(def);

}

void sprite2dObject::setFixture(b2FixtureDef* def){
    body->CreateFixture(def);
}

void sprite2dObject::setSprite(sf::Image image){
  // sprite = new sf::Sprite(sf::Texture::loadFromImage(image)));
}

sf::ConvexShape *  sprite2dObject::getShape(){
    //Draw sprite from box2d information
    //http://en.sfml-dev.org/forums/index.php?topic=20216.0
    //http://www.iforce2d.net/b2dtut/fixtures
    //http://box2d.org/forum/viewtopic.php?t=7261
    for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()){
         b2Shape::Type type = f->GetType();
         if(type==b2Shape::e_polygon){
           b2PolygonShape* polyShape= (b2PolygonShape*)f->GetShape();
           sf::ConvexShape * shapeToFill = new sf::ConvexShape;
           shapeToFill->setFillColor(sf::Color::White);
           shapeToFill->setPosition(body->GetPosition().x*SCALE, -body->GetPosition().y*SCALE);
           int vertCount = polyShape->GetVertexCount();
           shapeToFill->setPointCount(vertCount);
           for(int vert = 0 ; vert < vertCount ; vert++) {
              b2Vec2 aVertex = polyShape->GetVertex(vert);
              sf::Vector2f sfVect;
              sfVect.x = aVertex.x*SCALE;
              sfVect.y = aVertex.y*SCALE;
              shapeToFill->setPoint(vert,sfVect);
           }

           shapeToFill->setRotation(180/b2_pi * body->GetAngle());
           return shapeToFill;
         }
    }
    return nullptr;
}

b2Body * sprite2dObject::getBody(){
    return body;
}
