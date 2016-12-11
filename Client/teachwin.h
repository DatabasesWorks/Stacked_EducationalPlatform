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
    void updateStudents();
    explicit TeachWin(QWidget *parent = 0);
    ~TeachWin();
    void setCurrentUsername(QString currentUsername);

private slots:
    void on_logoutButton_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_clicked();

private:
    Ui::TeachWin *ui;
    QString currentUsername;

};

#endif // TEACHWIN_H
