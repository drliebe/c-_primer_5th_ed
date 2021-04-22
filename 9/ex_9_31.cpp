#include <iostream>
#include <list>
#include <forward_list>

using std::list;
using std::forward_list;

int main()
{
	list<int> li = {0,1,2,3,4,5,6,7,8,9};
	auto iter = li.begin();
	while(iter != li.end())
	{
		if (*iter % 2)
		{
			iter = li.insert(iter, *iter);
			++iter;
			++iter;
		}
		else
		{
			iter = li.erase(iter);
		}
	}

	std::cout << "List " << std::endl;

	for (auto i: li)
	{
		std::cout << i << std::endl;
	}


	forward_list<int> fli = {0,1,2,3,4,5,6,7,8,9};
	auto fiter_prev = fli.before_begin();
	auto fiter = fli.begin();
	while(fiter != fli.end())
	{
		if (*fiter % 2)
		{
			fiter = fli.insert_after(fiter_prev, *fiter);
			++fiter;
			fiter_prev = fiter;
			++fiter;
		}
		else
		{
			fiter = fli.erase_after(fiter_prev);
		}
	}

	std::cout << "Forward List " << std::endl;

	for (auto i: fli)
	{
		std::cout << i << std::endl;
	}



	return 0;
}
