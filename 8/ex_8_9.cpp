#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::istringstream;
using std::string;

istream &read_from_stream(istream &input_stream)
{
	string s;
	while (input_stream >> s)
	{
		std::cout << s << " ";
	}

	input_stream.clear();

	return input_stream;
};


int main()
{

	string text = "Hello there crazy people!";
	istringstream iss(text);
	


	read_from_stream(iss);
	std::cout << std::endl;
	std::cout << "EOF?: " << std::cin.eof() << std::endl;

	return 0;
}
