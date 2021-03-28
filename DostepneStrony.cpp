#include "DostepneStrony.h"
#include "ui_DostepneStrony.h"

DostepneStrony::DostepneStrony(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DostepneStrony)
{
    ui->setupUi(this);
}

DostepneStrony::~DostepneStrony()
{
    delete ui;
}

void DostepneStrony::Show()
{
    updateUI();
    show();
}

void DostepneStrony::updateUI()
{
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

}
