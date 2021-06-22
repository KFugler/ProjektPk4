#ifndef TREEFILE_H
#define TREEFILE_H

#include <iostream>
#include <QString>
#include "file.h"
#include "tree.h"


class treeFile: public File {
public:
    treeFile(QString value);
    ~treeFile();
    void readTreeFile(Tree& newTree, QString currentUser);
    void writeFile(Tree& newTree);
    void writeNewUserData(Tree& newTree, File output);
private:
       QVector<QVector<QString>> readFile;
       QString userName;
};

#endif // TREEFILE_H

