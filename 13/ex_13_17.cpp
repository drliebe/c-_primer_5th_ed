#include <iostream>

class numbered
{
public:
	numbered() : mysn(next_sn_granted) {++next_sn_granted;}
	//numbered(const numbered &cp) = default;
	numbered(const numbered &cp) : mysn(next_sn_granted) {++next_sn_granted;}
	int mysn;
	static int next_sn_granted;
};

int numbered::next_sn_granted = 0;

void f(const numbered &s) {std::cout << s.mysn << std::endl;}


int main()
{
	numbered a, b=a, c=b;
	f(a);
	f(b);
	f(c);

	return 0;
}
