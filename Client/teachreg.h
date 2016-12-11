#ifndef TEACHREG_H
#define TEACHREG_H

#include <QWidget>
#include <client.h>

namespace Ui {
class TeachReg;
}

class TeachReg : public QWidget
{
    Q_OBJECT

public:
    explicit TeachReg(QWidget *parent = 0);
    TeachReg(Client * client, QWidget *parent=0);

    ~TeachReg();

private slots:
    void on_regButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TeachReg *ui;
     Client * client;
};

#endif // TEACHREG_H
