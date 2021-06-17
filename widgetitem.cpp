#include "widgetitem.h"

WidgetItem::WidgetItem() : QTableWidgetItem() {}
WidgetItem::WidgetItem(const QString &text) : QTableWidgetItem(text) {}

void WidgetItem::setDirectoryPtr(Directory* pointer)
{
    this->dirPtr = pointer;
}

void WidgetItem::setUrlPtr(Url* pointer)
{
    this->urlPtr = pointer;
}

Directory* WidgetItem::getDirectoryPtr()
{
    return this->dirPtr;
}

Url* WidgetItem::getUrlPtr()
{
    return this->urlPtr;
}
