#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> ivec;

	for(int i=0; i <130; ++i)
	{
		std::cout << "Size: " << ivec.size() << " Capacity: " << ivec.capacity() << std::endl;
		ivec.push_back(i);
	}
	return 0;
}	
