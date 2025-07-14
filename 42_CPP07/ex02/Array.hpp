#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _data;
        size_t _size;

    public:
        Array(/* args */);
        Array(const T& n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](size_t index);
        const T& operator[](size_t) const;

        size_t size() const;

        class OutOfBoundsException :: public std::exception
        {
             public:
                const char* what() const throw();
        }
};


#endif