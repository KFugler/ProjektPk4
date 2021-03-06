#include "Directory.h"
#include "File.h"

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

vector<Url> Directory::getUrls() {
	return urls;
}

Url Directory::getUrlObjectByName(string url) {
	int size = urls.size();
	for (int i = 0; i < size; ++i) {
		if (urls[i].getUrl() == url) {
			return urls[i];
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

void Directory::addUrl(string url, string description, string icon, vector<string> tags) {
	Url newUrl(url, description, icon, tags);
	urls.push_back(newUrl);
}

void Directory::removeUrl(string url) {
	auto item = find(urls.begin(), urls.end(), getUrlObjectByName(url));
	if (item != urls.end()) {
		auto idx = distance(urls.begin(), item);
		urls.erase(urls.begin() + idx);
	}
	else {
		cout << "not found URL to remove" << endl;
	}
}

void Directory::updateUrl(Url obj) {
	int size = urls.size();
	for (int i = 0; i < size; ++i) {
		if (urls[i].getId() == obj.getId()) {
			urls[i] = obj;
		}
	}
}

void Directory::getWebsite(string url, string name)
{
	//Url url =  getUrlObjectByName(url);
	bool exists = false;
	for (Url u : urls)
	{
		if (u.getUrl().compare(url) == 0)
		{
			exists = true;
		}
	}

	if (!exists)
	{
		File file(name);
		file.write("curl");
	}
}

///////////////////////////////////////////////////////// update 12.05

Directory Directory::getDirectoryObjectByName(string name) {
	int size = directories.size();
	for (int i = 0; i < size; ++i) {
		if (directories[i].getName() == name) {
			return directories[i];
		}
	}
}

void Directory::addDirectory(string name, string description) {
	Directory newDirectory(name, description);
	directories.push_back(newDirectory);
}

void Directory::removeDirectory(string name) {
	auto item = find(directories.begin(), directories.end(), getDirectoryObjectByName(name));
	if (item != directories.end()) {
		auto idx = distance(directories.begin(), item);
		directories.erase(directories.begin() + idx);
	}
	else {
		cout << "not found Directory to remove" << endl;
	}
}


vector<Directory> Directory::getDirectories()
{
	return directories;
}
int Directory::getDirectoriesSize() {
	return directories.size();
}

void Directory::setUrls(vector<Url> newUrls)
{
	urls = newUrls;
}
void Directory::setDirectories(vector<Directory> newDirectories)
{
	directories = newDirectories;
}