#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

using std::vector;
using std::map;
using std::set;
using std::string;
using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;

int main(int argv, char** argc)
{
	// Open up the file to be read
	string filename(argc[1]);
	ifstream ifs(filename);


	// Read in all of the file contents line by line	
	vector<string> file_contents;
	string file_line;
	while(getline(ifs,file_line))
	{
		file_contents.push_back(file_line);
	}

	//Go through each line and create the map of words to shared pointers to sets of line numbers
	map<string,shared_ptr<set<size_t>>> word_map;
	size_t line_number = 0;
	for(auto line : file_contents)
	{
		istringstream line_ss(line);
		string word;

		while(line_ss >> word)
		{
			if(word_map.find(word) == word_map.end())
			{//Word Not Already in Map
				word_map[word] = make_shared<set<size_t>>();
				(*word_map[word]).insert(line_number);
			}
			else
			{//Word Already in Map
				(*word_map[word]).insert(line_number);
			}
		}
		++line_number;
	}


	//Get the Requested Word To Look Up from the User, see if the word is in the map, if so, print the results
	cout << "Enter a word to look up in the text." << endl;
	string lookup_request;
	while(cin >> lookup_request)
	{
		if(word_map.find(lookup_request) == word_map.end())
		{ // Lookup Request not found in map
			cout << "Lookup Request Not Found in Map. Try another request or quit." << endl;
		}
		else
		{ // Lookup Request found in map
			shared_ptr<set<size_t>> p = word_map[lookup_request];
			size_t set_size = p->size();
			cout << lookup_request << " was found on " << set_size << " lines." << endl;
			set<size_t>::iterator b = p->begin();
			while(b != p->end())
			{
				cout << "(" << *b << "): " << file_contents[*b] << endl;				
				++b;
			}
		} 
		cout << endl << "Enter a word to look up in the text." << endl;
	}


	return 0;
}

