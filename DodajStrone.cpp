#include "DodajStrone.h"
#include "ui_DodajStrone.h"

DodajStrone::DodajStrone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajStrone)
{
    ui->setupUi(this);
}

DodajStrone::~DodajStrone()
{
    delete ui;
}

void DodajStrone::Show()
{
    this->show();
}

void DodajStrone::on_przyciskDodaj_clicked()
{
    ui->info->setText("");
    QString sName = ui->txtName->text();
    QString sHTTP = ui->txtHTTP->text();
    //QString sTag = ui->txtTag->text();

    QSqlQuery query(BazaDanych::getInstance()->getDBInstance());
    query.clear();
    query.prepare("INSERT INTO cpp_strony(Nazwa, HTTP) VALUES ('" +sName +"','" +sHTTP + "')");
  //  query.addBindValue(sName);

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->info->setText("Nie można dodac strony!");
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {
            qDebug() <<"read was successful "<< query.lastQuery();
            ui->info->setText("Strona dodana!");
            resetElements();
        }
        else
            qDebug() <<"Nie mozna dodac nowej strony!";
     }

}

void DodajStrone::resetElements()
{
    ui->txtName->clear();
    ui->txtHTTP->clear();
}
