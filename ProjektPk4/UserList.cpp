#include "UserList.h"

UserList::UserList() {}

UserList::~UserList() {}

vector<User> UserList::getUserList() {
	return userList;
}

int UserList::getListSize() {
	return inputListSize;
}

void UserList::setListSize(int newSize) {
	inputListSize = newSize;
}

void UserList::addUser(string newUsername, string newPassword) {
		User newUser;
		newUser.setUsername(newUsername);
		newUser.setPassword(newPassword);
		userList.push_back(newUser);
}

void UserList::registerUser(string newUsername, string newPassword) {
	bool isUser = false;
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i].getUsername() == newUsername) {
			isUser = true;
		}
	}
	if (isUser == false) {
		addUser(newUsername, newPassword);
	}
	else {
		cout << "Podany uzytkownik juz istnieje!" << endl;
	}
}

void UserList::loginUser(string newUsername, string newPassword) {
	bool isUser = false;
	string user;
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i].getUsername() == newUsername && userList[i].getPassword() == newPassword) {
			isUser = true;
			user = newUsername;
		}
	}
	if (isUser == false) {
		cout << "Niepoprawny uzytkownik lub haslo!" << endl;	
	}
	else {
		cout << "Zalogowano poprawnie jako: " + user << endl;
	}
}