#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    userFilePath = "C:/Pk4Qt2/ProjektPk4/users.csv";
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
        QMessageBox::warning(this, "Błąd!", "Nieprawidłowy login lub hasło!");
    }
}

void LoginWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = newUserList.registerUser(username, password);

    if(user != "invalid"){
        QMessageBox::information(this, "Sukces!", "Pomyślnie utworzono konto: " + user);
    }else{
        QMessageBox::warning(this, "Błąd!", "Użytkownik o podanym loginie istnieje!");
    }
}
