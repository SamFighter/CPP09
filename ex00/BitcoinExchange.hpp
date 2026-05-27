#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &toCopy);
		void	loadCSV(std::string data_csv);

	public:
		BitcoinExchange(std::string data_csv);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &toCopy);

		void	searchData(std::string input_csv);
};
