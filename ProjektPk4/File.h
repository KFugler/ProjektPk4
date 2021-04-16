#pragma once

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class File
{
	string filename;
	std::ofstream fs;
	std::ifstream is;
	bool isfirst;
public:
	File();
	File(string name);
	~File();

	void endrow();
	vector<vector<string>> read();
	void write(string value);
	bool compareFiles(string url);
};

#endif