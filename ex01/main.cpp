#include "RPN.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "Error: bad number of arguments!";
		RPN rpn;
		std::cout << rpn.calcul(argv[1]) << std::endl;
	}
 	catch(const char *msg)
 	{
 		std::cerr << msg << '\n';
 	}
}