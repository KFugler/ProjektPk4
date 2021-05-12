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

/*void Tree::updateDirectory(Directory dir) {
	int size = directories.size();
	for (int i = 0; i < size; ++i) {
		if (directories[i].getId() == dir.getId()) {
			directories[i] = dir;
		}
	}
}*/            //wersja poprzednia


void Tree::updateDirectory(Directory dir) {
	int size = directories.size();
	for (int i = 0; i < size; ++i) {
		if (directories[i].getName() == dir.getName())
			directories[i] = dir;
		vector<Directory> temp = directories[i].getDirectories();
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j].getName() == dir.getName())
				directories[i] = dir;
		}
	}
	/*auto temp = getFromWholeTree(dir.getName(), getDirectories()[0]);
	getFromWholeTree(dir.getName(), getDirectories()[0]) = dir;				//do dopracowania z u¿yciem getFromWholeTree()
	*/																		
}

Directory Tree::getFromWholeTree(string name, Directory dir)
{
	Directory temp;
	if (dir.getName() == name)
		return dir;
	else
	{
		for (int i = 0; i < dir.getDirectories().size(); i++)
		{

			temp = dir.getDirectories()[i];
			//a = dir.getDirectories().size();
			return getFromWholeTree(name, temp);
		}
	}
	return dir;
}
