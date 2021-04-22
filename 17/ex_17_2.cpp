#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <utility>

int main()
{
	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> 
		t("hello", {"there", "I", "am", "Josh"}, std::make_pair<std::string, int>("one",2));

	std::cout << std::get<0>(t) << " ";
	for (auto s : std::get<1>(t))
		std::cout << s << " ";

	std::cout << std::get<2>(t).first << " " << std::get<2>(t).second << std::endl;

	return 0;
}
