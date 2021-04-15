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

	/*void File::updateRow(string data)
	{
		string line;
		vector<vector<string>> values;
		vector<string> line_values_temp;
		bool breaker = false;
		while (getline(is, line))
		{
			string line_value;
			vector<string> line_values;
			stringstream ss(line);
			while (getline(ss, line_value, ';'))
			{
				if (line_value == data)
				{
					line_values.push_back(line_value);
					line_values_temp = line_values;
					breaker = true;
					break;
				}
				line_values.push_back(line_value);
			}
			if (breaker == true)
				break;
			values.emplace_back(line_values);

		}
		int val;
		string newVal;
		cout << "which value to change" << endl;
		if (line_values_temp.size() < 2)
			cout << "1 - directory name";
		else if (line_values_temp.size() == 2)
			cout << "1 - directory name, 2 - description";
		else
			cout << "0 - URL  1 - description  2 - icon  3 - ID";

		cin >> val;
		cout << endl << "naw value: ";
		cin >> newVal;
		line_values_temp[val] = newVal;
		values.emplace_back(line_values_temp);

		for (int j = 0; j < values.size(); j++)
			for (int k = 0; k < values[j].size(); k++)
				this->write(values[j][k]);
	}
	fs << val;
}