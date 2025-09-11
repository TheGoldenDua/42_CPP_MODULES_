/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:11:48 by del-ganb          #+#    #+#             */
/*   Updated: 2025/09/11 14:11:49 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <sys/time.h>
#include <iomanip>

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

			 if (chain.empty()) 
    		{
       			chain.push_back(value);
        		return;
    		}

			size_t left = 0;
			size_t right = endIndex;

			while(left <= right)
			{
				size_t mid = (left + right) / 2;

				if(chain[mid] == value)
				{
					chain.insert(chain.begin() + mid, value);
					return;
				}
				else if(chain[mid] < value)
				{
					left = mid + 1;
				}
				else
				{	
					if(mid == 0)
					{
						left = 0;
						break;
					}
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
