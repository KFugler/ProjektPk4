#include "User.h"

User::User() {
	username = "defaultName";
	password = "defaultPassword";
}

User::User(string newUsername, string newPassword) {
	username = newUsername;
	password = newPassword;
}

User::~User() {}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setUsername(string newUsername) {
	username = newUsername;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}