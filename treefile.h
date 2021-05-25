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

    void readTreeFile(Tree& newTree);
    void writeFile(Tree& newTree);
};

#endif // TREEFILE_H

