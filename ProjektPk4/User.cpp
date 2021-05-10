#include "User.h"

User::User() {
	userType = "user";
	username = "defaultName";
	password = "defaultPassword";
}

User::User(string newUsername, string newPassword) {
	userType = "user";
	username = newUsername;
	password = newPassword;
}

User::~User() {}

string User::getUserType() {
	return userType;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setUserType(string newUserType) {
	userType = newUserType;
}

void User::setUsername(string newUsername) {
	username = newUsername;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}