#include "Tree.h"

Tree::Tree() {}

Tree::~Tree() {}

vector<Directory> Tree::getDirectories() {
	return directories;
}

Directory Tree::getDirectoryObjectByName(string name) {
	int size = directories.size();
	for (int i = 0; i < size; ++i) {
		if (directories[i].getName() == name) {
			return directories[i];
		}
	}
}

void Tree::addDirectory(string name, string description) {
	Directory newDirectory(name, description);
	directories.push_back(newDirectory);
}

void Tree::removeDirectory(string name) {
	auto item = find(directories.begin(), directories.end(), getDirectoryObjectByName(name));
	if (item != directories.end()) {
		auto idx = distance(directories.begin(), item);
		directories.erase(directories.begin() + idx);
	}
	else {
		cout << "not found Directory to remove" << endl;
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
