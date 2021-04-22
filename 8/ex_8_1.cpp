#include <iostream>
#include <string>

using std::istream;
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

	read_from_stream(std::cin);
	std::cout << std::endl;
	std::cout << "EOF?: " << std::cin.eof() << std::endl;

	return 0;
}
