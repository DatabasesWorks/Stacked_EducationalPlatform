#ifndef STUDWIN_H
#define STUDWIN_H
#include <QObject>
#include <QPoint>
#include <QWidget>
#include <client.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <stackpuzzle.h>
#include <treepuzzle.h>
#include <arraypuzzle.h>
#include <listpuzzle.h>
#include <sstream>

#include <QApplication>
#include <QMessageBox>

namespace Ui {
class StudWin;
}

class StudWin : public QWidget, sf::RenderWindow
{
    Q_OBJECT

public:
    explicit StudWin(QWidget *parent = 0);
    StudWin(Client * client, QWidget *parent=0);

    ~StudWin();
    std::vector<bool> getSolvedList();
    std::vector<bool> getUpdatedPuzzles();
    void setCurrentUsername(QString currentUsername);

//    void setMainGameWidget(QWidget *widget);

private slots:
    void on_hideButton_clicked();
    void on_logoutButton_clicked();
//    void on_listWidget_currentRowChanged(int currentRow);

    void on_checkBox_stateChanged(int arg1);

    void on_puzzle1_clicked();

    void on_puzzle2_clicked();

    void on_puzzle3_clicked();

    void on_puzzle4_clicked();

private:
     Client * client;
    Ui::StudWin *ui;
    sf::Music music;
    bool levelshow;
    PuzzleWindow* pw;
    void setupLevels();
    std::vector<Puzzle*> puzzles;
    std::vector<bool> solvedPuzzles;
    std::vector<bool> convertStringsToBools(QVector<QString>);
    QString currentUsername;
    void updatePuzzles(int i);

};

#endif // STUDWIN_H
