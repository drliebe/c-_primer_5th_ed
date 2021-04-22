#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout << "sizeof(bool): " << sizeof(bool) << " bytes." << endl;
	cout << "sizeof(char): " << sizeof(char) << " bytes." << endl;
	cout << "sizeof(wchar_t): " << sizeof(wchar_t) << " bytes." << endl;
	cout << "sizeof(char16_t): " << sizeof(char16_t) << " bytes." << endl;
	cout << "sizeof(char32_t): " << sizeof(char32_t) << " bytes." << endl;
	cout << "sizeof(short): " << sizeof(short) << " bytes." << endl;
	cout << "sizeof(int): " << sizeof(int) << " bytes." << endl;
	cout << "sizeof(long): " << sizeof(long) << " bytes." << endl;
	cout << "sizeof(long long): " << sizeof(long long) << " bytes." << endl;
	cout << "sizeof(float): " << sizeof(float) << " bytes." << endl;
	cout << "sizeof(double): " << sizeof(double) << " bytes." << endl;
	cout << "sizeof(long double): " << sizeof(long double) << " bytes." << endl;
	int *p = 0;	
	cout << "sizeof(int *): " << sizeof(p) << " bytes." << endl;	
	return 0;
}
