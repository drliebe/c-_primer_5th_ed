#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;


void read_string_vec(string &filename, vector<string> &vec)
{
	string line;
	std::ifstream ifs;
	ifs.open(filename);
	if (ifs)
	{
		while(getline(ifs,line))
		{
			vec.push_back(line);
		}
	}
	else
	{
		std::cout << "Error opening: " << filename << std::endl;
	}

	return;
};


int main()
{
	string filename1 = "test.txt";
	vector<string> vec1;

	read_string_vec(filename1, vec1);

	for( auto s : vec1)
	{
		std::cout << s << std::endl;
	}

	return 0;
}
