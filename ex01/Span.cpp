#include "Span.hpp"

// ----- Canonical -----
Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) {
    *this = other;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// ----- Métodos -----
void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (std::vector<int>::iterator it = sorted.begin(); it + 1 != sorted.end(); ++it) {
        int diff = *(it + 1) - *it;
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

void Span::print() const {
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}
