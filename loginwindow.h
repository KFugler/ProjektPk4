#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "userlist.h"
#include "userfile.h"
#include "mainwindow.h"

namespace Ui {class LoginWindow;}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::LoginWindow *ui;
    UserList *newUserList;
    MainWindow *mainWindow;
    QString path = "C:/Pk4Qt3/ProjektPk4/users.csv";
    UserFile *file;
};

#endif // LOGINWINDOW_H
