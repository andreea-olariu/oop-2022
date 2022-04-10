//
// Created by Andreea Olariu on 06.04.2022.
//

#ifndef SIMULARE_TEST_EASYHASH_H
#define SIMULARE_TEST_EASYHASH_H

#include "Hash.h"

class EasyHash : public Hash{
public:
    EasyHash() {};
    int hashFunction(char*) override;
};


#endif //SIMULARE_TEST_EASYHASH_H
