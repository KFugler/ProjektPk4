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

void UserList::addUser(string newUserType, string newUsername, string newPassword) {
	User newUser;
	newUser.setUserType(newUserType);
	newUser.setUsername(newUsername);
	newUser.setPassword(newPassword);
	userList.push_back(newUser);
}

//void UserList::deleteUser(string username) {
//	for (int i = 0; i < userList.size(); i++) {
//		if (userList[i].getUsername() == username) {
//			userList.erase(userList.begin()+i);
//		}
//	}
//}