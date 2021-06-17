#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    userFilePath = "C:/Users/Ollie/Desktop/ProjektPk4/users.csv";
    UserFile newUserFile(userFilePath);
    newUserFile.readUserFile(newUserList);
}

LoginWindow::~LoginWindow()
{
    UserFile newUserFile(userFilePath);
    newUserFile.writeUserFile(newUserList);
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = newUserList.loginUser(username, password);

    if(user != "unknown"){
        this->hide();
        mainWindow = new MainWindow(nullptr, this, user);
        mainWindow->show();
    }else{
        QMessageBox::warning(this, "Error!", "Invalid username or password!");
    }
}

void LoginWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = newUserList.registerUser(username, password);

    if(user != "invalid"){
        QMessageBox::warning(this, "Success!", "Successfully registered user: " + user);
    }else{
        QMessageBox::warning(this, "Error!", "User already exists!");
    }
}
