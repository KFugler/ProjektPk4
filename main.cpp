#include "loginwindow.h"
#include "tree.h"

#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow l;
    l.show();
    a.exec();
    return 0;
}
