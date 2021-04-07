#include "Directory.h"

int Directory::ID = 0;

Directory::Directory() {
	name = "directory";
	description = "example directory";
	id = ID++;
}

Directory::Directory(string newName, string newDescription) {
	name = newName;
	description = newDescription;
	id = ID++;
}

Directory::~Directory() {}

string Directory::getName() {
	return name;
}

string Directory::getDescription() {
	return description;
}

vector<Url> Directory::getItems() {
	return items;
}

Url Directory::getUrlObjectByName(string url) {
	int size = items.size();
	for (int i = 0; i < size; ++i) {
		if (items[i].getUrl() == url) {
			return items[i];
		}
	}
}

int Directory::getId() {
	return id;
}

void Directory::setName(string newName) {
	name = newName;
}

void Directory::setDescription(string newDescription) {
	description = newDescription;
}

void Directory::addUrl(string url, string description, string icon) {
	Url newUrl(url, description, icon);
	items.push_back(newUrl);
}

void Directory::removeUrl(string url) {
	auto item = find(items.begin(), items.end(), getUrlObjectByName(url));
	if (item != items.end()) {
		auto idx = distance(items.begin(), item);
		items.erase(items.begin() + idx);
	}
	else {
		cout << "not found URL to remove" << endl;
	}	
}

void Directory::updateUrl(Url url) {
	int size = items.size();
	for (int i = 0; i < size; ++i) {
		if (items[i].getId() == url.getId()) {
			items[i] = url;
		}
	}
}
