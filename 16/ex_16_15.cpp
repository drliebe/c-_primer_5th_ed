#include <iostream>
#include <string>
#include <cstdio>

template <unsigned W, unsigned H>
class Screen;

template <unsigned W, unsigned H>
std::ostream &operator<<(std::ostream &os, Screen<W,H> &s);

template <unsigned W, unsigned H>
std::istream &operator>>(std::istream &is, Screen<W,H> &s);

template <unsigned W, unsigned H>
class Screen
{
public:
	friend std::ostream &operator<<<W,H>(std::ostream &os, Screen<W,H> &s);
	friend std::istream &operator>><W,H>(std::istream &is, Screen<W,H> &s);
	typedef typename std::string::size_type pos;
	Screen() = default;
	Screen(char c) : contents(H*W,c) {}
	char get() const {return contents[cursor];}
	void set(char c) {contents[cursor] = c; return;}
	inline char get(pos ht, pos wd) const;
	Screen<W,H> &move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = W, width = H;
	std::string contents = std::string(H*W,' ');
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


template <unsigned W, unsigned H>
std::ostream &operator<<(std::ostream &os, Screen<W,H> &s)
{
	for (int row = 0; row<H; ++row)
	{
		for (int column = 0; column<W; ++column)
		{
			os << s.get(row, column);
		}
		os << std::endl;
	}
	return os;
}

template <unsigned W, unsigned H>
std::istream &operator>>(std::istream &is, Screen<W,H> &s)
{
	char temp_c = 0;
	for (int row = 0; row<H; ++row)
	{
		for (int column = 0; column<W; ++column)
		{
			if (is >> temp_c)
			{
				s = s.move(row,column);
				s.set(temp_c);
			}
		}
	}
	return is;
}




int main()
{
	constexpr int wi = 10;
	constexpr int hi = 10;

	Screen<wi,hi> s1;

	char temp_c[3] = {0,0,0};

	for (int i=0; i<hi; ++i)
	{
		for (int j=0; j<wi; ++j)
		{
			s1.move(i,j);
			sprintf(temp_c, "%d", j);
			s1.set(*temp_c);
		}
	}

	std::cout << s1;

	return 0;
}
