/********************************************************************************
** Form generated from reading UI file 'testselectbdd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSELECTBDD_H
#define UI_TESTSELECTBDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestSelectBDD
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestSelectBDD)
    {
        if (TestSelectBDD->objectName().isEmpty())
            TestSelectBDD->setObjectName(QString::fromUtf8("TestSelectBDD"));
        TestSelectBDD->resize(800, 600);
        centralwidget = new QWidget(TestSelectBDD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);

        verticalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        TestSelectBDD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestSelectBDD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TestSelectBDD->setMenuBar(menubar);
        statusbar = new QStatusBar(TestSelectBDD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TestSelectBDD->setStatusBar(statusbar);

        retranslateUi(TestSelectBDD);

        QMetaObject::connectSlotsByName(TestSelectBDD);
    } // setupUi

    void retranslateUi(QMainWindow *TestSelectBDD)
    {
        TestSelectBDD->setWindowTitle(QCoreApplication::translate("TestSelectBDD", "TestSelectBDD", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TestSelectBDD", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TestSelectBDD", "Colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TestSelectBDD", "Colonne2", nullptr));
        pushButton->setText(QCoreApplication::translate("TestSelectBDD", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestSelectBDD: public Ui_TestSelectBDD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSELECTBDD_H
