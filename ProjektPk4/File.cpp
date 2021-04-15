#include "File.h"

File::File() {}

File::File(string name)
{
	filename = name;
	fs.open(filename, std::ios::app);
	is.open(filename);
	isfirst = true;
}

File::~File()
{
	fs.close();
	is.close();
}

void File::endrow()
{
	fs << std::endl;
	isfirst = true;
}

vector<vector<string>>File::read()
{
	string line;
	vector<vector<string>> values;
	while (getline(is, line))
	{
		string line_value;
		vector<string> line_values;
		stringstream ss(line);
		while (getline(ss, line_value, ';'))
		{
			line_values.push_back(line_value);
		}
		values.emplace_back(line_values);
	}
	return values; 
}

void File::write(string val)
{
	if (!isfirst) {
		fs << ";";
	}
	else {
		isfirst = false;
	}
	fs << val;
}

bool File::compareFiles(string name)
{
	string lineA;
	string lineB;
	File file(name);
	bool isEqual = true;

	while (getline(file.is, lineA) && getline(is, lineB))
	{
		if (lineA != lineB)
		{
			isEqual = false;
		}
	}

	return isEqual;
}