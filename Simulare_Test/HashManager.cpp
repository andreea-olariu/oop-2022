#include <iostream>
#include "HashManager.h"

HashManager::HashManager() {
    size = 0;
}

Hash*& HashManager::operator[](const char *string) {
    hashes[size++].name = string;
    return hashes[size - 1].hash;
}

void HashManager::print_hashes(char * string) {
    for(int i = 0; i < size; i++) {
        std::cout << hashes[i].name << ": " <<  hashes[i].hash->hashFunction(string) << '\n';
    }
}

