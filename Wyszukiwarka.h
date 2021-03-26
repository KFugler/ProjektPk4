#ifndef WYSZUKIWARKA_H
#define WYSZUKIWARKA_H

#include <QDialog>
#include "BazaDanych.h"

namespace Ui {
class Wyszukiwarka;
}

class Wyszukiwarka : public QDialog
{
    Q_OBJECT

public:
    explicit Wyszukiwarka(QWidget *parent = nullptr);
    ~Wyszukiwarka();

private slots:
    void on_przyciskWyszukiwarka_clicked();

private:
    Ui::Wyszukiwarka *ui;

};
#endif // WYSZUKIWARKA_H
