/********************************************************************************
** Form generated from reading UI file 'convetisseurtemp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVETISSEURTEMP_H
#define UI_CONVETISSEURTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvetisseurTemp
{
public:
    QAction *action1;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QMenu *menuEdiions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConvetisseurTemp)
    {
        if (ConvetisseurTemp->objectName().isEmpty())
            ConvetisseurTemp->setObjectName(QString::fromUtf8("ConvetisseurTemp"));
        ConvetisseurTemp->resize(539, 345);
        action1 = new QAction(ConvetisseurTemp);
        action1->setObjectName(QString::fromUtf8("action1"));
        centralwidget = new QWidget(ConvetisseurTemp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ConvetisseurTemp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConvetisseurTemp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 539, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuEdiions = new QMenu(menubar);
        menuEdiions->setObjectName(QString::fromUtf8("menuEdiions"));
        ConvetisseurTemp->setMenuBar(menubar);
        statusbar = new QStatusBar(ConvetisseurTemp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConvetisseurTemp->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());
        menubar->addAction(menuEdiions->menuAction());

        retranslateUi(ConvetisseurTemp);

        QMetaObject::connectSlotsByName(ConvetisseurTemp);
    } // setupUi

    void retranslateUi(QMainWindow *ConvetisseurTemp)
    {
        ConvetisseurTemp->setWindowTitle(QCoreApplication::translate("ConvetisseurTemp", "ConvetisseurTemp", nullptr));
        action1->setText(QCoreApplication::translate("ConvetisseurTemp", "Action1", nullptr));
        label->setText(QCoreApplication::translate("ConvetisseurTemp", "Convertisseur de temp\303\251rature", nullptr));
        label_2->setText(QCoreApplication::translate("ConvetisseurTemp", "Degr\303\251s Celcius", nullptr));
        lineEdit->setText(QCoreApplication::translate("ConvetisseurTemp", "entier entre 0 et 999", nullptr));
        label_3->setText(QCoreApplication::translate("ConvetisseurTemp", "Degr\303\251s Fahrenheit", nullptr));
        label_4->setText(QCoreApplication::translate("ConvetisseurTemp", "--.--", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ConvetisseurTemp", "Convertir", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ConvetisseurTemp", "Effacer", nullptr));
        pushButton->setText(QCoreApplication::translate("ConvetisseurTemp", "Quitter", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("ConvetisseurTemp", "Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("ConvetisseurTemp", "Aide", nullptr));
        menuEdiions->setTitle(QCoreApplication::translate("ConvetisseurTemp", "Edition", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvetisseurTemp: public Ui_ConvetisseurTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVETISSEURTEMP_H
