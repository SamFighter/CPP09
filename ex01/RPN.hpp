#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN(void);
		~RPN(void);
		RPN(const RPN &toCopy);

		RPN		&operator=(const RPN &toCopy);
		int	tokenHandler(std::string expr);
		int		calculate(char op);
};
