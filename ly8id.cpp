#include "ly8id.h"
#include <fstream>

LY8ID::LY8ID(QWidget *parent) : QMainWindow(parent)
{

}
void LY8ID::Open_log_file()
{
    QByteArray data;
    QString filename = QFileDialog::getOpenFileName();
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    file.readAll();
    QDataStream in(&file);

    in >> data;
    qDebug() << data;
    QMessageBox msgBox;
    msgBox.setWindowTitle("SimpleCrypt");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Plik odczytany");
    msgBox.exec();




}
