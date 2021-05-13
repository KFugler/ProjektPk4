#include "url.h"

int Url::ID = 0;

Url::Url() {
    url = "localhost";
    description = "example Url";
    icon = "example.jpg";
    id = ID++;
}

Url::Url(QString newUrl, QString newDescription, QString newIcon, QVector<QString> tagsVector) {
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

QString Url::getUrl() {
    return url;
}

QString Url::getDescription() {
    return description;
}

QString Url::getIcon() {
    return icon;
}

int Url::getId() {
    return id;
}

Tag Url::getTags() {
    return tags;
}

void Url::setUrl(QString newUrl) {
    url = newUrl;
}

void Url::setDescription(QString newDescription) {
    description = newDescription;
}

void Url::setIcon(QString newIcon) {
    icon = newIcon;
}

void Url::removeTag(QString value) {
    tags.removeTag(value);
}

void Url::addTag(QString value) {
    tags.addTag(value);
}
