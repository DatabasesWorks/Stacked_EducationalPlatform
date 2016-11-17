#ifndef STUDWIN_H
#define STUDWIN_H

#include <QWidget>

namespace Ui {
class StudWin;
}

class StudWin : public QWidget
{
    Q_OBJECT

public:
    explicit StudWin(QWidget *parent = 0);
    ~StudWin();

private:
    Ui::StudWin *ui;
};

#endif // STUDWIN_H
