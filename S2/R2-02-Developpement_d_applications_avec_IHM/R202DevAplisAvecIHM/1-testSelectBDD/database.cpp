#include "database.h"
#include <QDebug>
#include <QSqlQuery>

Database::Database()
{

}

bool Database::openDataBase() {
 mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
 mydb.setDatabaseName(DATABASE_NAME);

 return mydb.open();
}

void Database::closeDataBase() {
    mydb.close();
}

bool Database::restoreDataBase() {
    qDebug () << "bd inexistante";
    return true;
}

bool Database::insertVilles()
{
    QSqlQuery query;
    if (!query.exec("insert into Villes values('64000', 'Pau', 70000);"))
    return false;
    QString insertions="insert into Villes values(?, ?, ?);";
    query.prepare(insertions);
    QVariantList codesPostaux;
    codesPostaux << "33000" << "32000" ;
    query.addBindValue(codesPostaux);
    QVariantList nomsVilles;
    nomsVilles << "Bordeaux" << "Auch";
    query.addBindValue(nomsVilles);
    QVariantList nbHabitants;
    nbHabitants << 300000 << 25000;
    query.addBindValue(nbHabitants);
    if (!query.execBatch())
    return false;
    return true;
}
