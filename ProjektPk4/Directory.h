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
	vector<Url> urls;

	static int ID;
public:
	// Default constructor
	Directory();

	// Overload constructor
	Directory(string name, string description);

	// Destructor
	~Directory();

	string getName();
	string getDescription();

	vector<Url> getUrls();
	Url getUrlObjectByName(string name);

	int getId();

	void setName(string name);
	void setDescription(string description);

	void addUrl(string url, string description, string icon, vector<string> tags);
	void removeUrl(string url);
	void updateUrl(Url obj);

	void getWebsite(string url, string name);

	bool operator==(const Directory& obj) const
	{
		return (this->name.compare(obj.name) == 0);
	}
};

#endif