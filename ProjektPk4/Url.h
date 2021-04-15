#pragma once

#ifndef URL_H
#define URL_H

#include <iostream>
#include <vector>
#include "Tag.h"

using namespace std;

class Url {
private:
	int id;
	string url;
	string description;
	string icon;
	Tag tags;

	static int ID;
public:
	// Default constructor
	Url();

	// Overload constructor
	Url(string url, string description, string icon, vector<string> tagsVector);

	// Destructor
	~Url();

	string getUrl();
	string getDescription();
	string getIcon();
	Tag getTags();
	int getId();

	void setUrl(string url);
	void setDescription(string description);
	void setIcon(string icon);

	void removeTag(string value);
	void addTag(string value);

	bool operator==(const Url& obj) const
	{
		return (this->url.compare(obj.url) == 0);
	}
};

#endif