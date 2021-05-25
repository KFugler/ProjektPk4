#include "treefile.h"


treeFile::treeFile(QString value) : File(value) {}
treeFile::~treeFile(){}


void treeFile::readTreeFile(Tree &tree)
{
File input(":/resources/Files/MyFile.csv");
QVector<QVector<QString>> readFile = input.read();

Directory dirName;

for (int i = 0; i < readFile.size(); i++)
{
    if (readFile[i].size() == 2) {
        dirName = Directory(readFile[i][0], readFile[i][1]);
        tree.addDirectoryPreDone(dirName);
    }
    else
    {
       QVector<QString> vector;
       for (int k=3;k<readFile[i].size();k++)
       {
        vector.append(readFile[k]);
       }

      dirName.addUrl(readFile[i][0], readFile[i][1], readFile[i][2], vector);
      tree.updateDirectory(dirName);
    }
}
}

void treeFile::writeFile(Tree& newTree) {
    int size = newTree.getDirectories().size();
    this->endrow();
    for (int i = 0; i < size; ++i) {
        this->write(newTree.getDirectories()[i].getName());
        this->write(newTree.getDirectories()[i].getDescription());
        this->endrow();
        for (int c = 0; c < newTree.getDirectories()[i].getUrls().size(); ++c) {
            this->write(newTree.getDirectories()[i].getUrls()[c].getUrl());
            this->write(newTree.getDirectories()[i].getUrls()[c].getDescription());
            this->write(newTree.getDirectories()[i].getUrls()[c].getIcon());
            // Dorobic dodawanie tagow z wektora
            this->endrow();
        }
    }
}


