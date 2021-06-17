#include "tree.h"

Tree::Tree() {}

Tree::~Tree() {}
QVector<Directory*> Tree::getDirectories() {
    return directories;
}

void Tree::addDirectory(Directory * newDir){

    directories.push_back(newDir);
}

void Tree::removeDirectory(Directory * dir) {
    auto item = find(directories.begin(), directories.end(), dir);
    if (item != directories.end()) {
        auto idx = distance(directories.begin(), item);
        directories.erase(directories.begin() + idx);
    }
}

