#include <iostream>

class Y;

class X
{
	Y *ptr_y;
};

class Y
{
	X obj_x;
};

int main()
{
	X x1;
	Y y1;

	return 0;
}
