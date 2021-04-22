#include <iostream>
#include <string>
#include <vector>

class ReadString
{
public:
	ReadString(std::istream &i = std::cin) :  is(i) { }
	std::string operator()(void);
private:
	std::istream &is;
};

std::string ReadString::operator()(void)
{
	std::string temp;
	std::cin >> temp;
	if (std::cin)
		return temp;
	else 
		return std::string("");
}

int main()
{
	std::vector<std::string> vec;
	ReadString reader;
	std::string input;
	
	while ( (input = reader()) != "" )
		vec.push_back(input);


	for(auto s : vec)
		std::cout << s << std::endl;

	return 0;
}
