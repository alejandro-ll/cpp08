#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        std::cout << "----- Prueba básica -----" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.print();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n----- Prueba con rango -----" << std::endl;
        std::vector<int> vec;
        for (int i = 0; i < 10000; i++)
            vec.push_back(i);

        Span sp2(10000);
        sp2.addRange(vec.begin(), vec.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

        std::cout << "\n----- Excepción al añadir -----" << std::endl;
        Span sp3(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3); // debe lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
