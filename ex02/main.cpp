#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << _RED << "Error: no arguments." << _END << std::endl;
		return (1);
	}
	std::vector<int> vec;
	std::deque<int>  deq;
	for (int i = 1; i < ac; i++)
	{
		int n = atoi(av[i]);
		if (n <= 0)
		{
			std::cerr << _RED << "Error: invalid argument: " << av[i] << _END << std::endl;
			return (1);
		}
		vec.push_back(n);
		deq.push_back(n);
	}
	std::cout << _RED << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout  << _END << std::endl;

	PmergeMe pm;

	clock_t startVec = clock();
	pm.sortVector(vec);
	clock_t endVec = clock();
	double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	pm.sortDeque(deq);
	clock_t endDeq = clock();
	double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std::cout << _GREEN << "\nAfter: ";
	for (size_t i = 0; i < pm.getVec().size(); i++)
		std::cout << pm.getVec()[i] << " ";
	std::cout << "\n" << _END << std::endl;

	std::cout << _BLUE << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << _END << vecTime << " us" << std::endl;
	std::cout << _BLUE << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << _END << deqTime << " us" << std::endl;

	return (0);
}
