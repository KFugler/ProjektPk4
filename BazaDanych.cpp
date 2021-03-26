#include "BazaDanych.h"

BazaDanych* BazaDanych::instance = nullptr;

BazaDanych::BazaDanych()
{
    init();
}

void BazaDanych::init()
{
    qDebug() << "in init()";
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("c:/Users/Karol/Strony.sqlite");

        if(QFile::exists("c:/Users/Karol/Strony.sqlite"))   // tutaj trzeba wpisac scieze do bazy danych
            qDebug() << "Znaleziono Baze Danych";
        else
           qDebug() << "Nie znaleziono Bazy Danych";

        if (!db.open())
            qDebug() << db.lastError().text();
        else
            qDebug() << "Baza Danych zaladowana poprawnie!";

}

BazaDanych *BazaDanych::getInstance()
{   
    if(instance == nullptr)
        instance = new BazaDanych();

    return instance;
}

QSqlDatabase BazaDanych::getDBInstance()
{
    return db;
}

void BazaDanych::ResetInstance()
{
      qDebug() << "usuwanie instancji bazy danych";
      delete instance;
      instance = nullptr;
}

BazaDanych::~BazaDanych()
{
   qDebug() << "zamykanie połaczenie z baza danych";
   db.close();
}
