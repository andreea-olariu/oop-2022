#include <iostream>
#include "Inmultire.h"

void Inmultire::printResult(int x, int y) {
    std::cout << "Inmultire(" << x << "," << y <<") = " << x * y << "\n";
}

Inmultire::Inmultire() {
    name = "Inmultire";
}
