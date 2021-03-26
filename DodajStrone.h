#ifndef DODAJSTRONE_H
#define DODAJSTRONE_H

#include <QDialog>
#include "BazaDanych.h"

namespace Ui {
class DodajStrone;
}

class DodajStrone : public QDialog
{
    Q_OBJECT

public:
    explicit DodajStrone(QWidget *parent = nullptr);
    ~DodajStrone();
    void Show();

private slots:
    void on_przyciskDodaj_clicked();

private:
    Ui::DodajStrone *ui;
    void resetElements();

};

#endif // DODAJSTRONE_H
