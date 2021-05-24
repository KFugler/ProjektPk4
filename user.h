#ifndef USER_H
#define USER_H

#include <QString>

using namespace std;

class User {
private:
    QString username;
    QString password;
public:
    User();
    User(QString newUsername, QString newPassword);
    ~User();

    QString getUsername();
    QString getPassword();

    void setUsername(QString value);
    void setPassword(QString value);
};

#endif // USER_H
