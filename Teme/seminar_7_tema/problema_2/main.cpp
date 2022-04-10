#include <iostream>
#include "Vector.h"


bool comp(int a, int b) {
    return a < b;
}

bool eq(int a, int b) {
    return a != b;
}

int main() {
    Vector<int> vector;

    vector.insertAtIndex(100, 0);
    vector.printValues();

    for(int i = 0; i < 20; i++)
        vector.push(i);
    for(int i = 0; i < 10; i++) {
        vector.pop();
        vector.printValues();
    }
    printf("---------------------\n");
    vector.removeAtIndex(7);
    vector.printValues();

    vector.removeAtIndex(0);
    vector.printValues();

    vector.insertAtIndex(100, 4);
    vector.printValues();

    std::cout << vector.count() << '\n';

    printf("----------------------------\n");

    int& x = vector.get(3);
    vector.printValues();
    x = 7;
    vector.printValues();

    printf("----------------------------\n");

    vector.set(90, 1);
    vector.printValues();

    vector.set(90, 100);
    vector.printValues();

    vector.sort();
    vector.sort(comp);
    vector.printValues();

    std::cout << vector.firstIndexOf(100) << "\n";
    std::cout << vector.firstIndexOf(100, eq) << "\n";
    return 0;
}
