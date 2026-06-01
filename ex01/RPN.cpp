#include "RPN.hpp"

//======================== Constructor/Destructor
RPN::RPN(void)
{
	return ;
}

RPN::RPN(const RPN &toCopy)
{
	*this = toCopy;
	return ;
}

RPN::~RPN(void)
{
	return ;
}

//======================== Overload
RPN		&RPN::operator=(const RPN &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->_stack = toCopy._stack;
	return (*this);
}

//======================== Public Method
int	RPN::tokenHandler(std::string expr)
{
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (std::isdigit(expr[i]))
			this->_stack.push(expr[i] - '0');
		else if (std::isspace(expr[i]))
			continue;
		else if (expr[i] == '+' || expr[i] == '*' || expr[i] == '-' || expr[i] == '/')
			this->_stack.push(calculate(expr[i]));
		else
			throw std::runtime_error("Error: invalid character '" + std::string(1, expr[i]) + "'");
	}
	if (this->_stack.size() > 1)
		throw std::runtime_error("Error: Not enough operator to sort all the argument");
	else
		return (this->_stack.top());
}

int		RPN::calculate(char op)
{
	if (this->_stack.size() < 2)
		throw std::runtime_error("Error: Not enough operator to sort all the argument");
	int x = this->_stack.top();
	this->_stack.pop();
	int y = this->_stack.top();
	this->_stack.pop();

	if (op == '+')
		return (x + y);
	else if (op == '*')
		return (x * y);
	else if (op == '-')
		return (y - x);
	else if (op == '/')
	{
		if (x == 0)
			throw std::runtime_error("Error: division by zero.");
		return (y / x);
	}
	else
		throw std::runtime_error("Error: not matching any operator.");
}

