#include <iostream>
#include <iomanip>
#include <string>

using std::endl;
using std::cout;

int main()
{
	cout << "boolalpha" << endl;
	cout << std::boolalpha << true << " " << false << endl;
	cout << std::noboolalpha << true << " " << false << endl;

	cout << "showbase" << endl;
	cout << std::showbase << 10 << " " << std::hex << 0x10 << " " << std::oct << 010 << endl;
	cout << std::noshowbase << std::dec << 10 << " " << std::hex << 0x10 << " " << std::oct << 010 << std::dec << endl;

	cout << "showpoint" << endl;
	cout << std::showpoint << 10.0 << endl;
	cout << std::noshowpoint << 10.0 << endl;

	cout << "uppercase" << endl;
	cout << std::uppercase << 1.0E8 << endl;
	cout << std::nouppercase << 1.0E8 << endl;
	
	cout << "fixed" << endl;
	cout << std::fixed << 1.23456E3 << endl;
	cout << "scientific" << endl;
	cout << std::scientific << 1.23456E3 << endl;

	cout << "fixed" << endl;
	cout << std::fixed << std::setprecision(2) << 1.23456E3 << endl;
	cout << "scientific" << endl;
	cout << std::scientific << std::setprecision(2) << 1.23456E3 << endl;


	return 0;
}
