#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ly8id.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    LY8ID ID;
    unsigned int id;
    ID.Open_log_file();
    id = ID.get_ID();

    QString s = QString::number(id);

    ui->lcdNumber->display(s);


}



void MainWindow::on_pushButton_2_clicked()
{
    LY8ID ID;
    ID.Open_elf_File();
}

void MainWindow::on_pushButton_3_clicked()
{

    LY8ID ID;
    ID.Save_log_File();
    unsigned int id;
    ID.Open_log_file();
    id = ID.get_ID();

    QString s = QString::number(id);
    qDebug() << id;

    ui->lcdNumber->display(s);
}

