#ifndef STUDREG_H
#define STUDREG_H

#include <QWidget>

namespace Ui {
class StudReg;
}

class StudReg : public QWidget
{
    Q_OBJECT

public:
    explicit StudReg(QWidget *parent = 0);
    ~StudReg();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::StudReg *ui;
};

#endif // STUDREG_H
