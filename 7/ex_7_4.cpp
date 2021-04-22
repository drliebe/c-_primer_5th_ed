#include <iostream>
#include <string>

using std::string;

class Person
{
public:
	string name() const {return _name;}
	string address() const {return _address;}

public:
	string _name;
	string _address;


};


int main ()
{
	Person bill;
	Person ted;

	bill._name = "Bill";
	ted._name = "Ted";

	std::cout << bill.name() << " and " << ted.name() << std::endl;

	return 0;
}
