#ifndef STUDWIN_H
#define STUDWIN_H
#include <QObject>
#include <QWidget>
#include <client.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <stackpuzzle.h>
#include <treepuzzle.h>
#include <arraypuzzle.h>
#include <listpuzzle.h>

namespace Ui {
class StudWin;
}

class StudWin : public QWidget, sf::RenderWindow
{
    Q_OBJECT

public:
    explicit StudWin(QWidget *parent = 0);
    ~StudWin();

//    void setMainGameWidget(QWidget *widget);

private slots:
    void on_hideButton_clicked();
    void on_logoutButton_clicked();
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::StudWin *ui;
    bool levelshow;
    PuzzleWindow* pw;
    void setupLevels();
    std::vector<Puzzle*> puzzles;
};

#endif // STUDWIN_H
