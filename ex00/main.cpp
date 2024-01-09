#include "BitcoinExchange.hpp"

int main(int argc, char ** argv)
{
	std::map<std::string, double> mapData;
	std::string dataFile = "data.csv";
	try
	{
		check_arg(argc, argv);
		mapData = open_and_check_conf_file(dataFile, ',');
		serch_and_print(mapData, argv[1]);
	}
	catch(const std::string except)
	{
		std::cout << except;
	}
	return 0;
}