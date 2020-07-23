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
    ID.Open_log_file();
}
