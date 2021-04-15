#pragma once

#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tag {
private:
	vector<string> items;
public:
	Tag();
	~Tag();

	void addTag(string value = "");
	vector<string> getItems();
	bool findItem(string value);
	void removeTag(string value);
};

#endif
