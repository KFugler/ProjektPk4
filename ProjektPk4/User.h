#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
private:
	string userType;
	string username;
	string password;
public:
	User();
	User(string newUsername, string newPassword);
	~User();

	string getUserType();
	string getUsername();
	string getPassword();

	void setUserType(string value);
	void setUsername(string value);
	void setPassword(string value);
};

#endif