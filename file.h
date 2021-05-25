#ifndef FILE_H
#define FILE_H

#endif // FILE_H

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>


using namespace std;

class File
{
    QString filename;
    bool isfirst;
public:
    File();
    File(QString name);
    ~File();

    void endrow();
    QVector<QVector<QString>> read();
    void write(QString value);
    //bool compareFiles(QString url);
};
