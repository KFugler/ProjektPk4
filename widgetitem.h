#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QTableWidgetItem>
#include <QVariant>
#include <QString>
#include <QDataStream>
#include <QPointer>
#include "directory.h"
#include "url.h"

class WidgetItem : public QTableWidgetItem
{
public:
    WidgetItem();
    WidgetItem(const QString &text);
    void setDirectoryPtr(Directory* ptr);
    void setUrlPtr(Url* ptr);
    Url* getUrlPtr();
    Directory* getDirectoryPtr();

private:
    Directory *dirPtr;
    Url *urlPtr;
};

#endif // WIDGETITEM_H
