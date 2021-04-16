#pragma once

#ifndef USERFILE_H
#define USERFILE_H

#include "File.h"
#include "UserList.h"
#include "User.h"
#include <string>

using namespace std;

class UserFile : public File {
public:
	UserFile(string value);
	~UserFile();

	void readUserFile(UserList& newList);
	void writeUserFile(UserList& newList);
};

#endif