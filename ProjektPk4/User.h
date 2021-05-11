#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
private:
	string username;
	string password;
public:
	User();
	User(string newUsername, string newPassword);
	~User();

	string getUsername();
	string getPassword();

	void setUsername(string value);
	void setPassword(string value);
};

#endif