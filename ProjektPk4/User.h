#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
private:
	static int userID;
	int userId;
	string username;
	string password;
public:
	User();
	User(string newUsername, string newPassword);
	~User();

	int getId();
	string getUsername();
	string getPassword();

	void setId(int newId);
	void setUsername(string value);
	void setPassword(string value);
};

#endif