#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>   
#include <algorithm> 
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deck;

		void parseInput(int argc, char **argv);

		std::vector<int> sortVector(std::vector<int>& data);
		std::deque<int> sortDeque(std::deque<int>& data);

		std::vector<size_t> jacobsthalOrder(size_t n);

		template <typename Container>
		void binaryInsert(Container& chain, int value, size_t endIndex);

	public:

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int ac, char **av);
		void displayResult() const;
};

#endif