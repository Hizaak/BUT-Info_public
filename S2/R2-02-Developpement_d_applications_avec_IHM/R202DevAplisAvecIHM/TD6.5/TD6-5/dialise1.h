#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class dialise1;
}

class dialise1 : public QDialog
{
    Q_OBJECT

public:
    explicit dialise1(QWidget *parent = nullptr);
    ~dialise1();

private:
    Ui::dialise1 *ui;
};

#endif // DIALOG_H
