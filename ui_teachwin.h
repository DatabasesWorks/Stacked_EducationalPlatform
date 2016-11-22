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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeachWin
{
public:

    void setupUi(QWidget *TeachWin)
    {
        if (TeachWin->objectName().isEmpty())
            TeachWin->setObjectName(QStringLiteral("TeachWin"));
        TeachWin->resize(640, 480);

        retranslateUi(TeachWin);

        QMetaObject::connectSlotsByName(TeachWin);
    } // setupUi

    void retranslateUi(QWidget *TeachWin)
    {
        TeachWin->setWindowTitle(QApplication::translate("TeachWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class TeachWin: public Ui_TeachWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHWIN_H
