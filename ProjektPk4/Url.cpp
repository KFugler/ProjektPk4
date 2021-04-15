#include "Url.h"

int Url::ID = 0;

Url::Url() {
	url = "localhost";
	description = "example Url";
	icon = "example.jpg";
	id = ID++;
}

Url::Url(string newUrl, string newDescription, string newIcon, vector<string> tagsVector) {
	url = newUrl;
	description = newDescription;
	icon = newIcon;
	id = ID++;
	int tagsSize = tagsVector.size();
	if (tagsSize > 0) {
		for (int i = 0; i < tagsSize; ++i) {
			tags.addTag(tagsVector[i]);
		}
	}
}

Url::~Url() {}

string Url::getUrl() {
	return url;
}

string Url::getDescription() {
	return description;
}

string Url::getIcon() {
	return icon;
}

int Url::getId() {
	return id;
}

Tag Url::getTags() {
	return tags;
}

void Url::setUrl(string newUrl) {
	url = newUrl;
}

void Url::setDescription(string newDescription) {
	description = newDescription;
}

void Url::setIcon(string newIcon) {
	icon = newIcon;
}

void Url::removeTag(string value) {
	tags.removeTag(value);
}

void Url::addTag(string value) {
	tags.addTag(value);
}