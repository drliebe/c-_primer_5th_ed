#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

	vector<int> via(ia, ia+11);
	list<int> lia(ia, ia+11);

	auto vit = via.begin();
	while (vit != via.end())
	{
		if (*vit % 2 == 0)
			vit = via.erase(vit);
		else
			++vit;
	}

	auto lit = lia.begin();
	while (lit != lia.end())
	{
		if (*lit % 2 == 1)
			lit = lia.erase(lit);
		else
			++lit;
	}


	std::cout << "Vector: " << std::endl;
	for(auto i : via)
		std::cout << i << std::endl;

	std::cout << "List: " << std::endl;
	for(auto i : lia)
		std::cout << i << std::endl;

	return 0;
}
