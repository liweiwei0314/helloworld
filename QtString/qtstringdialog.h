#ifndef QTSTRINGDIALOG_H
#define QTSTRINGDIALOG_H

#include <QDialog>

namespace Ui {
class QtStringDialog;
}

class QtStringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QtStringDialog(QWidget *parent = 0);
    ~QtStringDialog();
private slots:
    void Inverted();
private:
    Ui::QtStringDialog *ui;
};

#endif // QTSTRINGDIALOG_H
