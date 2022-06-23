/********************************************************************************
** Form generated from reading UI file 'dialise2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALISE2_H
#define UI_DIALISE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialise2
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *nbEnfants;
    QPushButton *okDialise2;
    QPushButton *annulerDialise2;

    void setupUi(QDialog *dialise2)
    {
        if (dialise2->objectName().isEmpty())
            dialise2->setObjectName(QString::fromUtf8("dialise2"));
        dialise2->resize(173, 115);
        verticalLayout = new QVBoxLayout(dialise2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(dialise2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        nbEnfants = new QSpinBox(dialise2);
        nbEnfants->setObjectName(QString::fromUtf8("nbEnfants"));

        verticalLayout->addWidget(nbEnfants);

        okDialise2 = new QPushButton(dialise2);
        okDialise2->setObjectName(QString::fromUtf8("okDialise2"));

        verticalLayout->addWidget(okDialise2);

        annulerDialise2 = new QPushButton(dialise2);
        annulerDialise2->setObjectName(QString::fromUtf8("annulerDialise2"));

        verticalLayout->addWidget(annulerDialise2);


        retranslateUi(dialise2);

        QMetaObject::connectSlotsByName(dialise2);
    } // setupUi

    void retranslateUi(QDialog *dialise2)
    {
        dialise2->setWindowTitle(QCoreApplication::translate("dialise2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("dialise2", "Combiens d'enfants avez-vous ?", nullptr));
        okDialise2->setText(QCoreApplication::translate("dialise2", "OK", nullptr));
        annulerDialise2->setText(QCoreApplication::translate("dialise2", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialise2: public Ui_dialise2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALISE2_H
