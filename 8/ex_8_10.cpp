#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

int main(int argv, char** argc)
{
	string input_filename(argc[1]);
	ifstream ifs;
	ifs.open(input_filename);

	if (!ifs)
		cerr << "Error opening " << input_filename << endl;

	vector<string> file_contents;
	string line;
	
	cout << "Repeating contents by line: " << endl;

	while (getline(ifs, line))
	{
		file_contents.push_back(line);
	}
	for (auto l : file_contents)
	{
		cout << l << endl;
	}

	cout << "Repeating contents by word: " << endl;

	for (auto l : file_contents)
	{
		istringstream iss(l);
		string word;
		while (iss >> word)
		{
			cout << word << endl;
		}
	}

	return 0;
}
