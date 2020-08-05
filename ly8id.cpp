#include "ly8id.h"
#include <fstream>

LY8ID::LY8ID(QWidget *parent) : QMainWindow(parent)
{

}
void LY8ID::Open_log_file()
{
    QMessageBox msgBox;
    //QByteArray data;

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
    i_DlugoscPliku_log = file.size();

    log_Dane = file.readAll();
    qDebug() << log_Dane;

    Hi = log_Dane.at(0);
    Mi = log_Dane.at(1);
    Lo = log_Dane.at(2);
    ID = 0x10000 * Hi + 0x100 * Mi + Lo;
    qDebug() << Hi;
    qDebug() << Mi;
    qDebug() << Lo;
    qDebug() << ID;
    file.close();


}



unsigned int &LY8ID::get_ID()
{
    return ID;
}




void LY8ID::Open_elf_File()
{
    QMessageBox msgBox;
    QFile file(FileName);
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
    i_DlugoscPliku = file.size();
    pc_Dane = file.readAll();
    unsigned char elf_Hi = pc_Dane.at(2566);
    unsigned char elf_Mi = pc_Dane.at(2567);
    unsigned char elf_Lo = pc_Dane.at(2568);

    qDebug() << elf_Hi;
    qDebug() << elf_Mi;
    qDebug() << elf_Lo;

//   for (int  i= 0 ; i < i_DlugoscPliku; i++)
//   {
//       qDebug() << pc_Dane;
//   }
}


void LY8ID::Save_log_File()
{

    QMessageBox msgBox;
    //QByteArray data;

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
    i_DlugoscPliku_log = file.size();

    log_Dane = file.readAll();
    qDebug() << log_Dane;

    Hi = log_Dane.at(0);
    Mi = log_Dane.at(1);
    Lo = log_Dane.at(2);
    ID = 0x10000 * Hi + 0x100 * Mi + Lo;
    qDebug() << Hi;
    qDebug() << Mi;
    qDebug() << Lo;
    //qDebug() << ID;
    file.close();


    QFile file3(FileName);
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
    file3.open(QIODevice::ReadOnly);
    i_DlugoscPliku = file.size();
    pc_Dane = file3.readAll();
    unsigned char elf_Hi = pc_Dane.at(2566);
    unsigned char elf_Mi = pc_Dane.at(2567);
    unsigned char elf_Lo = pc_Dane.at(2568);

    qDebug() << elf_Hi;
    qDebug() << elf_Mi;
    qDebug() << elf_Lo;


    ID++;
    ID_Lo = ID_Lo_Location;
    i = (ID >> 16) & 0xFF;
            log_Dane[0] = i;
            pc_Dane[ID_Lo + 2] = i;
    i = (ID >> 8) & 0xFF;
            log_Dane[1] = i;
            pc_Dane[ID_Lo + 1] = i;
    i = ID & 0xFF;
            log_Dane[2] = i;
            pc_Dane[ID_Lo] = i;
    QFile file1(FileNameLog);
    file1.open(QIODevice::WriteOnly);
    file1.write(log_Dane);
    file.close();

    QFile file2(FileName);
    file2.open(QIODevice::WriteOnly);
    file2.write(pc_Dane);
    file2.close();
    qDebug() << log_Dane;
    //qDebug() << ID;
    qDebug() << pc_Dane;





}
