//#ifndef GRAPHICSOBJECT_H
//#define GRAPHICSOBJECT_H
////#undef Bool

//#include <QObject>
//#include <QWidget>
//#include <SFML/Graphics.hpp>
//#include <QTimer>
////#ifdef Q_WS_X11
////    #include <Qt/qx11info_x11.h>
////    #include <X11/Xlib.h>
////#endif

////Sourced: http://www.sfml-dev.org/tutorials/1.6/graphics-qt.php
////Also: https://www.youtube.com/watch?v=D9XK1KHI0Xk
////Also: http://becomingindiedev.blogspot.com/2013/10/qt-5-and-sfml-20-integration.html
//class GraphicsObject : public QWidget, public sf::RenderWindow
//{
//    Q_OBJECT
//public:

//    explicit GraphicsObject(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
//    //Some of these may be private?
//    virtual QPaintEngine *paintEngine() const;
//    virtual void showEvent(QShowEvent *event);
//    virtual void paintEvent(QPaintEvent*);
//    virtual void OnUpdate();
//    virtual void OnInit();
//    virtual ~GraphicsObject();


//signals:

//public slots:

//private :
//    QTimer myTimer;
//    bool   myInitialized;
//};

//#endif // GRAPHICSOBJECT_H
