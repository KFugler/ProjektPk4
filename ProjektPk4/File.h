#pragma once
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

	template<typename T>
	File& write(const T& val)
	{
		if (!isfirst) {
			fs << ";";
		}
		else {
			isfirst = false;
		}
		fs << val;
		return *this;
	}
	void endrow();
	vector<vector<string>> read();
	
	//void updateRow(string data);
};