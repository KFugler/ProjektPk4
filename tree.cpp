#include "tree.h"

Tree::Tree() {}

Tree::~Tree() {}

QVector<Directory> Tree::getDirectories() {
    return directories;
}

Directory Tree::getDirectoryObjectById(int id) {
    int size = directories.size();
    for (int i = 0; i < size; ++i) {
        if (directories[i].getId() == id) {
            return directories[i];
        }
    }
}

Directory Tree::getDirectoryObjectByIndex(int index) {
    return directories[index];
}

void Tree::addDirectory(QString name, QString description) {
    Directory newDirectory(name, description);
    directories.push_back(newDirectory);
}

void Tree::removeDirectoryById(int id) {
    auto item = find(directories.begin(), directories.end(), getDirectoryObjectById(id));
    if (item != directories.end()) {
        auto idx = distance(directories.begin(), item);
        directories.erase(directories.begin() + idx);
    }
}

void Tree::updateDirectory(Directory dir) {
    int size = directories.size();
    for (int i = 0; i < size; ++i) {
        if (directories[i].getId() == dir.getId()) {
            directories[i] = dir;
        }
    }
}

