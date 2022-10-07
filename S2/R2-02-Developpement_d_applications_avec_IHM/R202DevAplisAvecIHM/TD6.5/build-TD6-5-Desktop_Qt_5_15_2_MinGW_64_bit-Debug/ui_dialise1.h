/********************************************************************************
** Form generated from reading UI file 'dialise1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALISE1_H
#define UI_DIALISE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QCheckBox *estMajeur;
    QLineEdit *SELnom;
    QLabel *label;
    QPushButton *okDialise1;
    QLabel *label_2;
    QLineEdit *SELprenom;
    QPushButton *annulerDialise1;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(253, 116);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        estMajeur = new QCheckBox(Dialog);
        estMajeur->setObjectName(QString::fromUtf8("estMajeur"));

        gridLayout->addWidget(estMajeur, 2, 1, 1, 1);

        SELnom = new QLineEdit(Dialog);
        SELnom->setObjectName(QString::fromUtf8("SELnom"));

        gridLayout->addWidget(SELnom, 0, 1, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        okDialise1 = new QPushButton(Dialog);
        okDialise1->setObjectName(QString::fromUtf8("okDialise1"));

        gridLayout->addWidget(okDialise1, 3, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        SELprenom = new QLineEdit(Dialog);
        SELprenom->setObjectName(QString::fromUtf8("SELprenom"));

        gridLayout->addWidget(SELprenom, 1, 1, 1, 1);

        annulerDialise1 = new QPushButton(Dialog);
        annulerDialise1->setObjectName(QString::fromUtf8("annulerDialise1"));

        gridLayout->addWidget(annulerDialise1, 3, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        estMajeur->setText(QCoreApplication::translate("Dialog", "Avez-vous plus de 18 ans ?", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Nom", nullptr));
        okDialise1->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Pr\303\251nom", nullptr));
        annulerDialise1->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALISE1_H
