#include <iostream>
#include "Adunare.h"

void Adunare::printResult(int x, int y) {
    std::cout << "Adunare(" << x << "," << y <<") = " << x + y << "\n";
}

Adunare::Adunare() {
    name = "Adunare";
}
