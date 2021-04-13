#pragma once

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include "Directory.h"

using namespace std;

class Tree {
private:
	vector<Directory> items;
public:
	// Default constructor
	Tree();

	// Destructor
	~Tree();

	vector<Directory> getItems();
	Directory getDirectoryObjectByName(string);

	void addDirectory(string, string);
	void removeDirectory(string);
	void updateDirectory(Directory);
};

#endif