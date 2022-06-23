/********************************************************************************
** Form generated from reading UI file 'principale.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPALE_H
#define UI_PRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Principale
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Principale)
    {
        if (Principale->objectName().isEmpty())
            Principale->setObjectName(QString::fromUtf8("Principale"));
        Principale->resize(800, 600);
        centralwidget = new QWidget(Principale);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Principale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principale);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Principale->setMenuBar(menubar);
        statusbar = new QStatusBar(Principale);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Principale->setStatusBar(statusbar);

        retranslateUi(Principale);

        QMetaObject::connectSlotsByName(Principale);
    } // setupUi

    void retranslateUi(QMainWindow *Principale)
    {
        Principale->setWindowTitle(QCoreApplication::translate("Principale", "Principale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Principale: public Ui_Principale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPALE_H
