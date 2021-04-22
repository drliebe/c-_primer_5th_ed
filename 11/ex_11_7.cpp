#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

void add_family_name(map<string, vector<string>> &children_map, string family_name)
{
	vector<string> empty_vec;
	children_map[family_name] = empty_vec;
	
	return;
}

void add_child_name(map<string, vector<string>> &children_map, string family_name, string child_name)
{
	children_map[family_name].push_back(child_name);

	return;
}

void print_map(map<string, vector<string>> &children_map)
{
	for(auto family : children_map)
	{
		for(auto child : family.second)
		{
			cout << "Family: " << family.first << " Child: " << child << endl;
		}
	}
	return;
}


int main()
{
	map<string, vector<string>> children;

	add_family_name(children, string("Miller"));
	add_child_name(children, string("Miller"), string("Ted"));
	add_child_name(children, string("Miller"), string("Kathy"));
	add_family_name(children, string("Martin"));
	add_child_name(children, string("Martin"), string("Marie"));
	add_child_name(children, string("Martin"), string("Kyle"));
	add_child_name(children, string("Martin"), string("Trevor"));

	print_map(children);
	



	return 0;
}
