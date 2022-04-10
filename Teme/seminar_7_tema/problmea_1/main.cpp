#include <iostream>
#include "Literals.h"
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << " " << b;
    return 0;
}
