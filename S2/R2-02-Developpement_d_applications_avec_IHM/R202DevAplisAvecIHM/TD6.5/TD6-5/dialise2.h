#ifndef DIALISE2_H
#define DIALISE2_H

#include <QDialog>

namespace Ui {
class dialise2;
}

class dialise2 : public QDialog
{
    Q_OBJECT

public:
    explicit dialise2(QWidget *parent = nullptr);
    ~dialise2();

private:
    Ui::dialise2 *ui;
};

#endif // DIALISE2_H
