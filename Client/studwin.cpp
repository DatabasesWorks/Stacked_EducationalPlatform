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
}


StudWin::StudWin(Client *client, QWidget* parent) : StudWin(parent){
     this->client=client;
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
    puzzles.push_back(new TreePuzzle(size()));
    puzzles.push_back(new ListPuzzle(size()));
    ui->listWidget->addItem("stack");
    ui->listWidget->addItem("array");
    ui->listWidget->addItem("tree");
    ui->listWidget->addItem("list");
}

std::vector<bool> StudWin::getSolvedList(){
    std::vector<bool> solvedlist;
    for(auto it = puzzles.begin(); it < puzzles.end(); it++){
        Puzzle * puzz = *it;
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
    reply = QMessageBox::question(static_cast<QWidget*>(this), "Really QUIT??","Quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
        UserSocket sock(sf::IpAddress::LocalHost, 11777,par->getSessionId());
        try{
            sock.deauthenticate();
        }catch(authenticationexception ex){

        }
    } else {

      //recover
    }
    //emit signal to release sources?
}

void StudWin::on_listWidget_currentRowChanged(int currentRow) {
    if (currentRow > -1 && currentRow < 4) {
        pw->setPuzzle(puzzles[currentRow]);
        pw->setFocus();
    }
}

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

std::vector<bool> StudWin::getUpdatedPuzzles(){
    UserSocket sock(sf::IpAddress::LocalHost, 11777);
    sock.authenticate("", "");
    Message msg = sock.sendPayload("getSolvedPuzzles", "");
    QVector<QString> completedPuzzles = QString::fromStdString(msg.payload).split(",").toVector();
    return convertStringsToBools(completedPuzzles);

}

std::vector<bool> StudWin::convertStringsToBools(QVector<QString> strBools){
    std::vector<bool>bools;
    bool tempBool;
    for(int i = 0; i < strBools.length(); i++){
        std::istringstream is(strBools.at(i).toStdString());
        is>>std::boolalpha >> tempBool;
        bools.push_back(tempBool);//make sure order is right
    }
    return bools;
}

void StudWin::setCurrentUsername(QString currentUsername) {
    this->currentUsername = currentUsername;
    ui->userLabel->setText("Welcome: " + this->currentUsername);
}
