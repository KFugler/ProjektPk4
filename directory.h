#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QString>
#include <QVector>

#include "url.h"

using namespace std;

class Directory
{
private:
    QString name;
    QString description;
    QVector<Url*> urls;
public:
    // Default constructor
    Directory();

    // Overload constructor
    Directory(QString name, QString description);

    // Destructor
    ~Directory();

    QString getName();
    QString getDescription();

    QVector<Url*> getUrls();

    void setName(QString name);
    void setDescription(QString description);

    void addUrl(Url* newUrl);
    void removeUrl(Url* url);
};

#endif // DIRECTORY_H
