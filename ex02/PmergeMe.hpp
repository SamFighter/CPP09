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
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_vecTime;
		double				_deqTime;

		//##### Method for sortVector() #####
		std::vector<std::pair<int,int> >		makeVPair(std::vector<int> &input);
		void									sortVPair(std::vector<std::pair<int, int> > &pairs);
		std::vector<int>						sortVBiggest(std::vector<std::pair<int,int> > &pairs);
		std::vector<int>						sortVSmallest(std::vector<std::pair<int,int> > &pairs);
		void									sortVInsert(std::vector<int> &smallest, std::vector<int> &mainVect);
		int										binaryVSearch(std::vector<int> &sorted, int toInsert);
		void									putVStraggler(std::vector<int> &mainVect, int &straggler);
		//##### Method for sortDeque() #####
		std::deque<std::pair<int,int> >			makeDPair(std::deque<int> &input);
		void									sortDPair(std::deque<std::pair<int, int> > &pairs);
		std::deque<int>							sortDBiggest(std::deque<std::pair<int,int> > &pairs);
		std::deque<int>							sortDSmallest(std::deque<std::pair<int,int> > &pairs);
		void									sortDInsert(std::deque<int> &smallest, std::deque<int> &mainDeque);
		int										binaryDSearch(std::deque<int> &sorted, int toInsert);
		void									putDStraggler(std::deque<int> &mainDeque, int &straggler);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &toCopy);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &toCopy);

		std::vector<int>	getVec() { return (_vec); };
		std::deque<int>		getDeq() { return (_deq); };
		void sortVector(std::vector<int> &input);
		void sortDeque(std::deque<int> &input);
};
