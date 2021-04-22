#include <iostream>
#include <string>


using std::string;
using std::ostream;
using std::istream;

class Person;
istream &read(istream &is, Person &p);

class Person
{
public:
	Person() = default;
	Person(string n) : _name(n)                        { }
	Person(string n, string a) : _name(n), _address(a) { }
	Person(istream &is)                                {read(is, *this);}
	string name() const                                {return _name;}
	string address() const                             {return _address;}
	friend istream &read(istream &is, Person &p);
private:
	string _name;
	string _address;
};


istream &read(istream &is, Person &p)
{
	getline(is,p._name);
	getline(is,p._address);

	return is;
}

ostream &print(ostream &os, const Person &p)
{
	os << p.name() << std::endl << p.address();

	return os;
}

int main ()
{
	Person p1;

	std::cout << "Enter Person 1's Name and Address: " << std::endl;
	read(std::cin, p1);

	std::cout << "I heard : " << std::endl;
	print(std::cout, p1) << std::endl;


	return 0;
}
