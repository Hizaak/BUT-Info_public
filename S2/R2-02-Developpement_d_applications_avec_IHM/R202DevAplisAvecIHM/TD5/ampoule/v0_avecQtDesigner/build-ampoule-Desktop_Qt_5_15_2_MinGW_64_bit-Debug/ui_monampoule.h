/********************************************************************************
** Form generated from reading UI file 'monampoule.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONAMPOULE_H
#define UI_MONAMPOULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monAmpoule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelEtat;
    QHBoxLayout *horizontalLayout;
    QPushButton *bAllumer;
    QPushButton *bEteindre;

    void setupUi(QWidget *monAmpoule)
    {
        if (monAmpoule->objectName().isEmpty())
            monAmpoule->setObjectName(QString::fromUtf8("monAmpoule"));
        monAmpoule->resize(193, 106);
        monAmpoule->setMinimumSize(QSize(193, 0));
        monAmpoule->setMaximumSize(QSize(16777215, 106));
        verticalLayout = new QVBoxLayout(monAmpoule);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelEtat = new QLabel(monAmpoule);
        labelEtat->setObjectName(QString::fromUtf8("labelEtat"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelEtat->sizePolicy().hasHeightForWidth());
        labelEtat->setSizePolicy(sizePolicy);
        labelEtat->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelEtat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bAllumer = new QPushButton(monAmpoule);
        bAllumer->setObjectName(QString::fromUtf8("bAllumer"));

        horizontalLayout->addWidget(bAllumer);

        bEteindre = new QPushButton(monAmpoule);
        bEteindre->setObjectName(QString::fromUtf8("bEteindre"));

        horizontalLayout->addWidget(bEteindre);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(monAmpoule);

        QMetaObject::connectSlotsByName(monAmpoule);
    } // setupUi

    void retranslateUi(QWidget *monAmpoule)
    {
        monAmpoule->setWindowTitle(QCoreApplication::translate("monAmpoule", "Ampoule", nullptr));
        labelEtat->setText(QCoreApplication::translate("monAmpoule", "---------", nullptr));
        bAllumer->setText(QCoreApplication::translate("monAmpoule", "Allumer", nullptr));
        bEteindre->setText(QCoreApplication::translate("monAmpoule", "Eteindre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monAmpoule: public Ui_monAmpoule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONAMPOULE_H
