#include <iostream>
#include <string>

using std::string;

string form_salutation(string nm, string pre, string suf)
{
	return pre.append(" ").append(nm).append(" ").append(suf);
}

int main()
{
	string name("Joshua");
	string prefix("Dr.");
	string suffix("IV");

	string full_salutation;

	full_salutation = form_salutation(name, prefix, suffix);

	std::cout << full_salutation << std::endl;

	return 0;
}
