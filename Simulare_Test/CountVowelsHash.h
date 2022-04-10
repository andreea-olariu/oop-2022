
#ifndef SIMULARE_TEST_COUNTVOWELSHASH_H
#define SIMULARE_TEST_COUNTVOWELSHASH_H
#include "Hash.h"

class CountVowelsHash : public Hash {
public:
    CountVowelsHash() {};
    int hashFunction(char*) override;
};


#endif //SIMULARE_TEST_COUNTVOWELSHASH_H
