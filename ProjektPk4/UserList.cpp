#include "UserList.h"

UserList::UserList() {}

UserList::~UserList() {}

vector<User> UserList::getUserList(){
	return userList;
}

void UserList::updateUserList(vector<User> newUserList) {
	userList = newUserList;
}

void UserList::addUser(int newId, string newUsername, string newPassword) {
	User newUser;
	newUser.setId(newId);
	newUser.setUsername(newUsername);
	newUser.setPassword(newPassword);
	userList.push_back(newUser);
}

void UserList::deleteUser(string username) {

}