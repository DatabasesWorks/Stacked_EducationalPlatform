#ifndef TEACHREG_H
#define TEACHREG_H

#include <QWidget>

namespace Ui {
class TeachReg;
}

class TeachReg : public QWidget
{
    Q_OBJECT

public:
    explicit TeachReg(QWidget *parent = 0);
    ~TeachReg();

private:
    Ui::TeachReg *ui;
};

#endif // TEACHREG_H
