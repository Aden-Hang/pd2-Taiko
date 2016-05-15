#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QDialog>

extern int again;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->close();
    again=1;
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    again=2;
}
