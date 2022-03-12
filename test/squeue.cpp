#include <iostream>

#include <src/SQueue.hpp>

int main() {
    SDS::SQueue<int, 100> sq;

    for (int i = 0; i < 150; i++) {
        sq.put(i);
    }

    while (!sq.empty()) {
        std::cout << sq.get() << " ";
    }

    std::cout << std::endl;
}