#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( BazaDanych::getInstance()->getDBInstance());
    query.prepare("select * from cpp_strony ");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "!!!!";

    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "Rzedy : " << model->rowCount();
    ui->tableView->show();

    ptrDodajStrone = new DodajStrone(this);
    ptrWyszukiwarka = new Wyszukiwarka(this);
    ptrDostepneStrony = new DostepneStrony(this);

    //this->setFixedSize(400,300);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrDodajStrone;
    delete ptrWyszukiwarka;
    delete ptrDostepneStrony;


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
void MainWindow::on_btnDostepneStrony_clicked()
{
    ptrDostepneStrony->Show();
}

