#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::multimap;


void add_child_name(multimap<string, string> &children_map, string family_name, string child_name)
{
	children_map.insert({family_name, child_name});

	return;
}

void print_map(multimap<string, string> &children_map)
{

	for(auto child : children_map)
	{
		cout << "Family: " << child.first << " Child: " << child.second << endl;
	}

	return;
}


int main()
{
	multimap<string, string> children;


	add_child_name(children, string("Miller"), string("Ted"));
	add_child_name(children, string("Miller"), string("Kathy"));

	add_child_name(children, string("Martin"), string("Marie"));
	add_child_name(children, string("Martin"), string("Kyle"));
	add_child_name(children, string("Martin"), string("Trevor"));

	print_map(children);
	



	return 0;
}
