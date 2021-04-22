#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	//v1
	decltype(v1.size()) v1_size = v1.size();
	cout << "v1 size: " << v1_size << endl;
	for(auto i : v1)
	{
		cout << i << endl;
	}


	//v2
	decltype(v2.size()) v2_size = v2.size();
	cout << "v2 size: " << v2_size << endl;
	for(auto i : v2)
	{
		cout << i << endl;
	}


	//v3
	decltype(v3.size()) v3_size = v3.size();
	cout << "v3 size: " << v3_size << endl;
	for(auto i : v3)
	{
		cout << i << endl;
	}


	//v4
	decltype(v4.size()) v4_size = v4.size();
	cout << "v4 size: " << v4_size << endl;
	for(auto i : v4)
	{
		cout << i << endl;
	}


	//v5
	decltype(v5.size()) v5_size = v5.size();
	cout << "v5 size: " << v5_size << endl;
	for(auto i : v5)
	{
		cout << i << endl;
	}

	//v6
	decltype(v6.size()) v6_size = v6.size();
	cout << "v6 size: " << v6_size << endl;
	for(auto i : v6)
	{
		cout << i << endl;
	}


	//v7
	decltype(v7.size()) v7_size = v7.size();
	cout << "v7 size: " << v7_size << endl;
	for(auto i : v7)
	{
		cout << i << endl;
	}

	return 0;
}
