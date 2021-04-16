#include "User.h"

int User::userID = 0;

User::User() {
	username = "defaultName";
	password = "defaultPassword";
	userId = userID++;
}

User::User(string newUsername, string newPassword) {
	username = newUsername;
	password = newPassword;
	userId = userID++;
}

User::~User() {}

int User::getId() {
	return userId;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setId(int newId) {
	userId = newId;
}

void User::setUsername(string newUsername) {
	username = newUsername;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}