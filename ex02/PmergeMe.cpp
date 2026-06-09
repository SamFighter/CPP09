#include "PmergeMe.hpp"


//######################################## Constructor/Destructor
PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &toCopy)
{
	*this = toCopy;
	return ;
}

PmergeMe::~PmergeMe()
{
	return ;
}

//######################################## Overload
PmergeMe	&PmergeMe::operator=(const PmergeMe &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->_vec = toCopy._vec;
	this->_deq = toCopy._deq;
	this->_vecTime = toCopy._vecTime;
	this->_deqTime = toCopy._deqTime;
	return (*this);
}

//######## Utils

static bool comparePairs(std::pair<int,int> a, std::pair<int,int> b)
{
    return (a.second < b.second);
}
//######################################## sortVector() Method

std::vector<std::pair<int,int> >		PmergeMe::makeVPair(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
		else
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
	}
	return (pairs);
}

void	PmergeMe::sortVPair(std::vector<std::pair<int, int> > &pairs)
{
	std::sort(pairs.begin(), pairs.end(), comparePairs);
}

std::vector<int>	PmergeMe::sortVBiggest(std::vector<std::pair<int,int> > &pairs)
{
	std::vector<int>	biggest;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		biggest.push_back(pairs[i].second);
	}
	return (biggest);
}


std::vector<int>	PmergeMe::sortVSmallest(std::vector<std::pair<int,int> > &pairs)
{
	std::vector<int>	smallest;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		smallest.push_back(pairs[i].first);
	}
	return (smallest);

}

void	PmergeMe::sortVInsert(std::vector<int> &smallest, std::vector<int> &mainVect)
{
	if (smallest.empty())
	    return ;
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < (int)smallest.size())
		jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);
	int position = binaryVSearch(mainVect, smallest[0]);
	mainVect.insert(mainVect.begin() + position, smallest[0]);
	for (size_t i = 1; i < jacob.size(); i++)
	{
		int current = jacob[i];
		int prev = jacob[i-1];
		for (int j = current; j > prev; j--)
	    {
		    if (j < (int)smallest.size())
			{
				int position = binaryVSearch(mainVect, smallest[j]);
	            mainVect.insert(mainVect.begin() + position, smallest[j]);
		    }
		}
	}
}

int		PmergeMe::binaryVSearch(std::vector<int> &sorted, int toInsert)
{
	int left = 0;
	if (sorted.empty())
		return (0);
	int right = (int)sorted.size() - 1;
	while (left <= right)
	{
		size_t mid = (left + right) / 2;
		if (sorted[mid] == toInsert)
			return (mid);
		if (sorted[mid] < toInsert)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void	PmergeMe::putVStraggler(std::vector<int> &mainVect, int &straggler)
{
	int position = binaryVSearch(mainVect, straggler);
	mainVect.insert(mainVect.begin() + position, straggler);
}

//######################################## main sort Algorithm

void PmergeMe::sortVector(std::vector<int> &input)
{
	int straggler = -1;
	if (input.size() % 2 != 0)
	{
		straggler = input.back();
		input.pop_back();
	}
	std::vector<std::pair<int,int> > pairs = makeVPair(input);
	sortVPair(pairs);
	std::vector<int> biggest = sortVBiggest(pairs);
	std::vector<int> smallest = sortVSmallest(pairs);
	sortVInsert(smallest, biggest);
	if (straggler != -1)
		putVStraggler(biggest, straggler);
	this->_vec = biggest;
}


void PmergeMe::sortDeque(std::deque<int> &input)
{
	int straggler = -1;
	if (input.size() % 2 != 0)
	{
		straggler = input.back();
		input.pop_back();
	}
	std::deque<std::pair<int,int> > pairs = makeDPair(input);
	sortDPair(pairs);
	std::deque<int> biggest = sortDBiggest(pairs);
	std::deque<int> smallest = sortDSmallest(pairs);
	sortDInsert(smallest, biggest);
	if (straggler != -1)
		putDStraggler(biggest, straggler);
	this->_deq = biggest;
}

//####################################### sortDeque() Method

std::deque<std::pair<int,int> >		PmergeMe::makeDPair(std::deque<int> &input)
{
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
		else
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
	}
	return (pairs);

}

void	PmergeMe::sortDPair(std::deque<std::pair<int, int> > &pairs)
{
	std::sort(pairs.begin(), pairs.end(), comparePairs);
}

std::deque<int>		PmergeMe::sortDBiggest(std::deque<std::pair<int,int> > &pairs)
{
	std::deque<int>	biggest;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		biggest.push_back(pairs[i].second);
	}
	return (biggest);
}

std::deque<int>		PmergeMe::sortDSmallest(std::deque<std::pair<int,int> > &pairs)
{
	std::deque<int>	smallest;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		smallest.push_back(pairs[i].first);
	}
	return (smallest);
}

void	PmergeMe::sortDInsert(std::deque<int> &smallest, std::deque<int> &mainDeque)
{
	if (smallest.empty())
		return ;
	std::deque<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < (int)smallest.size())
		jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);
	int position = binaryDSearch(mainDeque, smallest[0]);
	mainDeque.insert(mainDeque.begin() + position, smallest[0]);
	for (size_t i = 1; i < jacob.size(); i++)
	{
		int current = jacob[i];
		int prev = jacob[i-1];
		for (int j = current; j > prev; j--)
	    {
		    if (j < (int)smallest.size())
			{
				int position = binaryDSearch(mainDeque, smallest[j]);
	            mainDeque.insert(mainDeque.begin() + position, smallest[j]);
		    }
		}
	}
}

int		PmergeMe::binaryDSearch(std::deque<int> &sorted, int toInsert)
{
	int left = 0;
	if (sorted.empty())
		return (0);
	int right = (int)sorted.size() - 1;
	while (left <= right)
	{
		size_t mid = (left + right) / 2;
		if (sorted[mid] == toInsert)
			return (mid);
		if (sorted[mid] < toInsert)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void	PmergeMe::putDStraggler(std::deque<int> &mainDeque, int &straggler)
{
	int position = binaryDSearch(mainDeque, straggler);
	mainDeque.insert(mainDeque.begin() + position, straggler);
}

