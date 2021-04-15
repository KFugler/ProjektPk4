#include "TreeFile.h"

TreeFile::TreeFile(string value) : File(value) {}
TreeFile::~TreeFile(){}

void TreeFile::readTreeFile(Tree& newTree) {
    vector<vector<string>> one = this->read();
    Directory dirName;

    for (int i = 0; i < one.size(); i++)
    {
        if (one[i].size() < 2)
            cout << endl;
        else if (one[i].size() == 2) {
            newTree.addDirectory(one[i][0], one[i][1]);
            dirName = newTree.getDirectoryObjectByName(one[i][0]);
        }
        else
        {
            vector<string> vect;

            stringstream ss(one[i][3]);

            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                vect.push_back(substr);
            }

            dirName.addUrl(one[i][0], one[i][1], one[i][2], vect);
            newTree.updateDirectory(dirName);
        }
    }
}

void TreeFile::writeFile(Tree& newTree) {
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

