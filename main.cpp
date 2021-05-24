#include "mainwindow.h"
#include "loginwindow.h"
#include "tree.h"

#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    LoginWindow l;
    if(l.exec() != QDialog::Accepted){
        a.quit();
    }else{
        m.show();
        a.exec();
    }
    return 0;
}
