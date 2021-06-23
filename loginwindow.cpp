#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    file = new UserFile(path);
    newUserList = new UserList();

    file->readUserFile(newUserList);
}

LoginWindow::~LoginWindow()
{
    file->writeUserFile(newUserList);

    file = nullptr;
    newUserList = nullptr;
    delete newUserList;
    delete file;
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = newUserList->loginUser(username, password);

    if (user != "unknown") {
        this->hide();
        mainWindow = new MainWindow(nullptr, this, user);
        mainWindow->show();
    } else {
        QMessageBox::warning(this, "Błąd!", "Nieprawidłowy login lub hasło!");
    }
}

void LoginWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString user = newUserList->registerUser(username, password);

    if (user != "invalid") {
        QMessageBox::information(this, "Sukces!", "Pomyślnie utworzono konto: " + user);
    } else {
        QMessageBox::warning(this, "Błąd!", "Użytkownik o podanym loginie istnieje!");
    }
}
