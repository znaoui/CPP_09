#include "BitcoinExchange.hpp"

/*********** AFFICHAGE **********/

void affichage_map(std::map<std::string, double>  map)
{
	int i = 0;
	for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); it++)
	{
		i++;
		std::cout << "list " << i << " < " << it->first << ", " << it->second << " >"<< std::endl;
	}
}

/*********** READING **********/

void check_arg(int argc, char ** argv)
{
	if (argc != 2)
		throw std::string("Error : Wrong number of arguments !\n");
	(void)argv;
}

/********** READ_FILE **********/

double stringtodouble(std::string value)
{
	return static_cast<double>(std::strtod(value.c_str(), NULL));
}

std::pair<std::string, double> parse_to_pair (std::string str, char c)
{
	std::string s1;
	std::string s2;

	int i = -1;
	while ( ++i < static_cast<int>(str.size()) && str[i] != c)
		if (str[i] != ' ')
			s1.append(str, i, 1);
	while ( str[++i] )
		if (str[i] != ' ')
			s2.append(str, i, 1);
	std::pair<std::string, double> my_pair = std::make_pair(s1, stringtodouble(s2));
	return my_pair;
}

std::map<std::string, double> open_and_check_conf_file(std::string file, char c)
{
	std::ifstream	flux(file.c_str());
	std::map<std::string, double> list_conf;
	std::string line;

	if (!flux.is_open())
		throw std::string("Error : Unable to open the file !\n");
	getline(flux, line);
	while (!flux.eof() && getline(flux, line))
	{
		if (!line.empty() && line.find(c) != std::string::npos )
			list_conf.insert(parse_to_pair(line, c));
	}
	return list_conf;
}

int check_valid_format(std::string str)
{
	std::string format = "XXXX-XX-XX | ";
	size_t j(0);

	for (size_t i = 0; i < format.size() ; i++)
	{
		if (format[i] == 'X' && !isdigit(str[i]))
			return 0;
		else if ((format[i] == '-' || format[i] == '|' || format[i] == ' ') && format[i] != str[i])
			return 0;
		j = i;
	}
	j++;
	size_t count = 0;
	for (size_t i = j; i < str.size(); i++)
	{
		if (str[j] == '-')
			i++;
		else if (str[i] == '.')
			count++;
		else if (!isdigit(str[i]))
			return 0;
		if (count > 1)
			return 0;
	}
	return 1;
}

int check_valid_data(std::string str, std::map<std::string, double> mapData)
{
	std::string mois = str.substr(5, 2);
	std::string day = str.substr(8, 2);
	std::string date = str.substr(0, 10);
	std::map<std::string, double>::iterator it =  mapData.begin();
	std::map<std::string, double>::reverse_iterator it_end =  mapData.rbegin();

	if (it->first.compare(date) > 0)
		return 0;
	if (it_end->first.compare(date) < 0)
		return 0;
	if (atoi(mois.c_str()) < 1 || atoi(mois.c_str()) > 12)
		return 0;
	if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
		return 0;

	return 1;
}

void serch_and_print(std::map<std::string, double> mapData, std::string file)
{
	std::ifstream	flux(file.c_str());
	std::string line;
	std::pair <std::string, double> myPair;
	char c = '|';

	if (!flux.is_open())
		throw std::string("Error : Unable to open the file !\n");
	getline(flux, line);
	while (!flux.eof() && getline(flux, line))
	{
		if (!line.empty())
		{
			if (!check_valid_format(line))
				std::cout << "Error: bad input => " << line << std::endl;
			else if (!check_valid_data(line, mapData))
				std::cout << "Error: bad input => " << line << std::endl;

			else
			{
				myPair = parse_to_pair(line, c);

				std::map<std::string, double>::iterator itup = mapData.lower_bound(myPair.first);

				if (myPair.second < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (myPair.second > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
				{
					if (itup->first.compare(myPair.first) > 0)
						itup--;
					std::cout << myPair.first << " => " << myPair.second <<  " = " << itup->second * myPair.second << std::endl;

				}
			}
		}
	}
}