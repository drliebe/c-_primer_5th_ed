#include <iostream>

class Base
{
public:
	void pub_mem();
	virtual void memfcn(Base &b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};


struct Pub_Derv : public Base
{
public:
	int f() {return prot_mem;}
	void memfcn(Base &b) { b = *this; }
};


struct Prot_Derv : protected Base
{
public:
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};


struct Priv_Derv : private Base
{
public:
	int f2() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};


struct Derived_from_Public : public Pub_Derv
{
public:
	int use_base() {return prot_mem;}
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv
{
public: 
	int use_base() {return prot_mem;}
	void memfcn(Base &b) { b = *this; }
};


struct Derived_from_Private : public Priv_Derv
{
public: 
//	int use_base() {return prot_mem;}
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base b1;
	Base &b = b1;
	d1.memfcn(b);
	d2.memfcn(b);
	d3.memfcn(b);
	dd1.memfcn(b);
	dd2.memfcn(b);
	dd3.memfcn(b);

	return 0;
}
