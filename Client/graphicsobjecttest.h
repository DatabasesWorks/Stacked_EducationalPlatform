#ifndef GRAPHICSOBJECTTEST_H
#define GRAPHICSOBJECTTEST_H
#include <graphicsobject.h>
#include <SFML/Graphics/Drawable.hpp>

class GraphicsObjectTest : public GraphicsObject
{
public :

    GraphicsObjectTest(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime);

    ~GraphicsObjectTest();

private:
//    sf::Image  myImage;
    sf::Texture myImage;
    sf::Sprite mySprite;
    void OnInit();
    void OnUpdate();
    int rot=1;

};

#endif // GRAPHICSOBJECTTEST_H
