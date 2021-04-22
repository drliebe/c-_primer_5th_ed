#include <iostream>

class Base
{
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};


struct Pub_Derv : public Base
{
public:
	int f() {return prot_mem;}
};


struct Prot_Derv : protected Base
{
public:
	int f1() const { return prot_mem; }
};


struct Priv_Derv : private Base
{
public:
	int f2() const { return prot_mem; }
};


struct Derived_from_Public : public Pub_Derv
{
public:
	int use_base() {return prot_mem;}
};

struct Derived_from_Protected : public Prot_Derv
{
public: 
	int use_base() {return prot_mem;}
};


struct Derived_from_Private : public Priv_Derv
{
public: 
//	int use_base() {return prot_mem;}
};

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	p = &d2;
	p = &d3;
	p = &dd1;
	p = &dd2;
	p = &dd3;


	return 0;
}
