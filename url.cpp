#include "url.h"

Url::Url() {}

Url::Url(QString urlValue, QString descriptionValue, QString tagsValue) {
    url = urlValue;
    description = descriptionValue;
    tags = tagsValue;
}

Url::~Url() {}

QString Url::getUrl() {
    return url;
}

QString Url::getDescription() {
    return description;
}

QString Url::getTags() {
    return tags;
}

void Url::setUrl(QString urlValue) {
    url = urlValue;
}

void Url::setDescription(QString descriptionValue) {
    description = descriptionValue;
}

void Url::setTag(QString value) {
    tags = value;
}
