#include <iostream>
#include "Compare.h"
#include "ArrayIterator.h"
#include "Array.h"

int compare(const int& a, const int& b) {
    if(a < b) {
        return 1;
    } else if(a == b) {
        return 0;
    }
    return -1;
}

int main() {
    Array<int> a(100);
    a += 3;
    a += 4;
    a += 5;
    a.print();

    a.Insert(1, 10);
    a.print();
    std::cout << "###################################\n";
    Array<int> b(a);
    b.print();

    Array<int> c(5);
    c += 7;
    c += 11;
    b.Insert(2, c);
    b.print();


    b.Delete(3);
    b.print();


    std::cout << b.Find(4) << '\n';

    Array<int> d(100);
    d += 1;
    d += 2;
    d += 4;
    d += 10;
    d += 5;
    d += 6;
    d += 0;
    std::cout << d.BinarySearch(5) << '\n';

    b.Sort();
    b.print();

    d.Sort(compare);
    d.print();

    std::cout << d.BinarySearch(5);
    return 0;
}
