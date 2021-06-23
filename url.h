#ifndef URL_H
#define URL_H

#include <QString>
#include <QVector>

using namespace std;

class Url
{
private:
    QString url;
    QString description;
    QString tags;

public:
    Url();
    Url(QString url, QString description, QString tags);
    ~Url();

    QString getUrl();
    QString getDescription();
    QString getTags();

    void setUrl(QString url);
    void setDescription(QString description);
    void setTag(QString value);

    bool operator==(const Url& obj) const
    {
        return (this->url.compare(obj.url) == 0);
    }
};

#endif // URL_H
