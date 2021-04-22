#include <iostream>
#include <string>

class Screen {
public:
	typedef std::string::size_type pos;
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd) const;

	std::string contents;
	pos cursor = 7;
	pos height, width;
};


int main()
{
	Screen s;

	auto ptrmem = &Screen::cursor;
	std::cout << s.*ptrmem << std::endl;

	return 0;
}
