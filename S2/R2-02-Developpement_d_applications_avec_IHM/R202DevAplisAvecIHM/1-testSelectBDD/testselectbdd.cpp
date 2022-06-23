#include "testselectbdd.h"
#include "ui_testselectbdd.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

TestSelectBDD::TestSelectBDD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestSelectBDD)
{
    ui->setupUi(this);
    db = new Database();
    db->openDataBase();

    ui->lineEdit->setText("SELECT * FROM Article");

    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(executer()));
}

TestSelectBDD::~TestSelectBDD()
{
    delete ui;
}

void TestSelectBDD::executer() {
    QSqlQuery query;
    query.exec(ui->lineEdit->text());

    QSqlRecord rec = query.record();

    for(int i = rec.count(); i > 0; i--){
        ui->tableWidget->insertColumn( 0 );
        ui->tableWidget->setHorizontalHeaderLabels(QStringList(rec.fieldName(i)));
    }

    ui->tableWidget->setColumnCount(rec.count());
    ui->tableWidget->setRowCount(0);


    QTableWidgetItem * item;

    for(int i = 0; query.next(); i++){

        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );

        for(int v = 0; v < rec.count(); v++){
            item = new QTableWidgetItem();
            item->setText( query.value(v).toString() );
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, v, item);
        }

    }

}
