#include "graphicsobject.h"

//A QWidget for rending SFML sprites in QT
GraphicsObject::GraphicsObject(QWidget* Parent):
QWidget(Parent), goinitialized(false)

{
        // Setup some states to allow direct rendering into the widget
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_OpaquePaintEvent);
        setAttribute(Qt::WA_NoSystemBackground);

        // Set strong focus to enable keyboard events to be received
        setFocusPolicy(Qt::StrongFocus);
}





void GraphicsObject::showEvent(QShowEvent *event)
{
        if(goinitialized == false)
        {
            //Under X11, we need to flush the commands sent to the server to ensure that
            //SFML will get an updated view of the windows
            #ifdef Q_WS_X11
                XFlush(QX11Info::display());
            #endif
            #ifdef __APPLE__
                sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
            #elif __linux__
                sf::RenderWindow::create((sf::WindowHandle) winId());
            #elif __unix__ // all unices not caught above
                sf::RenderWindow::create((sf::WindowHandle) winId());
            #elif _WIN32
                sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
            #endif

            OnInit();
            connect(&gotimer, SIGNAL(timeout()), this, SLOT(repaint()));
            gotimer.start();
            goinitialized=true;
        }


//***OLD STUFF*** DELETE LATER
//        // Create the SFML window with the widget handle
//        //UPDATED
//        QWidget::create(QWidget::effectiveWinId());

//        // Let the derived class do its specific stuff
//        OnInit();

//        // Setup the timer to trigger a refresh at specified framerate
//        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
//        myTimer.start();

//        myInitialized = true;
//***END DELETE
}

//Don't know what this does
QPaintEngine* GraphicsObject::paintEngine() const
{
    return 0;
}

//Updates the window or something
void GraphicsObject::paintEvent(QPaintEvent* event)
{
    RenderWindow::clear();
    OnUpdate();
    RenderWindow::display();
}

//Will be written by derived class
void GraphicsObject::OnInit()
{
    //to override
}

//Will be written by derived class
void GraphicsObject::OnUpdate()
{
    //to override
}

