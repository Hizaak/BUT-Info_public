#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>

#define DATABASE_NAME "data"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    bool restoreDataBase();
    bool insertVilles();
    void closeDataBase();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
