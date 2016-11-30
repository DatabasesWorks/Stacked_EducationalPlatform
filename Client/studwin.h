#ifndef STUDWIN_H
#define STUDWIN_H

#include <QWidget>
#include <client.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Ui {
class StudWin;
}

class StudWin : public QWidget, sf::RenderWindow
{
    Q_OBJECT

public:
    explicit StudWin(QWidget *parent = 0);
    ~StudWin();

private slots:
    void on_hideButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::StudWin *ui;
    bool levelshow;

    void setupLevels();
};

#endif // STUDWIN_H
