#include <iostream>
#include <string>

using std::string;

class Employee
{
public:
	Employee() : name(""), id(next_id++) {}
	Employee(string s) : name(s), id(next_id++) {}
	Employee(const Employee &e) : name(e.name), id(next_id++) {}
	Employee &operator=(const Employee &rhs); 
	static unsigned int next_id;
private:
	string name;
	unsigned int id;
};

unsigned int Employee::next_id = 0;

Employee &Employee::operator=(const Employee &rhs)
{
	name = rhs.name;
	return *this;
}


int main()
{
	Employee e1;
	Employee e2("Josh");
	Employee e3(e2);
	Employee e4;
	e4 = e2;

	return 0;
}
