#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    users.addUser("admin", "password");
    users.addUser("user1", "password1");
    users.addUser("user2", "password2");
    users.addUser("", "");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = users.loginUser(username, password);

    if(user != "unknown"){
        this->accept();
    }else{
        QMessageBox::warning(this, "Error!", "Invalid username or password!");
    }
}

void LoginWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = users.registerUser(username, password);

    if(user != "invalid"){
        QMessageBox::warning(this, "Success!", "Successfully registered user: " + user);
    }else{
        QMessageBox::warning(this, "Error!", "User already exists!");
    }
}
