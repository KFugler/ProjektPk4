#ifndef USERFILE_H
#define USERFILE_H

#include "file.h"
#include "user.h"
#include "userlist.h"

using namespace std;

class UserFile : public File {
public:
    UserFile(QString value);
    ~UserFile();

    void readUserFile(UserList& newList);
    void writeUserFile(UserList& newList);
};

#endif // USERFILE_H
