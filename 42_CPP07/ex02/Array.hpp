/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:07:12 by del-ganb          #+#    #+#             */
/*   Updated: 2025/07/17 23:10:23 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array
{
    private:
        T* _data;
        size_t _size;

    public:
        Array() : _size(0) , _data(NULL)
        {
        };

        Array(unsigned int n) : _size(n)
        {
            _data = new T[n];
        };

        Array(const Array& other)
        {
           this->_size = other._size;
           this->_data = new T[other._size];

           for(size_t i = 0; i < other._size; i++)
           {
                _data[i] = other._data[i];
           }
        };

        Array& operator=(const Array& other)
        {
           if(*this != other)
           {
                delete[] this->_data;
                this->_size = other._size;
                this->_data = new T[other._size];

                for(size_t i = 0; i < other._size; i++)
                    _data[i] = other._data[i];
           }
           return  *this;
        };

        ~Array()
        {
            delete[] this->_data;
        };

        T& operator[](size_t index)
        {
            if(index >= _size)
                throw OutOfBoundsException();
            return this->_data[index];    
        };

        const T& operator[](size_t index) const
        {
            if(index >= _size)
                throw OutOfBoundsException();
            return this->_data[index];
        };

        size_t size() const
        {
            return (this->_size);
        }

        class OutOfBoundsException : public std::exception
        {
             public:
                const char* what() const throw()
                {
                    return "Index out of bounds!";
                }
        };
};


#endif
