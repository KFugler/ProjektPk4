#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrDodajStrone = new DodajStrone(this);
    ptrWyszukiwarka = new Wyszukiwarka(this);

    this->setFixedSize(400,300);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrDodajStrone;
    delete ptrWyszukiwarka;

    BazaDanych::ResetInstance();
}

void MainWindow::on_przyciskDodajStrone_clicked()
{
    ptrDodajStrone->Show();
}


void MainWindow::on_przyciskWyszukiwarka_clicked()
{
    ptrWyszukiwarka->show();
}
