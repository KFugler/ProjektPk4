#pragma once

#ifndef URL_H
#define URL_H

#include <iostream>
#include <vector>

using namespace std;

class Url {
private:
	int id;
	string url;
	string description;
	string icon;

	static int ID;
public:
	// Default constructor
	Url();

	// Overload constructor
	Url(string, string, string);

	// Destructor
	~Url();

	string getUrl();
	string getDescription();
	string getIcon();
	int getId();

	void setUrl(string);
	void setDescription(string);
	void setIcon(string);

	bool operator==(const Url& obj2) const
	{
		return (this->url.compare(obj2.url) == 0);
	}
};

#endif