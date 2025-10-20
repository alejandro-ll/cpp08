#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // --- VECTOR ---
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    // --- LIST ---
    std::list<int> l;
    for (int i = 0; i < 5; ++i)
        l.push_back(i * 5);

    try {
        std::list<int>::iterator it = easyfind(l, 15);
        std::cout << "Encontrado en lista: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Lista: " << e.what() << std::endl;
    }

    // --- CASO QUE FALLA ---
    try {
        easyfind(v, 99);
    } catch (std::exception &e) {
        std::cout << "Búsqueda fallida: " << e.what() << std::endl;
    }

    return 0;
}
