#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::deque;

int main()
{
	list<int> l1{9,8,6,5,3,2,1};
	deque<int> odd;
	deque<int> even;

	for(auto i : l1)
	{
		if (i%2 == 0)
		{
			even.push_back(i);
		}
		else
		{
			odd.push_back(i);
		}
	}
	
	std::cout << "Evens: " << std::endl;
	for(auto i : even)
	{
		std::cout << i << std::endl;
	}


	std::cout << "Odds: " << std::endl;
	for(auto i : odd)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
