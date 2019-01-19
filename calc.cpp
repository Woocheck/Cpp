/*
 * - read all arguments to program
 * - if -h || --help - print help
 * - if -v || --verbose - print all arguments
 * - if -f=N - calculate N*N and check if 2*N-1 is prime
 */
#include <iostream>
#include <string>
#include <vector>

void help(std::string app)
{
	std::cout << "Usage:" << std::endl;
	std::cout << app << " [-h|--help] | [-v|--verbose] | [-f=N]" << std::endl;
	std::cout << "\t-h | --help\t\tprint this help" << std::endl;
	std::cout << "\t-v | --verbose\t\tprint all arguments passed" << std::endl;
	std::cout << "\t-f=N\t\t\tdo calculations" << std::endl;
}

int power(int N)
{   
    return N*N;
}

void is_prime(int N)
{
    bool isPrime;
    for(int i = 2; i <= N / 2; ++i)
  {
      if(N % i == 0)
      {
          isPrime = false;
          break;
      }
  }
  if (isPrime)
      std::cout << "This is a prime number\n";
  else
      std::cout << "This is not a prime number\n";

}

int main(int argc, char *argv[])
{
	std::vector<std::string> args {argv+1 , argv + argc};

	for (const auto& option : args)
	{
		if (option == "-h" || option == "--help") {
			help(argv[0]);
		} 
		else if (option == "-v" || option == "--verbose") {
			for (const auto& out : args)
			{
				std::cout << out << std::endl;
			}
		} 
        else if (option.find("-f=") != std::string::npos) {
			if (option.size() > 3) {
				int n = std::stoi(option.substr(3));
				std::cout << "Power: " << power(n) << std::endl;
                is_prime(n);
            }

		} 
        else {
			help(argv[0]);
		}
	}

	return 0;
}