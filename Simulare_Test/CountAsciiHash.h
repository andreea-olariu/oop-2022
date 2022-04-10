//
// Created by Andreea Olariu on 06.04.2022.
//

#ifndef SIMULARE_TEST_COUNTASCIIHASH_H
#define SIMULARE_TEST_COUNTASCIIHASH_H
#include "Hash.h"

class CountAsciiHash : public Hash {
public:
    CountAsciiHash() {};
    int hashFunction(char*) override;
};


#endif //SIMULARE_TEST_COUNTASCIIHASH_H
