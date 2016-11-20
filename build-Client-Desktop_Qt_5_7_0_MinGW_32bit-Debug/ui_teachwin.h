/********************************************************************************
** Form generated from reading UI file 'teachwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHWIN_H
#define UI_TEACHWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeachWin
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFrame *studentFrame;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QWidget *playWidget;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QFrame *frame1;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QLabel *userLabel;
    QLabel *classLabel;
    QPushButton *logoutButton;
    QWidget *teachDataWidget;

    void setupUi(QWidget *TeachWin)
    {
        if (TeachWin->objectName().isEmpty())
            TeachWin->setObjectName(QStringLiteral("TeachWin"));
        TeachWin->resize(640, 480);
        gridLayout_2 = new QGridLayout(TeachWin);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        studentFrame = new QFrame(TeachWin);
        studentFrame->setObjectName(QStringLiteral("studentFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(studentFrame->sizePolicy().hasHeightForWidth());
        studentFrame->setSizePolicy(sizePolicy);
        studentFrame->setMinimumSize(QSize(150, 450));
        gridLayout_3 = new QGridLayout(studentFrame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(studentFrame);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignTop);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(studentFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(150, 10000));

        gridLayout_6->addWidget(listWidget, 0, 0, 1, 1);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout->addWidget(studentFrame, 0, 0, 1, 1);

        playWidget = new QWidget(TeachWin);
        playWidget->setObjectName(QStringLiteral("playWidget"));
        gridLayout_9 = new QGridLayout(playWidget);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        frame1 = new QFrame(playWidget);
        frame1->setObjectName(QStringLiteral("frame1"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy3);
        frame1->setMinimumSize(QSize(0, 25));
        frame1->setFrameShape(QFrame::Box);
        gridLayout_11 = new QGridLayout(frame1);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(1, 1, 1, 1);
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        userLabel = new QLabel(frame1);
        userLabel->setObjectName(QStringLiteral("userLabel"));

        gridLayout_10->addWidget(userLabel, 0, 0, 1, 1);

        classLabel = new QLabel(frame1);
        classLabel->setObjectName(QStringLiteral("classLabel"));

        gridLayout_10->addWidget(classLabel, 0, 1, 1, 1);

        logoutButton = new QPushButton(frame1);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        gridLayout_10->addWidget(logoutButton, 0, 2, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame1, 0, 0, 1, 1);

        teachDataWidget = new QWidget(playWidget);
        teachDataWidget->setObjectName(QStringLiteral("teachDataWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(teachDataWidget->sizePolicy().hasHeightForWidth());
        teachDataWidget->setSizePolicy(sizePolicy4);
        teachDataWidget->setMinimumSize(QSize(150, 150));

        gridLayout_8->addWidget(teachDataWidget, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);


        gridLayout->addWidget(playWidget, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(TeachWin);

        QMetaObject::connectSlotsByName(TeachWin);
    } // setupUi

    void retranslateUi(QWidget *TeachWin)
    {
        TeachWin->setWindowTitle(QApplication::translate("TeachWin", "Form", 0));
        label->setText(QApplication::translate("TeachWin", "STUDENTS", 0));
        pushButton->setText(QApplication::translate("TeachWin", "Delete Student", 0));
        userLabel->setText(QApplication::translate("TeachWin", "Welcome: TeacherName", 0));
        classLabel->setText(QApplication::translate("TeachWin", "ClassCodeHere", 0));
        logoutButton->setText(QApplication::translate("TeachWin", "Log Out", 0));
    } // retranslateUi

};

namespace Ui {
    class TeachWin: public Ui_TeachWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHWIN_H
