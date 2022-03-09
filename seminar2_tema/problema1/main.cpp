#include <iostream>
#include "NumberList.h"

int main() {
    NumberList list;
    list.Init();
    for(int i = 0; i < 10; i++)
        list.Add(i * 3 % 5);
    list.Print();
    std::cout << '\n';
    list.Sort();
    list.Print();
    return 0;
}
