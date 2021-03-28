
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DodajStrone.h"
#include "Wyszukiwarka.h"
#include "DostepneStrony.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_przyciskDodajStrone_clicked();
    void on_przyciskWyszukiwarka_clicked();
    void on_btnDostepneStrony_clicked();

private:
    Ui::MainWindow *ui;
    DodajStrone * ptrDodajStrone;
    Wyszukiwarka * ptrWyszukiwarka;
    DostepneStrony * ptrDostepneStrony;


};

#endif // MAINWINDOW_H
