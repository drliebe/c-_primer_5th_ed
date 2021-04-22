#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
	{
		ret *= val--;
	}
	return ret;
}


int fact_for_user()
{
	cout << "Enter integer: " << endl;
	int i = 0;
	cin >> i;
	int j = fact(i);
	return j;
}

int main()
{
	int k = fact_for_user();	
	cout << "Factorial is " << k << endl;

	return 0;
}
