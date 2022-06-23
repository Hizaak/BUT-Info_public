/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *Utilisateur;
    QLineEdit *SELuser;
    QHBoxLayout *horizontalLayout_3;
    QLabel *MDP;
    QLineEdit *SELmdp;
    QPushButton *PBconnexion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(342, 159);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Utilisateur = new QLabel(centralwidget);
        Utilisateur->setObjectName(QString::fromUtf8("Utilisateur"));

        horizontalLayout->addWidget(Utilisateur);

        SELuser = new QLineEdit(centralwidget);
        SELuser->setObjectName(QString::fromUtf8("SELuser"));

        horizontalLayout->addWidget(SELuser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        MDP = new QLabel(centralwidget);
        MDP->setObjectName(QString::fromUtf8("MDP"));

        horizontalLayout_3->addWidget(MDP);

        SELmdp = new QLineEdit(centralwidget);
        SELmdp->setObjectName(QString::fromUtf8("SELmdp"));
        SELmdp->setEnabled(true);
        QFont font;
        font.setStrikeOut(false);
        SELmdp->setFont(font);
        SELmdp->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(SELmdp);


        verticalLayout->addLayout(horizontalLayout_3);

        PBconnexion = new QPushButton(centralwidget);
        PBconnexion->setObjectName(QString::fromUtf8("PBconnexion"));

        verticalLayout->addWidget(PBconnexion);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 342, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        Utilisateur->setText(QCoreApplication::translate("MainWindow", "Utilisateur :", nullptr));
        MDP->setText(QCoreApplication::translate("MainWindow", "Mort de passe :", nullptr));
        PBconnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
