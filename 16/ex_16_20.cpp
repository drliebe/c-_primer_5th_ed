#include <iostream>
#include <vector>


template <typename T>
void print(T &c)
{
	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return;
}




int main()
{
	std::vector<int> vi = {1,2,3,4,5};
	print(vi);

	return 0;
}
