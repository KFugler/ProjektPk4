#ifndef URL_H
#define URL_H

#include "tag.h"

#include <QString>
#include <QVector>

using namespace std;

class Url
{
private:
    QString url;
    QString description;
    Tag tags;

public:
    // Default constructor
    Url();

    // Overload constructor
    Url(QString url, QString description, QVector<QString> tagsVector);

    // Destructor
    ~Url();

    QString getUrl();
    QString getDescription();
    Tag getTags();

    void setUrl(QString url);
    void setDescription(QString description);

    void removeTag(QString value);
    void addTag(QString value);

    bool operator==(const Url& obj) const
    {
        return (this->url.compare(obj.url) == 0);
    }
};

#endif // URL_H
