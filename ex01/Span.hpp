#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        
        template <typename It>
        void addRange(It begin, It end) {
            for (It it = begin; it != end; ++it) {
                if (_numbers.size() >= _maxSize)
                    throw std::runtime_error("Span is full");
                _numbers.push_back(*it);
            }
        }

        void print() const;
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
};

#endif