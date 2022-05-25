#include <iostream>

template <typename T>
void shiftRight(int n, int index, T** arr, int howMuch) {
    for(auto i = n + howMuch - 1; i >= index + howMuch; i--) {
        std::memcpy(arr[i], arr[i - howMuch], sizeof(T*));
    }
}

template <typename T>
void shiftLeft(int n, int index, T** arr, int howMuch) {
    for(auto i = index; i <= n - 2; i++) {
        std::memcpy(arr[i], arr[i + 1], sizeof(T*));
    }
}