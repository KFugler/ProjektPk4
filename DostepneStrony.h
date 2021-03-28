#ifndef DOSTEPNESTRONY_H
#define DOSTEPNESTRONY_H

#include <QDialog>
#include "BazaDanych.h"

namespace Ui {
class DostepneStrony;
}

class DostepneStrony : public QDialog
{
    Q_OBJECT

public:
    explicit DostepneStrony(QWidget *parent = nullptr);
    ~DostepneStrony();
    void Show();
private:
    Ui::DostepneStrony *ui;
    void updateUI();
};

#endif // DOSTEPNESTRONY_H
