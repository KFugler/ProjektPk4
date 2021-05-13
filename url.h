#ifndef URL_H
#define URL_H

#include "tag.h"

#include <QString>
#include <QVector>

using namespace std;

class Url
{
private:
    int id;
    QString url;
    QString description;
    QString icon;
    Tag tags;

    static int ID;
public:
    // Default constructor
    Url();

    // Overload constructor
    Url(QString url, QString description, QString icon, QVector<QString> tagsVector);

    // Destructor
    ~Url();

    QString getUrl();
    QString getDescription();
    QString getIcon();
    Tag getTags();
    int getId();

    void setUrl(QString url);
    void setDescription(QString description);
    void setIcon(QString icon);

    void removeTag(QString value);
    void addTag(QString value);

    bool operator==(const Url& obj) const
    {
        return (this->url.compare(obj.url) == 0);
    }
};

#endif // URL_H
