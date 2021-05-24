#include "userlist.h"

UserList::UserList() {}

UserList::~UserList() {}

QVector<User> UserList::getUserList() {
    return userList;
}

int UserList::getListSize() {
    return inputListSize;
}

void UserList::setListSize(int newSize) {
    inputListSize = newSize;
}

void UserList::addUser(QString newUsername, QString newPassword) {
        User newUser;
        newUser.setUsername(newUsername);
        newUser.setPassword(newPassword);
        userList.push_back(newUser);
}

QString UserList::registerUser(QString newUsername, QString newPassword) {
    bool isUser = false;
    for (int i = 0; i < userList.size(); i++) {
        if (userList[i].getUsername() == newUsername) {
            isUser = true;
        }
    }
    if (isUser == false) {
        addUser(newUsername, newPassword);
        return newUsername;
    }
    else {
        return "invalid";
    }
}

QString UserList::loginUser(QString newUsername, QString newPassword) {
    bool isUser = false;
    for (int i = 0; i < userList.size(); i++) {
        if (userList[i].getUsername() == newUsername && userList[i].getPassword() == newPassword) {
            isUser = true;
            return newUsername;
        }
    }
    return "unknown";
}
