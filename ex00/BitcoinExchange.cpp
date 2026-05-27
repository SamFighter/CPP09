#include "BitcoinExchange.hpp"

//=================== Constructor/Destructor

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &toCopy)
{
	*this == toCopy;
	return;
}

BitcoinExchange::BitcoinExchange(std::string data_csv)
{
	loadCSV(data_csv);
}

//=================== Overload

//=================== Regex

static bool        checkPattern(const char *pattern, std::string line)
{
	regex_t reg;
	bool	valid = false;
	regcomp(&reg, pattern, REG_EXTENDED);
	if (regexec(&reg, line.c_str(), 0, NULL, 0) == 0)
		valid = true;
	regfree(&reg);
	return (valid);
}

static bool        checkDate(std::string date)
{
	unsigned int	years;
	unsigned int	months;
	unsigned int	days;

	years = atoi(date.substr(0, 4).c_str());
	if (years < 2009)
		return (false);
	months = atoi(date.substr(5, 2).c_str());
	if (months > 12 || months < 1)
		return (false);
	days = atoi(date.substr(8, 2).c_str());
	if (days < 1)
		return (false);
	if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0 )
	{
		if (months == 2 && days > 29)
			return (false);
	}
	else if (months == 2 && days > 28)
	    return (false);
	if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12)
	{
		if (days > 31)
			return (false);
	}
	if (months == 4 || months == 6 || months == 9 || months == 11)
	{
		if (days > 30)
			return (false);
	}
	return (true);
}

static bool        checkValue(double value)
{
	if (value > 1000 || value < 0)
		return (false);
	return (true);
}

static bool        checkFormatData(std::string line)
{
	const char	*pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2},[0-9]{1,}(\\.[0-9]{1,}){0,1}$";
	return (checkPattern(pattern, line));
}

static bool        checkFormatInput(std::string line)
{
	const char	*pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| -?[0-9]{1,}(\\.[0-9]{1,}){0,1}$";
	return (checkPattern(pattern, line));
}

//=================== Private Method

void	BitcoinExchange::loadCSV(std::string data_csv)
{
	std::ifstream	file(data_csv.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cerr << _RED << "Error: could not open file." << _END << std::endl;
		return ;
	}
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << _RED << "Error: first line of data.csv must be \"date,exchange_rate\"" << _END << std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		if (!checkFormatData(line))
		{
			std::cerr << "Error: bad data => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, 10);
		size_t pos = line.find(",");
		double btc = std::strtod(line.substr(pos + 1).c_str(), NULL);
		this->_data[date] = btc;
	}
}

//=================== Public Method

void	searchData(std::string input_csv)
{
    std::ifstream	file(input_csv.c_str());
	std:string		line;

	if (!file.is_open())
	{
		std::cerr << _RED << "Error: could not open file." << _END << std::endl;
		return ;
	}
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << _RED << "Error: first line of data.csv must be \"date | value\"" << _END << std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		if (!checkFormatInput(line))
		{
			std::cerr << _RED << "Error: bad input => " << line << _END << std::endl;
			continue ;
		}
		if (!checkDate(line.substr(0, 10)))
		{
			std::cerr << _RED << "Error: bad input => " << line << _END << std::endl;
			continue ;
		}
		size_t pos = line.find(",");
		double btc = std::strtod(line.substr(pos + 1).c_str(), NULL);
		if (!checkValue(btc))
		{
			if (btc < 0)
			{
				std::cerr << _RED << "Error: not a positive number." << _END << std::endl;
				continue;
			}
			else
			{
				std::cerr << _RED << "Error: too large a number." << _END << std::endl;
				continue
			}
		}
//	J'ai besoin de faire un iterateur pour utiliser lower_bound, entrain de chercher a faire ca...
	}
}
