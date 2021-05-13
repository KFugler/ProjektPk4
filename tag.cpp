#include "tag.h"

Tag::Tag() {};
Tag::~Tag() {};

void Tag::addTag(QString tagValue) {
    if (!findItem(tagValue)) {
        items.push_back(tagValue);
    }
}

QVector<QString> Tag::getItems() {
    return items;
}

bool Tag::findItem(QString tagValue) {
    return std::find(items.begin(), items.end(), tagValue) != items.end();
}

void Tag::removeTag(QString value) {
    if (findItem(value)) {
        auto idx = std::distance(items.begin(), std::find(items.begin(), items.end(), value));
        items.erase(items.begin() + idx);
    }
//    else {
//        cout << "No tag to remove" << endl;
//    }
}
