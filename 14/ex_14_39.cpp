#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class TestStringLength
{
public:
	TestStringLength(size_t l = 0) : length(l) { };
	bool operator()(const std::string &s) { return s.size() <= length; }
private:
	size_t length;
};


int main()
{
	std::string filename = "test.txt";
	std::ifstream ifs(filename);

	std::vector<std::string> text;
	std::string word;
	while(ifs >> word)
		text.push_back(word);

	TestStringLength t(9);
	int count_below_10 = count_if(text.begin(), text.end(), t);
	int count_total = text.size();
	std::cout << count_below_10 << " " << count_total-count_below_10 << std::endl;

	return 0;
}



