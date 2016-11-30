#include "sprite2dobject.h"

// A class to integrate the SFML sprite class with the Box2D objects.
sprite2dObject::sprite2dObject(){

}

sprite2dObject::~sprite2dObject(){

}

sprite2dObject::sprite2dObject(std::string filename, b2World world, b2BodyDef def) // call the super constructor
{
    sf::Texture texture;
    if(!texture.loadFromFile(filename)){
        //throw exception
        filenotfoundexception ex(filename);
        throw ex;
    }
    sprite=new sf::Sprite(texture);
    body = world.CreateBody(&def);

}

void sprite2dObject::setFixture(b2FixtureDef def){
    fixture = body->CreateFixture(&def);
}

void sprite2dObject::setSprite(sf::Image image){
  // sprite = new sf::Sprite(sf::Texture::loadFromImage(image)));
}

sf::Sprite * sprite2dObject::getSprite(){

    //Draw sprite from box2d information
    //http://en.sfml-dev.org/forums/index.php?topic=20216.0
    //http://www.iforce2d.net/b2dtut/fixtures

    b2PolygonShape* polyShape = new b2PolygonShape(); //delete this line -- added so it would compile
    //Need fixture var?
//    b2PolygonShape* polyShape = (b2PolygonShape*) bodyFixture->GetShape();

    sf::ConvexShape shapeToFill;
    shapeToFill.setPosition(body->GetPosition().x*SCALE, -body->GetPosition().y*SCALE);

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
    return sprite;
}

b2Body * sprite2dObject::getBody(){
    return body;
}
