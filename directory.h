#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QString>
#include <QVector>

#include "url.h"

using namespace std;

class Directory
{
private:
    int id;
    QString name;
    QString description;
    QVector<Url> urls;
    static int ID;
public:
    // Default constructor
    Directory();

    // Overload constructor
    Directory(QString name, QString description);

    // Destructor
    ~Directory();

    QString getName();
    QString getDescription();

    QVector<Url> getUrls();
    Url getUrlObjectById(int id);
    Url getUrlObjectByIndex(int index);

    int getId();

    void setName(QString name);
    void setDescription(QString description);

    void addUrl(QString url, QString description, QString icon, QVector<QString> tags);
    void removeUrlById(int id);
    void updateUrl(Url obj);

//    void getWebsite(QString url, QString name);

    bool operator==(const Directory& obj) const
    {
        return (this->name.compare(obj.name) == 0);
    }
};

#endif // DIRECTORY_H
