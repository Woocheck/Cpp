/* 1. 
 - read a char from stdin ('i', 'd', 'f')
 - read 4 numbers from stdin
 - outputs the biggest number 
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int biggest(std::vector<int>& numbers)
{
	int res = numbers[0];
	for (const auto& number : numbers) 
	{
		if (number > res)
			res = number;
	}

	return res;
}

int main(void)
{
	char myChar {0};
	std::string input = "";
	std::cout << "Enter one of inputracters: i, d or f: ";
    getline(std::cin, input);

	if (input.length() == 1) {
		myChar = input[0];
		if (myChar == 'i' || myChar == 'd' || myChar == 'f') {
			std::cout << "Found " << myChar << std::endl;
		}
	}

	std::vector<int> ints {};
	std::cout << "Enter four numbers. Press enter after each: ";

	int i {0};
	while(true) {
		int number;
		std::string tmp = "";
		getline(std::cin, tmp);
		std::stringstream myStream(tmp);
		myStream >> number;
		ints.push_back(number);
		++i;
		if (i > 3) 
			break;
	}

	std::cout << "You entered: ";
	for (const auto& num : ints) 
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;
	std::cout << "The biggest is: " << biggest(ints) << std::endl;

	return 0;
}
