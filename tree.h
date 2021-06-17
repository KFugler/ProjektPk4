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
    QVector<Directory*> directories;
public:
    Tree();
    ~Tree();

    QVector<Directory*> getDirectories();

    void addDirectory(Directory * newDir);
    void removeDirectory(Directory * dir);
};

#endif // TREE_H
