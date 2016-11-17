#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QWidget>

namespace Ui {
class LoginWin;
}

class LoginWin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWin(QWidget *parent = 0);
    ~LoginWin();

private:
    Ui::LoginWin *ui;
};

#endif // LOGINWIN_H
