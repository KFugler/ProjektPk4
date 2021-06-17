#include "directory.h"
//#include "file.h"

Directory::Directory() {
    name = "directory";
    description = "example directory";
}

Directory::Directory(QString newName, QString newDescription) {
    name = newName;
    description = newDescription;
}

Directory::~Directory() {}

QString Directory::getName() {
    return name;
}

QString Directory::getDescription() {
    return description;
}

QVector<Url*> Directory::getUrls() {
    return urls;
}

void Directory::setName(QString newName) {
    name = newName;
}

void Directory::setDescription(QString newDescription) {
    description = newDescription;
}

void Directory::addUrl(Url* newUrl) {
    urls.push_back(newUrl);
}

void Directory::removeUrl(Url* url) {
    auto item = find(urls.begin(), urls.end(), url);
    if (item != urls.end()) {
        auto idx = distance(urls.begin(), item);
        urls.erase(urls.begin() + idx);
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
