#ifndef SIMULARE_TEST_4_CALCULATOR_H
#define SIMULARE_TEST_4_CALCULATOR_H

#define SIZE 101

#include "Operatie.h"

class Calculator {
    Operatie* operatii[SIZE];
    int count;
    bool found(Operatie*);
public:
    Calculator();
    bool operator+=(Operatie*);
    operator int();
    void Compute(int, int);
    bool operator[](char*);
    bool operator-=(char*);
};


#endif //SIMULARE_TEST_4_CALCULATOR_H
