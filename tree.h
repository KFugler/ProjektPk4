#ifndef TREE_H
#define TREE_H

#include <QString>
#include <QVector>
#include <QDebug>

#include "directory.h"

using namespace std;

class Tree
{
private:
    QVector<Directory> directories;
public:
    Tree();
    ~Tree();

    QVector<Directory> getDirectories();
    Directory getDirectoryObjectById(int id);
    Directory getDirectoryObjectByIndex(int index);

    void addDirectory(QString, QString);
    void addDirectoryPreDone(Directory newDir);
    void removeDirectoryById(int id);
    void updateDirectory(Directory);
};

#endif // TREE_H
