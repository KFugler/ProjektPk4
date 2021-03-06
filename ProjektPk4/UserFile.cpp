#include "UserFile.h"

UserFile::UserFile(string value) : File(value) {}
UserFile::~UserFile() {}

void UserFile::readUserFile(UserList& newList) {
    vector<vector<string>> input = this->read();
    for (int i = 0; i < input.size(); i++)
    {
        newList.addUser(input[i][0], input[i][1]);
    }
    newList.setListSize(input.size());
}

void UserFile::writeUserFile(UserList& newList) {
    for (int i = newList.getListSize(); i < newList.getUserList().size(); ++i) {
        this->write(newList.getUserList()[i].getUsername());
        this->write(newList.getUserList()[i].getPassword());
        this->endrow();
    }
}