#include <iostream>
#include "Canvas.h"

int main() {
    Canvas C = {10, 10};
    C.DrawRect(2, 2 ,9,9, '*');
    C.Print();
    std::cout << '\n';
    C.Clear();
    C.FillRect(2, 2 ,9,9, '*');
    C.Print();
    C.Clear();
    std::cout << "\n";

    C.DrawCircle(5, 5, 3, '*');
    C.Print();

    std::cout << "\n";

    C.Clear();
    C.FillCircle(5, 5, 3, '*');
    C.Print();
    return 0;
}
