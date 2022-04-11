#include <iostream>
#include "Impartire.h"

void Impartire::printResult(int x, int y) {
    std::cout << "Impartire(" << x << "," << y <<") = " << x / y << "\n";
}

Impartire::Impartire() {
    name = "Impartire";
}
