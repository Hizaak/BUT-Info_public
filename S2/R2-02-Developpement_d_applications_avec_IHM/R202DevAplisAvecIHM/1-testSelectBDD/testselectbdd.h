#ifndef TESTSELECTBDD_H
#define TESTSELECTBDD_H

#include <QMainWindow>
#include <database.h>

QT_BEGIN_NAMESPACE
namespace Ui { class TestSelectBDD; }
QT_END_NAMESPACE

class TestSelectBDD : public QMainWindow
{
    Q_OBJECT

public:
    TestSelectBDD(QWidget *parent = nullptr);
    ~TestSelectBDD();

private:
    Ui::TestSelectBDD *ui;
    Database *db;

private slots:
    void executer();
};
#endif // TESTSELECTBDD_H
