/********************************************************************************
** Form generated from reading UI file 'studreg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDREG_H
#define UI_STUDREG_H

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

class Ui_StudReg
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *userLabel;
    QLabel *passLabel;
    QLabel *classLabel;
    QLineEdit *userEntry;
    QLineEdit *passEntry;
    QLineEdit *classEntry;
    QPushButton *regButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *StudReg)
    {
        if (StudReg->objectName().isEmpty())
            StudReg->setObjectName(QStringLiteral("StudReg"));
        StudReg->resize(640, 480);
        gridLayout_2 = new QGridLayout(StudReg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(StudReg);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(200, 210));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Box);
        userLabel = new QLabel(frame);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(10, 10, 131, 21));
        passLabel = new QLabel(frame);
        passLabel->setObjectName(QStringLiteral("passLabel"));
        passLabel->setGeometry(QRect(10, 50, 131, 21));
        classLabel = new QLabel(frame);
        classLabel->setObjectName(QStringLiteral("classLabel"));
        classLabel->setGeometry(QRect(10, 90, 151, 16));
        userEntry = new QLineEdit(frame);
        userEntry->setObjectName(QStringLiteral("userEntry"));
        userEntry->setGeometry(QRect(10, 30, 171, 21));
        passEntry = new QLineEdit(frame);
        passEntry->setObjectName(QStringLiteral("passEntry"));
        passEntry->setGeometry(QRect(10, 70, 171, 21));
        classEntry = new QLineEdit(frame);
        classEntry->setObjectName(QStringLiteral("classEntry"));
        classEntry->setGeometry(QRect(10, 110, 171, 21));
        regButton = new QPushButton(frame);
        regButton->setObjectName(QStringLiteral("regButton"));
        regButton->setGeometry(QRect(10, 137, 171, 32));
        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(10, 170, 171, 32));

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(StudReg);

        QMetaObject::connectSlotsByName(StudReg);
    } // setupUi

    void retranslateUi(QWidget *StudReg)
    {
        StudReg->setWindowTitle(QApplication::translate("StudReg", "Form", 0));
        userLabel->setText(QApplication::translate("StudReg", "Choose Username", 0));
        passLabel->setText(QApplication::translate("StudReg", "Create Password", 0));
        classLabel->setText(QApplication::translate("StudReg", "Class Code (optional)", 0));
        regButton->setText(QApplication::translate("StudReg", "Register", 0));
        cancelButton->setText(QApplication::translate("StudReg", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class StudReg: public Ui_StudReg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDREG_H
