/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *userlabel;
    QLabel *passlabel;
    QLineEdit *userEntry;
    QLineEdit *passEntry;
    QPushButton *loginButton;
    QPushButton *regStud;
    QPushButton *regTeach;

    void setupUi(QWidget *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(640, 480);
        gridLayout_2 = new QGridLayout(LoginWin);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(LoginWin);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(200, 250));
        frame->setFrameShape(QFrame::Box);
        userlabel = new QLabel(frame);
        userlabel->setObjectName(QStringLiteral("userlabel"));
        userlabel->setGeometry(QRect(10, 10, 81, 31));
        passlabel = new QLabel(frame);
        passlabel->setObjectName(QStringLiteral("passlabel"));
        passlabel->setGeometry(QRect(10, 60, 81, 31));
        userEntry = new QLineEdit(frame);
        userEntry->setObjectName(QStringLiteral("userEntry"));
        userEntry->setGeometry(QRect(10, 40, 171, 21));
        passEntry = new QLineEdit(frame);
        passEntry->setObjectName(QStringLiteral("passEntry"));
        passEntry->setGeometry(QRect(10, 90, 171, 21));
        loginButton = new QPushButton(frame);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(13, 120, 171, 51));
        regStud = new QPushButton(frame);
        regStud->setObjectName(QStringLiteral("regStud"));
        regStud->setGeometry(QRect(3, 177, 191, 32));
        regTeach = new QPushButton(frame);
        regTeach->setObjectName(QStringLiteral("regTeach"));
        regTeach->setGeometry(QRect(3, 210, 191, 32));

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QWidget *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "Form", 0));
        userlabel->setText(QApplication::translate("LoginWin", "Username", 0));
        passlabel->setText(QApplication::translate("LoginWin", "Password", 0));
        loginButton->setText(QApplication::translate("LoginWin", "Login", 0));
        regStud->setText(QApplication::translate("LoginWin", "Register Student", 0));
        regTeach->setText(QApplication::translate("LoginWin", "Register Teacher", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
