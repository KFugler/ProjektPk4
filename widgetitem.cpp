#include "widgetitem.h"

WidgetItem::WidgetItem() : QTableWidgetItem() {}
WidgetItem::WidgetItem(const QString text) : QTableWidgetItem(text) {
    this->setToolTip(text);
}
WidgetItem::~WidgetItem(){
    dirPtr = nullptr;
    urlPtr = nullptr;
    delete dirPtr;
    delete urlPtr;
}

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

void WidgetItem::setType(QString value)
{
    this->type = value;
}

QString WidgetItem::getType()
{
    return this->type;
}
