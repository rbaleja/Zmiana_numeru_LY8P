#include "ly8id.h"
#include <fstream>

LY8ID::LY8ID(QWidget *parent) : QMainWindow(parent)
{

}
void LY8ID::Open_log_file()
{


    QMessageBox msgBox;
    QByteArray data;
    //QString filename = QFileDialog::getOpenFileName();
    QFile file(FileNameLog);
    if (!file.exists()) {
            qDebug() << "file doesn't exist";
            msgBox.setWindowTitle("SimpleCrypt");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Plik nie istnieje");
            msgBox.exec();
}
    if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "can't open inFile";
            msgBox.setWindowTitle("SimpleCrypt");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Nie można odczytac pliku");
            msgBox.exec();
}
    file.open(QIODevice::ReadOnly);
    data = file.readAll();
    qDebug() << data;

    Hi = data.at(0);
    Mi = data.at(1);
    Lo = data.at(2);
    ID = 0x10000 * Hi + 0x100 * Mi + Lo;
    qDebug() << Hi;
    qDebug() << Mi;
    qDebug() << Lo;
    //qDebug() << ID;
//    msgBox.setWindowTitle("SimpleCrypt");
//    msgBox.setIcon(QMessageBox::Information);
//    msgBox.setText("Plik odczytany");
//    msgBox.exec();



}

unsigned int &LY8ID::get_ID()
{
    return ID;
}

void LY8ID::Open_elf_File()
{
    QByteArray elf_data;
    QFile file(FileName);
    file.open(QIODevice::ReadOnly);
    elf_data = file.readAll();
    unsigned char elf_Hi = elf_data.at(ID_Lo_Location);
    //unsigned char elf_Mi = elf_data.at(2567);
    //unsigned char elf_Lo = elf_data.at(2568);
    ID = 0x10000 * Hi + 0x100 * Mi + Lo;
    //qDebug() << elf_Hi;
    //qDebug() << elf_Mi;
    //qDebug() << elf_Lo;
    //qDebug() << ID;
}


void LY8ID::Save_log_File()
{
    ++ID;
    i = (ID >> 16) & 0xFF;
    log_Dane[0] = i;
    pc_Dane[ID_Lo + 2] = i;

    i = (ID >> 8) & 0xFF;
    log_Dane[1] = i;
    pc_Dane[ID_Lo + 1] = i;

    i = ID & 0xFF;
    log_Dane[2] = i;
    pc_Dane[ID_Lo] = i;

    qDebug() << ID;

}
