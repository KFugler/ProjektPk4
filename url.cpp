#include "url.h"

Url::Url() {
    url = "localhost";
    description = "example Url";
}

Url::Url(QString newUrl, QString newDescription, QVector<QString> tagsVector) {
    url = newUrl;
    description = newDescription;
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

Tag Url::getTags() {
    return tags;
}

void Url::setUrl(QString newUrl) {
    url = newUrl;
}

void Url::setDescription(QString newDescription) {
    description = newDescription;
}

void Url::removeTag(QString value) {
    tags.removeTag(value);
}

void Url::addTag(QString value) {
    tags.addTag(value);
}
