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
		void binaryInsert(Container& chain, int value, size_t endIndex)
		{
			size_t left = 0;
			size_t right = endIndex;

			while(left <= right)
			{
				size_t mid = (left + right) / 2;

				if(chain[mid] == value)
				{
					left = mid;
					break;
				}
				if(chain[mid] < value)
					left = mid + 1;
				else
				{	
					if(mid == 0)
						break;
					right = mid - 1;
				}
			}
			chain.insert(chain.begin() + left, value);
		};

	public:

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int ac, char **av);
		void displayResult() const;
};

#endif