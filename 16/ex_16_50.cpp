#include <iostream>

//Forward Declarations
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

//Definitions
template <typename T> void f(T t)
{
	std::cout << "f(T t)" << std::endl;
}

template <typename T> void f(const T* p)
{
	std::cout << "f(T* p)" << std::endl;
}

template <typename T> void g(T t)
{
	std::cout << "g(T t)" << std::endl;
}

template <typename T> void g(T* p)
{
	std::cout << "g(T* p)" << std::endl;
}


int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);

	return 0;

}
