#include <iostream>
#include "Sort.h"
int main() {
    // s1 -> variadic parameters
    Sort s1{7, 12, 5, 10, 1, 90, 5, 3};
    s1.QuickSort(0, 7);
    s1.Print();
    std::cout << "\n";
    int v[10] = {4, 2, 3, 10, 8, 21, 1, 0, -1, 90};
    // s2 -> vector + count
    Sort s2(v, 10);
    s2.InsertSort();
    s2.Print();
    std::cout << "\n";
    // s3 -> counter, min, max
    Sort s3(9, 40, 100);
    s3.BubbleSort();
    s3.Print();
    std::cout << "\n";
    //s4 -> "1,2,3"
    Sort s4("1,4,10,0,23,90");
    s4.InsertSort();
    s4.Print();
    return 0;
}
