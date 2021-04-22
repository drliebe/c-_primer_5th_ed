#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

void add_family_name(map<string, vector<pair<string,string>>> &children_map, string family_name)
{
	vector<pair<string,string>> empty_vec;
	children_map[family_name] = empty_vec;
	
	return;
}

void add_child_name(map<string, vector<pair<string,string>>> &children_map, string family_name, string child_name, string birth_date)
{
	children_map[family_name].push_back({child_name,birth_date});

	return;
}

void print_map(map<string, vector<pair<string,string>>> &children_map)
{
	for(auto family : children_map)
	{
		for(auto child : family.second)
		{
			cout << "Family: " << family.first << " Child: " << child.first << " Birthdate: " << child.second << endl;
		}
	}
	return;
}


int main()
{
	map<string, vector<pair<string,string>>> children;

	add_family_name(children, string("Miller"));
	add_child_name(children, string("Miller"), string("Ted"), string("01/01/1990"));
	add_child_name(children, string("Miller"), string("Kathy"), string("02/01/1990"));
	add_family_name(children, string("Martin"));
	add_child_name(children, string("Martin"), string("Marie"), string("03/01/1991"));
	add_child_name(children, string("Martin"), string("Kyle"), string("04/01/1991"));
	add_child_name(children, string("Martin"), string("Trevor"), string("05/01/1991"));

	print_map(children);
	



	return 0;
}
