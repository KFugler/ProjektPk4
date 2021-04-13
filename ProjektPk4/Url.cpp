#include "Url.h"

int Url::ID = 0;

Url::Url() {
	url = "localhost";
	description = "example Url";
	icon = "example.jpg";
	id = ID++;
}

Url::Url(string newUrl, string newDescription, string newIcon) {
	url = newUrl;
	description = newDescription;
	icon = newIcon;
	id = ID++;
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

void Url::setUrl(string newUrl) {
	url = newUrl;
}

void Url::setDescription(string newDescription) {
	description = newDescription;
}

void Url::setIcon(string newIcon) {
	icon = newIcon;
}
