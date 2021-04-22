#include <iostream>
#include <vector>
#include <algorithm>

class EqualTest
{
public:
	EqualTest(const int val = 0) : i(val) { }
	bool operator()(const int &j);
private:
	const int i;
};

bool EqualTest::operator()(const int &j)
{
	return i==j;
}


int main()
{
	std::vector<int> vec = {1,2,3,4,5,6,5,4,3,2,1};
	EqualTest et(4);
	replace_if(vec.begin(), vec.end(), et, 12);
	
	for(auto i : vec)
		std::cout << i << " ";

	std::cout << std::endl;

	return 0;

}
