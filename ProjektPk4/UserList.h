#pragma once

#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

using namespace std;

class UserList {
private:
	vector<User> userList;
public:
	UserList();
	~UserList();

	vector<User> getUserList();

	void updateUserList(vector<User> value);

	void addUser(int id, string username, string password);
	void deleteUser(string username);
};

#endif