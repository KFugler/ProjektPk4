#include "UserFile.h"

UserFile::UserFile(string value) : File(value) {}
UserFile::~UserFile() {}

void UserFile::readUserFile(UserList& newList) {
    vector<vector<string>> input = this->read();
    UserList newUserList;
    string tmpString;
    int tmpInt = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (j == 0) {
                tmpString = input[i][j];
                tmpInt = stoi(tmpString);
            }
        }
        newUserList.addUser(tmpInt, input[i][1], input[i][2]);
    }
}

void UserFile::writeUserFile(UserList& newList) {
    for (int i = 0; i < newList.getUserList().size(); ++i) {
        this->write(to_string(newList.getUserList()[i].getId()));
        this->write(newList.getUserList()[i].getUsername());
        this->write(newList.getUserList()[i].getPassword());
        this->endrow();
    }
    //zapisywanie do pliku nie dziala, bedzie poprawione
}