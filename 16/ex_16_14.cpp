#include <iostream>
#include <string>

template <unsigned W, unsigned H>
class Screen
{
public:
	typedef typename std::string::size_type pos;
	Screen() = default;
	Screen(char c) : contents(H*W,c) {}
	char get() const {return contents[cursor];}
	inline char get(pos ht, pos wd) const;
	Screen<W,H> &move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = W, width = H;
	std::string contents;
};


template <unsigned W, unsigned H>
inline char Screen<W,H>::get(pos r, pos c) const
{
	pos row = r*width;
	return contents[row+c];
};

template <unsigned W, unsigned H>
Screen<W,H> &Screen<W,H>::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
};



int main()
{
	Screen<10,10> s1;

	return 0;
}
