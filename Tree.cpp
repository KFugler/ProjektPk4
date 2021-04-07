#include "Tree.h"

Tree::Tree() {}

Tree::~Tree() {}

vector<Directory> Tree::getItems() {
	return items;
}

Directory Tree::getDirectoryObjectByName(string name) {
	int size = items.size();
	for (int i = 0; i < size; ++i) {
		if (items[i].getName() == name) {
			return items[i];
		}
	}
}

void Tree::addDirectory(string name, string description) {
	Directory newDirectory(name, description);
	items.push_back(newDirectory);
}

void Tree::removeDirectory(string name) {
	auto item = find(items.begin(), items.end(), getDirectoryObjectByName(name));
	if (item != items.end()) {
		auto idx = distance(items.begin(), item);
		items.erase(items.begin() + idx);
	}
	else {
		cout << "not found Directory to remove" << endl;
	}
}

void Tree::updateDirectory(Directory dir) {
	int size = items.size();
	for (int i = 0; i < size; ++i) {
		if (items[i].getId() == dir.getId()) {
			items[i] = dir;
		}
	}
}
