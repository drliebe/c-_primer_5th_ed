#include <iostream>
#include <string>

using std::string;

int main()
{

	int grade = 0;
	string finalgrade = "";
	
        std::cout << "Enter grade: " << std::endl;
	std::cin >> grade;

	finalgrade = (grade>90) ? "high pass" : (grade < 60 ) ? "fail" : (grade <= 75) ? "low pass" : "pass";

	std::cout << finalgrade << std::endl;

	if(grade > 90)
	{
		finalgrade = "high pass";

	} else if (grade > 75)
	{
		finalgrade = "pass";

	} else if (grade >= 60)
	{
		finalgrade = "low pass";

	} else
	{
		finalgrade = "fail";
	}

	std::cout << finalgrade << std::endl;

	return 0;
}
