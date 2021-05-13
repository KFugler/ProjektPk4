#ifndef TAG_H
#define TAG_H

#include <QString>
#include <QVector>

using namespace std;

class Tag
{
private:
    QVector<QString> items;
public:
    Tag();
    ~Tag();

    void addTag(QString value = "");
    QVector<QString> getItems();
    bool findItem(QString value);
    void removeTag(QString value);
};

#endif // TAG_H
