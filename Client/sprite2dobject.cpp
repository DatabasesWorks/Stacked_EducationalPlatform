#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.
sprite2dObject::sprite2dObject(){
    body=NULL;
    sprite = NULL;
}

sprite2dObject::~sprite2dObject(){
    body->GetWorld()->DestroyBody(body);
    body = NULL;
    color = sf::Color::White;
    text.setString("");
}

sprite2dObject::sprite2dObject(std::string description, b2World* world, b2BodyDef* def) : sprite2dObject() // call the super constructor
{
    body = world->CreateBody(def);
    name = description;

    if (!font.loadFromFile("datacontrol.ttf"))
    {
       // error
    }
    text.setFont(font);
    text.setCharacterSize(20);
}

sprite2dObject::sprite2dObject(b2World* world, SpriteDefinition def) : sprite2dObject(def.name,world,def.body) // call the super constructor
{
    setText(def.text);
    text.setString(def.text);
    body->CreateFixture(def.fixture);
    color = def.color;
}

void sprite2dObject::bindToMouse()
{



}

void sprite2dObject::unbind(){



}


void sprite2dObject::changeColor(sf::Color color){
   this->color=color;
}

void sprite2dObject::setText(std::string string, sf::Color color){

   text.setColor(color);
   text.setString(string);


}

sf::Text sprite2dObject::getText(){

   b2Vec2 vec(body->GetLocalVector(body->GetPosition()));
   text.setPosition(vec.x,vec.y);
   text.setScale(100,100);
   return text;
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

//not implemented
void sprite2dObject::applyAngularForce(Direction d, double magnitude){
    if(d==right||d==down){ // not implemented
        body->ApplyAngularImpulse(magnitude,true);
    }else if(d==left||d==up) return;
}

void sprite2dObject::connectRope(sprite2dObject * other){
     b2RopeJointDef jd;
     b2Vec2 vec(other->getBody()->GetPosition()-getBody()->GetPosition());
     b2Vec2 tmp(vec.x,vec.y);
     jd.maxLength=tmp.Normalize();
     jd.bodyA=getBody();
     jd.bodyB=other->getBody();
     jd.localAnchorA=getBody()->GetLocalVector(getBody()->GetPosition());
     jd.localAnchorB=other->getBody()->GetLocalVector(other->getBody()->GetPosition());
     jd.collideConnected=false;
     b2Joint * joint = getBody()->GetWorld()->CreateJoint(&jd);
     joints.push_back(joint);
}

void sprite2dObject::connectBar(sprite2dObject * other){
     b2DistanceJointDef jd;
     b2Vec2 vec(other->getBody()->GetPosition()-getBody()->GetPosition());
     b2Vec2 tmp(std::abs(vec.x),std::abs(vec.y));
     jd.dampingRatio=0.01;
     jd.frequencyHz=0;
     jd.length=tmp.Normalize();
     jd.bodyA=getBody();
     jd.bodyB=other->getBody();
     jd.localAnchorA=getBody()->GetLocalVector(getBody()->GetPosition());
     jd.localAnchorB=other->getBody()->GetLocalVector(other->getBody()->GetPosition());
     jd.collideConnected=false;
     b2Joint * joint = getBody()->GetWorld()->CreateJoint(&jd);
     joints.push_back(joint);
}

void sprite2dObject::ignoreObject(){
     b2Fixture * fi = body->GetFixtureList();
     b2Filter fill;
     fill.categoryBits=0;
     fill.maskBits=0;
     fi->SetFilterData(fill);
     ignore = true;
}

bool sprite2dObject::isIgnored(){
    return ignore;
}

sf::ConvexShape sprite2dObject::getShape(){
    //Draw sprite from box2d information
    //http://en.sfml-dev.org/forums/index.php?topic=20216.0
    //http://www.iforce2d.net/b2dtut/fixtures
    //http://box2d.org/forum/viewtopic.php?t=7261
    sf::ConvexShape shapeToFill;
    for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()){
         b2Shape::Type type = f->GetType();
         if(type==b2Shape::e_polygon){
           b2PolygonShape* polyShape= (b2PolygonShape*)f->GetShape();
           shapeToFill.setFillColor(color);
           b2Vec2 vec(body->GetPosition());
           //b2Vec2 vec(body->GetLocalVector(body->GetPosition()));
           shapeToFill.setPosition(vec.x*SCALE, vec.y*SCALE);
           int vertCount = polyShape->GetVertexCount();
           shapeToFill.setPointCount(vertCount);
           for(int vert = 0 ; vert < vertCount ; vert++) {
              b2Vec2 aVertex = polyShape->GetVertex(vert);
              sf::Vector2f sfVect;
              sfVect.x = aVertex.x*SCALE;
              sfVect.y = aVertex.y*SCALE;
              shapeToFill.setPoint(vert,sfVect);
           }

           shapeToFill.setRotation(180/b2_pi * body->GetAngle());
           width = shapeToFill.getLocalBounds().width;
           height = shapeToFill.getLocalBounds().height;
         }
    }
    return shapeToFill;
}

void sprite2dObject::setSprite(std::string pathname){
    sf::Texture tex;
    tex.loadFromFile(pathname);
    sprite = new sf::Sprite(tex);
}

sf::Sprite * sprite2dObject::getSprite(){
    if(sprite!=nullptr){
        b2Vec2 vec(getBody()->GetLocalVector(body->GetPosition()));
        sprite->setPosition(vec.x,vec.y);
    }
    return sprite;
}

void sprite2dObject::setName(std::string n){
    name=n;
}

std::string sprite2dObject::getName()
{
    return name;
}

void sprite2dObject::setFriction(double f){
    body->GetFixtureList()->SetFriction(f);
}

void sprite2dObject::setDensity(double f){
    body->GetFixtureList()->SetDensity(f);
}

b2Vec2 sprite2dObject::getSize(){
    b2Vec2 vec(width,height);
    return vec;
}

b2Body * sprite2dObject::getBody(){
    return body;
}

void sprite2dObject::mark(){
    remove = true;
}

bool sprite2dObject::marked(){
    return remove;
}
