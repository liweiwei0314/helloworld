#include "qtstringdialog.h"
#include "ui_qtstringdialog.h"


QtStringDialog::QtStringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtStringDialog)
{
    ui->setupUi(this);
    connect(ui->m_button,SIGNAL(clicked()),this,SLOT(Inverted()));

}

QtStringDialog::~QtStringDialog()
{
    delete ui;
}
void QtStringDialog::Inverted()
{
    QString str = ui->m_editX->text();
    int n = str.size();
    QString str1 ;
    int j=0;
    for(int i=n-1;i>=0;i--){
        str1[j]=str[i];
        j++;
    }
    ui->m_editY->setText(str1);

}
