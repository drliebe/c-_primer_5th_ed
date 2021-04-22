#include <iostream>
#include <string>

int main()
{
	std::string most_repeated_string = "";
	int most_times_repeated = 1;

	std::string last_input_string = "";
	int times_just_repeated = 1;
	std::string input_string = "";

	while(std::cin >> input_string)
	{
		if (input_string == last_input_string)
		{
			++times_just_repeated;
			if (times_just_repeated >= most_times_repeated)
			{
				most_times_repeated = times_just_repeated;
				most_repeated_string = input_string;
			}
		} 
		else
		{
			times_just_repeated = 1;
		}

		last_input_string = input_string;
	}

	if (most_times_repeated == 1)
		std::cout << "No words repeated." << std::endl;
	else
		std::cout << most_repeated_string << " was repeated " << most_times_repeated << "times." << std::endl;

	return 0;
}
