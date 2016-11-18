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

private slots:
    void on_loginButton_clicked();

    void on_regStud_clicked();

    void on_regTeach_clicked();

private:
    Ui::LoginWin *ui;
};

#endif // LOGINWIN_H
