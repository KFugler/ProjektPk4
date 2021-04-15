#pragma once

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
#include "Url.h"

using namespace std;

class Directory {
private:
	int id;
	string name;
	string description;
	vector<Url> items;

	static int ID;
public:
	// Default constructor
	Directory();

	// Overload constructor
	Directory(string, string);

	// Destructor
	~Directory();

	string getName();
	string getDescription();

	vector<Url> getItems();
	Url getUrlObjectByName(string);

	int getId();

	void setName(string);
	void setDescription(string);

	void addUrl(string, string, string);
	void removeUrl(string);
	void updateUrl(Url);

	void getWebsite(string, string);

	bool operator==(const Directory& obj) const
	{
		return (this->name.compare(obj.name) == 0);
	}
};

#endif