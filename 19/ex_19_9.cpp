#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using std::cout; 

int main()
{
	std::string s("Hello world");
	std::vector<int> vi = {1,2,3};
	cout << typeid(42).name() << ", "
	<< typeid(10.0).name() << ", "
	<< typeid('c').name() << ", "
	<< typeid(s).name() << ", "
	<< typeid(vi).name() << std::endl;

	return 0;
}
