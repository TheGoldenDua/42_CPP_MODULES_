/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:47:51 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/30 18:15:10 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits>

class EmptySpanException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Empty array!";
        };
};

class TooManyElementsException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Impossible to add this number!";
        };
};

class NotEnoughElementsException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Need at least two numbers!";
        };
};

class Span
{
    private:
        std::vector<int> v;
        unsigned int N;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

};

#endif
