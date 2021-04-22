#include <iostream>
#include <string>
#include <forward_list>


using std::string;
using std::forward_list;


forward_list<string> func1(forward_list<string> flist, string query_string, string inserted_string)
{
	forward_list<string>::iterator it_prev=flist.before_begin();
	forward_list<string>::iterator it=flist.begin();	
	while(it != flist.end())
	{
		if (*it == query_string)
		{
			flist.insert_after(it, inserted_string);
			return flist;
		}
		else
		{
			it_prev = it;
			++it;
		}
	}
	flist.insert_after(it_prev, inserted_string);
	return flist;
}

int main()
{
	forward_list<string> flist1{"This", "sentence", "is", "complete"};
	string query1("Ted");
	string s1("not");

	flist1 = func1(flist1, query1, s1);

	for(auto s : flist1)
		std::cout << s << std::endl;

	return 0;
}
