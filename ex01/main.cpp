#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << _RED << "Error: one argument needed, exemple > ./RPN \"1 2 + 4 6 * -\"" << _END << std::endl;
		return (1);
	}
	try
	{
		RPN stack;
		int val = stack.tokenHandler(av[1]);
		std::cout << _GREEN << val << _END << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << _END << std::endl;
		return (1);
	}
	return (0);
}
