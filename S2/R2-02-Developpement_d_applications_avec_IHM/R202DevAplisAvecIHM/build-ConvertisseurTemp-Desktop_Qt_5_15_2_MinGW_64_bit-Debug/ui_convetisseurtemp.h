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
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *LCelcius;
    QLineEdit *SELinput;
    QVBoxLayout *verticalLayout_3;
    QLabel *LFahrenheit;
    QLabel *LResultat;
    QHBoxLayout *horizontalLayout_8;
    QLabel *L_999;
    QSlider *STemperature;
    QLabel *L999;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *PBConvertir;
    QPushButton *PBRazeRo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PBQuitter;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QMenu *menuEdiions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConvetisseurTemp)
    {
        if (ConvetisseurTemp->objectName().isEmpty())
            ConvetisseurTemp->setObjectName(QString::fromUtf8("ConvetisseurTemp"));
        ConvetisseurTemp->resize(766, 565);
        action1 = new QAction(ConvetisseurTemp);
        action1->setObjectName(QString::fromUtf8("action1"));
        centralwidget = new QWidget(ConvetisseurTemp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setMouseTracking(true);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LCelcius = new QLabel(centralwidget);
        LCelcius->setObjectName(QString::fromUtf8("LCelcius"));
        LCelcius->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(LCelcius);

        SELinput = new QLineEdit(centralwidget);
        SELinput->setObjectName(QString::fromUtf8("SELinput"));

        verticalLayout_2->addWidget(SELinput);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LFahrenheit = new QLabel(centralwidget);
        LFahrenheit->setObjectName(QString::fromUtf8("LFahrenheit"));
        LFahrenheit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(LFahrenheit);

        LResultat = new QLabel(centralwidget);
        LResultat->setObjectName(QString::fromUtf8("LResultat"));

        verticalLayout_3->addWidget(LResultat);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, -1, -1);
        L_999 = new QLabel(centralwidget);
        L_999->setObjectName(QString::fromUtf8("L_999"));

        horizontalLayout_8->addWidget(L_999);

        STemperature = new QSlider(centralwidget);
        STemperature->setObjectName(QString::fromUtf8("STemperature"));
        STemperature->setMinimum(-999);
        STemperature->setMaximum(999);
        STemperature->setOrientation(Qt::Horizontal);
        STemperature->setInvertedAppearance(false);
        STemperature->setInvertedControls(false);
        STemperature->setTickPosition(QSlider::TicksBelow);
        STemperature->setTickInterval(50);

        horizontalLayout_8->addWidget(STemperature);

        L999 = new QLabel(centralwidget);
        L999->setObjectName(QString::fromUtf8("L999"));

        horizontalLayout_8->addWidget(L999);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        PBConvertir = new QPushButton(centralwidget);
        PBConvertir->setObjectName(QString::fromUtf8("PBConvertir"));

        horizontalLayout_6->addWidget(PBConvertir);

        PBRazeRo = new QPushButton(centralwidget);
        PBRazeRo->setObjectName(QString::fromUtf8("PBRazeRo"));

        horizontalLayout_6->addWidget(PBRazeRo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        PBQuitter = new QPushButton(centralwidget);
        PBQuitter->setObjectName(QString::fromUtf8("PBQuitter"));

        horizontalLayout_6->addWidget(PBQuitter);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        ConvetisseurTemp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConvetisseurTemp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 766, 21));
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
        LCelcius->setText(QCoreApplication::translate("ConvetisseurTemp", "Degr\303\251s Celcius", nullptr));
        LFahrenheit->setText(QCoreApplication::translate("ConvetisseurTemp", "Degr\303\251s Fahrenheit", nullptr));
        LResultat->setText(QCoreApplication::translate("ConvetisseurTemp", "--.--", nullptr));
        L_999->setText(QCoreApplication::translate("ConvetisseurTemp", "-999", nullptr));
        L999->setText(QCoreApplication::translate("ConvetisseurTemp", "999", nullptr));
        PBConvertir->setText(QCoreApplication::translate("ConvetisseurTemp", "Convertir", nullptr));
        PBRazeRo->setText(QCoreApplication::translate("ConvetisseurTemp", "RaZ\303\251ro", nullptr));
        PBQuitter->setText(QCoreApplication::translate("ConvetisseurTemp", "Quitter", nullptr));
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
