#ifndef SIMULARE_TEST_HASHMANAGER_H
#define SIMULARE_TEST_HASHMANAGER_H

#include "Hash.h"

class HashManager {
private:
    struct pair{
        Hash* hash;
        const char* name;
    };
    pair hashes[20];
    int size;
public:
    HashManager();
    Hash*& operator[](const char *);
    void print_hashes(char*);
};


#endif //SIMULARE_TEST_HASHMANAGER_H
