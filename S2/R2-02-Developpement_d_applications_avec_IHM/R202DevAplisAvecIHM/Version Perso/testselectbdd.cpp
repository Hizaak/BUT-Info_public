
#include "testselectbdd.h"
#include "ui_testselectbdd.h"
#include <QSqlQuery>
#include <QDebug>

TestSelectBDD::TestSelectBDD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestSelectBDD)
{
    ui->setupUi(this);
    db = new Database();
    db->openDataBase();

    QSqlQuery query;

    // exécution de la requête
    query.exec("SELECT * FROM Article;");
    QTableWidgetItem* item;

    //peuplement de la table
    for(int i = 0; query.next(); i++){

        qDebug() << query.value(0) << query.value(1) << query.value(2) << Qt::endl;
        ui->tableWidget->insertRow(i);
        item = new QTableWidgetItem(query.value(0).toString());
        ui->tableWidget->setItem(i,0,item);
        item = new QTableWidgetItem(query.value(1).toString());
        ui->tableWidget->setItem(i,1,item);
        item = new QTableWidgetItem(query.value(2).toString());
        ui->tableWidget->setItem(i,2,item);

    }

}

TestSelectBDD::~TestSelectBDD()
{
    delete ui;
}

