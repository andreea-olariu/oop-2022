#include <iostream>
#include "Scadere.h"

void Scadere::printResult(int x, int y) {
    std::cout << "Scadere(" << x << "," << y <<") = " << x - y << "\n";
}

Scadere::Scadere() {
    name = "Scadere";
}
