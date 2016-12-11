
#ifndef TEACHWIN_H
#define TEACHWIN_H

#include <QWidget>
#include <client.h>


namespace Ui {
class TeachWin;
}

class TeachWin : public QWidget
{
    Q_OBJECT

public:
    void updateStudents();
    TeachWin(Client * client, QWidget *parent=0);
    explicit TeachWin(QWidget *parent = 0);
    ~TeachWin();

private slots:
    void on_logoutButton_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_clicked();

private:
    Ui::TeachWin *ui;
    Client * client;
};

#endif // TEACHWIN_H
