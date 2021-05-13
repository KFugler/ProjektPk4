#include "directory.h"
//#include "file.h"

int Directory::ID = 0;

Directory::Directory() {
    name = "directory";
    description = "example directory";
    id = ID++;
}

Directory::Directory(QString newName, QString newDescription) {
    name = newName;
    description = newDescription;
    id = ID++;
}

Directory::~Directory() {}

QString Directory::getName() {
    return name;
}

QString Directory::getDescription() {
    return description;
}

QVector<Url> Directory::getUrls() {
    return urls;
}

Url Directory::getUrlObjectById(int id) {
    int size = urls.size();
    for (int i = 0; i < size; ++i) {
        if (urls[i].getId() == id) {
            return urls[i];
        }
    }
}

Url Directory::getUrlObjectByIndex(int index) {
    return urls[index];
}

int Directory::getId() {
    return id;
}

void Directory::setName(QString newName) {
    name = newName;
}

void Directory::setDescription(QString newDescription) {
    description = newDescription;
}

void Directory::addUrl(QString url, QString description, QString icon, QVector<QString> tags) {
    Url newUrl(url, description, icon, tags);
    urls.push_back(newUrl);
}

void Directory::removeUrlById(int id) {
    auto item = find(urls.begin(), urls.end(), getUrlObjectById(id));
    if (item != urls.end()) {
        auto idx = distance(urls.begin(), item);
        urls.erase(urls.begin() + idx);
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

//void Directory::getWebsite(QString url, QString name)
//{
//    //Url url =  getUrlObjectByName(url);
//    bool exists = false;
//    for (Url u : urls)
//    {
//        if (u.getUrl().compare(url) == 0)
//        {
//            exists = true;
//        }
//    }

//    if (!exists)
//    {
//        File file(name);
//        file.write("curl");
//    }
//}
