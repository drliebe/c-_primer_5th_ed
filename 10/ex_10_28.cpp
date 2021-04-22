#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::vector;
using std::list;
using std::back_inserter;
using std::front_inserter;
using std::inserter;

int main()
{
	vector<int> ivec{1,2,3,4,5,6,7,8,9};
	list<int> ilist1;
	list<int> ilist2;
	list<int> ilist3;

	copy(ivec.begin(), ivec.end(), inserter(ilist1, ilist1.begin()));
	copy(ivec.begin(), ivec.end(), back_inserter(ilist2));
	copy(ivec.begin(), ivec.end(), front_inserter(ilist3));

	for(auto i : ilist1)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	for(auto i : ilist2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	for(auto i : ilist3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	return 0;
}
