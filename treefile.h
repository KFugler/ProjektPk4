#ifndef TREEFILE_H
#define TREEFILE_H

#include <iostream>
#include <QString>
#include "file.h"
#include "tree.h"

class treeFile: public File {
public:
    treeFile();
    ~treeFile();
    void readTreeFile(Tree& newTree, QString currentUser);
    void writeFile(Tree& newTree);
    void writeTreeToFile(Tree& newTree, File output);
private:
       QVector<QVector<QString>> readFile;
       QString userName;
       QString path = qApp->applicationDirPath() + "/_directories.csv";
};

#endif // TREEFILE_H
