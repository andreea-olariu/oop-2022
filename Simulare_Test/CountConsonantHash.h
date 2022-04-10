//
// Created by Andreea Olariu on 06.04.2022.
//

#ifndef SIMULARE_TEST_COUNTCONSONANTHASH_H
#define SIMULARE_TEST_COUNTCONSONANTHASH_H
#include "Hash.h"

class CountConsonantHash : public Hash{
public:
    CountConsonantHash()  {};
    int hashFunction(char*) override;
};


#endif //SIMULARE_TEST_COUNTCONSONANTHASH_H
