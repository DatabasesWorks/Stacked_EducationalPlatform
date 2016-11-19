#ifndef TEACHWIN_H
#define TEACHWIN_H

#include <QWidget>

namespace Ui {
class TeachWin;
}

class TeachWin : public QWidget
{
    Q_OBJECT

public:
    explicit TeachWin(QWidget *parent = 0);
    ~TeachWin();

private slots:
    void on_logoutButton_clicked();

private:
    Ui::TeachWin *ui;
};

#endif // TEACHWIN_H
