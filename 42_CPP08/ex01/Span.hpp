#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int N;
    
    public:
        Span();
        Span(unsigned int N);
        Span(Span& other);
        Span& operator=(Span& other);
        Span();

        
};

#endif