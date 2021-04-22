#include <iostream>
#include <vector>
#include <string>

int main()
{
	int grade = 0;
	std::cout << "Enter Grade (0-100): " << std::endl;
	std::cin >> grade;

	const std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
	std::string lettergrade;
	lettergrade = (grade < 60) ? lettergrade=scores[0] : lettergrade = scores[(grade-50)/10];

	std::cout << "Letter Grade: " << lettergrade << std::endl;

	return 0;
}
