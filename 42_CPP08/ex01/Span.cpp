#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span& other)
{
    this->N = other.N;
    this->v = other.v;
}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        this->N = other.N;
        this->v = other.v;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if(v.size() >= N)
        throw TooManyElementsException();
    v.push_back(n);
}

int Span::shortestSpan() const
{
    if (v.size() < 2)
        throw NotEnoughElementsException();

    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (v.size() < 2)
        throw NotEnoughElementsException();

    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    int maxElem = sorted.back();
    int minElem = sorted.front();

    int maxSpan = maxElem - minElem;
    return maxSpan;
}