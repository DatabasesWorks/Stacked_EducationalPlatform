#include "studwin.h"
#include "ui_studwin.h"
#include "client.h"
#include <vector>
#include "qstandarditemmodel.h"


StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin) {
    ui->setupUi(this);
    levelshow = true;
    pw = new PuzzleWindow;
    ui->userLabel->setText("Welcome: TestUser");
    setupLevels();
    pw->setPuzzle(puzzles.front());
    //  pw->setFocus();
    QGridLayout *lay = new QGridLayout(this);
    lay->addWidget(pw);
    ui->mainGameWidget->setLayout(lay);
    //this->setStyleSheet("background-color: black; color: white;");
    ui->puzzle1->setStyleSheet("Background-color: #3daee9;");

    updatePuzzles(0);
}

StudWin::StudWin(Client *client, QWidget *parent) : StudWin(parent) {
    this->client = client;
}

StudWin::~StudWin() {
    delete ui;

    for (auto it = puzzles.begin(); it < puzzles.end(); it++) {
        delete *it;
    }
}

void StudWin::setupLevels() {
    puzzles.push_back(new StackPuzzle(size()));
    puzzles.push_back(new ArrayPuzzle(size()));
    puzzles.push_back(new ListPuzzle(size()));
    puzzles.push_back(new TreePuzzle(size()));
}

std::vector<bool> StudWin::getSolvedList() {
    std::vector<bool> solvedlist;

    for (auto it = puzzles.begin(); it < puzzles.end(); it++) {
        Puzzle *puzz = *it;
        solvedlist.push_back(puzz->solved());
        return solvedlist;
    }

    //return nullptr;
}

void StudWin::on_hideButton_clicked() {
    if (levelshow) {
        ui->levelFrame->hide();
        levelshow = false;
        ui->hideButton->setText(QString("Show Levels"));
    } else {
        ui->levelFrame->showNormal();
        ui->hideButton->setText(QString("Hide Levels"));
        levelshow = true;
    }
}

//Move to controller?
void StudWin::on_logoutButton_clicked() {
    Client *par = client;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(static_cast<QWidget *>(this), "Really QUIT??", "Quit?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
        UserSocket sock(sf::IpAddress::LocalHost, 11777, par->getSessionId());
        try {
            sock.deauthenticate();
        } catch (authenticationexception ex) {
        }
    } else {
        //recover
    }

    //emit signal to release sources?
}

//void StudWin::on_listWidget_currentRowChanged(int currentRow) {
//    if (currentRow > -1 && currentRow < 4) {
//        pw->setPuzzle(puzzles[currentRow]);
//        pw->setFocus();
//    }
//}

void StudWin::on_checkBox_stateChanged(int arg1) {
    //There may be better way to get directory
    Q_INIT_RESOURCE(sprites);
    QFile musicfile(":rc/music.ogg");
    musicfile.copy(QString("music.ogg"));

    if (arg1 == 0) {
        music.stop();
    } else {
        if (!music.openFromFile("music.ogg")) {
            std::cout << "music broke" << std::endl;
        } else {
            music.setVolume(50);
            music.play();
        }
    }
}

std::vector<bool> StudWin::getUpdatedPuzzles() {
    UserSocket sock(sf::IpAddress::LocalHost, 11777);

    sock.authenticate("user", "pass");
    Message msg = sock.sendPayload("getSolvedPuzzles", "user, pass");
    QVector<QString> completedPuzzles = QString::fromStdString(msg.payload).split(",").toVector();
    return convertStringsToBools(completedPuzzles);
}

std::vector<bool> StudWin::convertStringsToBools(QVector<QString> strBools) {
    std::vector<bool>bools;
    bool tempBool;

    for (int i = 0; i < strBools.length(); i++) {
        std::istringstream is(strBools.at(i).toStdString());
        is >> std::boolalpha >> tempBool;
        bools.push_back(tempBool);//make sure order is right
    }

    return bools;
}
void StudWin::updatePuzzles(int i){
    getUpdatedPuzzles();
    if(i == 0){
        ui->puzzle1->setStyleSheet("Background-color: #3daee9;");
    }

    if(!puzzles.at(1)->getProgress()){
        ui->puzzle2->setDisabled(true);
        ui->puzzle2->setStyleSheet("Background-color: grey;");
    }else if(i == 1){
        ui->puzzle2->setDisabled(false);
        ui->puzzle2->setStyleSheet("Background-color: #3daee9;");
    }else{
        ui->puzzle2->setStyleSheet("Background-color: black");
    }

    if(!puzzles.at(2)->getProgress()){
        ui->puzzle3->setDisabled(true);
        ui->puzzle3->setStyleSheet("Background-color: grey;");
    }else if(i == 2){
        ui->puzzle3->setDisabled(false);
        ui->puzzle3->setStyleSheet("Background-color: #3daee9;");
    }else{
        ui->puzzle3->setStyleSheet("Background-color: black");
    }

    if(!puzzles.at(3)->getProgress()){
        ui->puzzle4->setDisabled(true);
        ui->puzzle4->setStyleSheet("Background-color: grey;");
    }else if(i == 3){
        ui->puzzle4->setDisabled(false);
        ui->puzzle4->setStyleSheet("Background-color: #3daee9;");
    }else{
        ui->puzzle4->setStyleSheet("Background-color: black");
    }


}

void StudWin::setCurrentUsername(QString currentUsername) {
    this->currentUsername = currentUsername;
    ui->userLabel->setText("Welcome: " + this->currentUsername);
}

void StudWin::on_puzzle1_clicked()
{
    pw->setPuzzle(puzzles[0]);
    pw->setFocus();
    updatePuzzles(0);
}

void StudWin::on_puzzle2_clicked()
{
    pw->setPuzzle(puzzles[1]);
    pw->setFocus();
    updatePuzzles(1);
}

void StudWin::on_puzzle3_clicked()
{
    pw->setPuzzle(puzzles[2]);
    pw->setFocus();
    updatePuzzles(2);
}

void StudWin::on_puzzle4_clicked()
{
    pw->setPuzzle(puzzles[3]);
    pw->setFocus();
    updatePuzzles(3);
}
