#include "Tag.h"

Tag::Tag() {};
Tag::~Tag() {};

void Tag::addTag(string tagValue) {
	if (!findItem(tagValue)) {
		items.push_back(tagValue);
	}
}

vector<string> Tag::getItems() {
	return items;
}

bool Tag::findItem(string tagValue) {
	return std::find(items.begin(), items.end(), tagValue) != items.end();
}

void Tag::removeTag(string value) {
	if (findItem(value)) {
		auto idx = distance(items.begin(), std::find(items.begin(), items.end(), value));
		items.erase(items.begin() + idx);
	}
	else {
		cout << "No tag to remove" << endl;
	}
}