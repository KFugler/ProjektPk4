#ifndef USERLIST_H
#define USERLIST_H

#include "user.h"

#include <QVector>

using namespace std;

class UserList {
private:
    QVector<User> userList;
    int inputListSize = 0;
public:
    UserList();
    ~UserList();

    QVector<User> getUserList();
    int getListSize();
    void setListSize(int newSize);
    void addUser(QString username, QString password);
    QString registerUser(QString username, QString password);
    QString loginUser(QString username, QString password);
};

#endif // USERLIST_H
