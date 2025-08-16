#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>   
#include <algorithm> 
#include <templates>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deck;

		void parseInput(int argc, char **argv);

		template <typename Container>
		Container fordJohnsonSort(Container& data);

		template <typename Container>
		Container makePairs(Container& data);

		std::vector<size_t> jacobsthalSequence(size_t n);

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