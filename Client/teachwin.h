

#ifndef TEACHWIN_H
#define TEACHWIN_H

#include <QWidget>
#include <client.h>


namespace Ui {
class TeachWin;
}

/**
 * @brief The StudReg class is a window for teachers to login and gather analytics on students
 * registered in the Stackd game API.
 */
class TeachWin : public QWidget
{
    Q_OBJECT

public:
    void deleteStudent(QString);
    void updateStudents();
    TeachWin(Client * client, QWidget *parent=0);
    explicit TeachWin(QWidget *parent = 0);
    ~TeachWin();
    void setCurrentUsername(QString currentUsername);

private slots:
    void on_logoutButton_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_clicked();

private:
    Ui::TeachWin *ui;
    Client * client;
    QString currentUsername;
};

#endif // TEACHWIN_H
