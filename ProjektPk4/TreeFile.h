#pragma once

#ifndef TREEFILE_H
#define TREEFILE_H

#include <iostream>
#include <string>
#include "File.h"
#include "Tree.h"
#include "Directory.h"

using namespace std;

class TreeFile: public File {
public:
	TreeFile(string value);
	~TreeFile();

	void readTreeFile(Tree& newTree);
	void writeFile(Tree& newTree);
};

#endif