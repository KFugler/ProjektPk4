#include "user.h"

User::User() {
    username = "defaultName";
    password = "defaultPassword";
}

User::User(QString newUsername, QString newPassword) {
    username = newUsername;
    password = newPassword;
}

User::~User() {}

QString User::getUsername() {
    return username;
}

QString User::getPassword() {
    return password;
}

void User::setUsername(QString newUsername) {
    username = newUsername;
}

void User::setPassword(QString newPassword) {
    password = newPassword;
}
