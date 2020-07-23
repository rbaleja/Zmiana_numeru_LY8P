#ifndef LY8P_ID_H
#define LY8P_ID_H

#include <QMainWindow>

class LY8P_ID : public QMainWindow
{
    Q_OBJECT
public:
    explicit L8P_ID(QWidget *parent = nullptr);

    void Open_log_file();
    void Open_elf_File();
    void Set_ID_man(unsigned int&);
    void Save_log_File();
    void Save_elf_File();



private:
    QString FileName = "LY8P_v001_ELF.elf";
    QString FileNameNew = "LY8P_v001_ELF_new.elf";
    QString FileNameLog = "LY8P_ID.log";
    unsigned int  ID_Lo_Location = 2566 ;

    char *pc_Dane;
    char *log_Dane;
    int i_DlugoscPliku;
    int i_DlugoscPliku_log;
    unsigned char Lo, Mi, Hi;               // od 0 do 255
    unsigned short i, ID_Lo, Lp;            // od 0 do 65'535
    unsigned int ID;                        // od 0 do 4'294'967'295  zakres IP: 0 - 16 777 215 (3 bajty)
    char znak;


signals:

};

#endif // LY8P_ID_H
