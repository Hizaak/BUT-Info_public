#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->PBconnexion,SIGNAL(clicked()),this,SLOT(demanderConnexion()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demandeConnexion()
{
    QString utilisateur = ui->SELuser->text();
    QString mdP = ui->SELmdp->text();
    if ((utilisateur == "moi") && (mdP == "moi"))
    {
    QMessageBox::information(this, "Connexion", "Connexion réussie");
    QDialog maDlg(nullptr);
    maDlg.show(); // ou maDlg.exec();
    }
    else
    {
    QMessageBox::information(this, "Connexion", "Connexion erronée");
    }
}
