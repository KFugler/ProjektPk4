#pragma once

#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

using namespace std;

class UserList {
private:
	vector<User> userList;
	int inputListSize = 0;
public:
	UserList();
	~UserList();

	vector<User> getUserList();
	int getListSize();
	void setListSize(int newSize);
	void addUser(string username, string password);
	void registerUser(string username, string password);
	void loginUser(string username, string password);
};

#endif