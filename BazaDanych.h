#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>


class BazaDanych
{
private:
    BazaDanych();
    static BazaDanych *instance;
    void init();
    QSqlDatabase db;
public:
    static BazaDanych* getInstance();
    static void ResetInstance();
    QSqlDatabase getDBInstance();
    ~BazaDanych();
};
#endif // BAZADANYCH_H
