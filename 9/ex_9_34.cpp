#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vi{1,2,3,4,5};

	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter %2)
		{
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}

	for (auto i: vi)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
