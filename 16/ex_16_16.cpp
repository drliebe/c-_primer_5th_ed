#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

template <typename T>
class Vec
{
public:
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(const Vec<T> &cp);
	Vec<T> &operator=(const Vec<T> &rhs);
	~Vec();
	void push_back(const T &s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t n);
	void resize(size_t n);
	T *begin() const { return elements; }
	T *end() const { return first_free; }

private:
	static std::allocator<T> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};


template <typename T>
std::allocator<T> Vec<T>::alloc;


template <typename T>
void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}


template <typename T>
void Vec<T>::reserve(size_t n)
{
	if (n > capacity())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}


template <typename T>
void Vec<T>::resize(size_t n)
{
	if (n < size())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=n; ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;

	} else if (n > size())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		for (size_t j=size(); j != newcapacity; ++j)
			alloc.construct(dest++, std::string());
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	} else 
	{
	// Already equal in size to n, do nothing.
	}	
}


template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e-b);
	return {data, uninitialized_copy(b,e,data)};
}


template <typename T>
void Vec<T>::free()
{
	if (elements)
	{
		for (auto p= first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);	
	}
}


template <typename T>
Vec<T>::Vec(const Vec<T> &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}


template <typename T>
Vec<T>::~Vec()
{
	free();
}


template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}


template <typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2*size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i=0; i !=size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}


int main()
{
	Vec<std::string> svec;
	svec.push_back("first");
	svec.push_back("second");
	svec.push_back("third");
	
	Vec<std::string> svec2(svec);
	svec2.reserve(6);
	svec2.push_back("fourth");
	for (auto it = svec2.begin(); it != svec2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	svec2.resize(2);

	for (auto it = svec2.begin(); it != svec2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}

