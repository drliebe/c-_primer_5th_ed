#include <iostream>
#include <vector>


template <typename T>
void print(T &c)
{
	typename T::size_type sz = c.size();
	for (typename T::size_type i=0; i<sz; ++i)
	{
		std::cout << c[i] << std::endl;
	}
	return;
}




int main()
{
	std::vector<int> vi = {1,2,3,4,5};
	print(vi);

	return 0;
}
