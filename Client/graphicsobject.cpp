#include "graphicsobject.h"

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
            sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
            OnInit();
            connect(&gotimer, SIGNAL(timeout()), this, SLOT(repaint()));
            gotimer.start();
            goinitialized=true;
        }

//

//        // Create the SFML window with the widget handle
//        //UPDATED
//        QWidget::create(QWidget::effectiveWinId());

//        // Let the derived class do its specific stuff
//        OnInit();

//        // Setup the timer to trigger a refresh at specified framerate
//        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
//        myTimer.start();

//        myInitialized = true;

}

QPaintEngine* GraphicsObject::paintEngine() const
{
    return 0;
}

void GraphicsObject::paintEvent(QPaintEvent* event)
{
    RenderWindow::clear();
    OnUpdate();
    RenderWindow::display();
}

void GraphicsObject::OnInit()
{
    //to override
}

void GraphicsObject::OnUpdate()
{
    //to override
}

