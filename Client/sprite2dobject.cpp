#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.
sprite2dObject::sprite2dObject(){
   body=nullptr;
}

#include <spritedefinition.h>
sprite2dObject::~sprite2dObject(){
}

sprite2dObject::sprite2dObject(std::string description, b2World* world, b2BodyDef* def) // call the super constructor
{
    color = sf::Color::White;
    name = description;
    body = world->CreateBody(def);
}

sprite2dObject::sprite2dObject(b2World* world, SpriteDefinition def) // call the super constructor
{
    body = world->CreateBody(def.body);
    for(auto it = def.fixtures.begin(); it < def.fixtures.end(); it++){
        body->CreateFixture(*it);
    }
    color = def.color;
    name = def.name;
}

void sprite2dObject::moveBody(Direction d, int magnitude){


    int scale = body->GetMass()*magnitude;
    body->SetAwake(true);
    switch (d) {
       case left:
       {
           b2Vec2 vec(-1*scale,0);
           body->ApplyForce(vec,body->GetPosition(),true);
           break;
       }
       case right:
       {
           b2Vec2 vec(1*scale,0);
           body->ApplyForce(vec,body->GetPosition(),true);
           break;
       }
       case up:
       {
           b2Vec2 vec(0,-1*scale);
           body->ApplyLinearImpulse(vec,body->GetPosition(),true);
           break;
       }
       case down:
       {
           b2Vec2 vec(0,-1*scale);
           body->ApplyLinearImpulse(vec,body->GetPosition(),true);
           break;
       }
       default:
       {
           break;
       }
    }
}

void sprite2dObject::connect(sprite2dObject * other, b2World* world, int length){
     b2DistanceJointDef jd;
     jd.bodyA=this->getBody();
     jd.bodyB=other->getBody();
     jd.length=length;
     b2Joint * joint = world->CreateJoint(&jd);
     joints.push_back(joint);
}

sf::ConvexShape * sprite2dObject::getShape(){
    //Draw sprite from box2d information
    //http://en.sfml-dev.org/forums/index.php?topic=20216.0
    //http://www.iforce2d.net/b2dtut/fixtures
    //http://box2d.org/forum/viewtopic.php?t=7261
    for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()){
         b2Shape::Type type = f->GetType();
         if(type==b2Shape::e_polygon){
           b2PolygonShape* polyShape= (b2PolygonShape*)f->GetShape();
           sf::ConvexShape * shapeToFill = new sf::ConvexShape;
           shapeToFill->setFillColor(color);
           shapeToFill->setPosition(body->GetPosition().x*SCALE, body->GetPosition().y*SCALE);
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
           width = shapeToFill->getLocalBounds().width;
           height = shapeToFill->getLocalBounds().height;
           return shapeToFill;
         }
    }
    return nullptr;
}

b2Body * sprite2dObject::getBody(){
    return body;
}
