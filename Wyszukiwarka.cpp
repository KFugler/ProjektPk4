#include "Wyszukiwarka.h"
#include "ui_Wyszukiwarka.h"

Wyszukiwarka::Wyszukiwarka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wyszukiwarka)
{
    ui->setupUi(this);
    ui->rdoName->setChecked(true);
}

Wyszukiwarka::~Wyszukiwarka()
{
    delete ui;
}

void Wyszukiwarka::on_przyciskWyszukiwarka_clicked()
{
    QString sValue = ui->txtValue->text();
    QString sCriteriaColum = "";

    if(ui->rdoId->isChecked())
        sCriteriaColum="Id";
    else if (ui->rdoName->isChecked())
        sCriteriaColum="Nazwa";
    else
        sCriteriaColum = "Nazwa";

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( BazaDanych::getInstance()->getDBInstance());
    query.prepare("select * from cpp_strony where " +sCriteriaColum+" like '%" + sValue + "%'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
       if(query.numRowsAffected()>0)
       qDebug() << "== Sukces! : " << query.lastQuery();
       else {
           qDebug() << " Nie znaleziono ! ";
           qDebug() << " Zapytanie to : " << query.lastQuery();
       }
    }
    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tabelka->setModel(model);
    qDebug() << "Rzedy : " << model->rowCount();
    ui->tabelka->show();
}
