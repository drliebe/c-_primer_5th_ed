#include <iostream>
#include <string>

class Screen
{
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd,c) {}
	char get() const {return contents[cursor];}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline char Screen::get(pos r, pos c) const
{
	pos row = r*width;
	return contents[row+c];
};

Screen &Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
};



int main()
{
	Screen s1;
	Screen s2(10, 20);
	Screen s3(5, 10, 'b');

	Screen s4;
	s4 = s3;

	return 0;
}
