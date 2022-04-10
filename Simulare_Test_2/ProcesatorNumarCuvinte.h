#ifndef SIMULARE_TEST_2_PROCESATORNUMARCUVINTE_H
#define SIMULARE_TEST_2_PROCESATORNUMARCUVINTE_H

#include "Procesator.h"
class ProcesatorNumarCuvinte : public Procesator{
    int numWords;
    char* words[SIZE];
    int* freq;
public:
    ProcesatorNumarCuvinte();
    void Proceseaza(char*) override;
    void Print() override;
    ~ProcesatorNumarCuvinte();
};


#endif //SIMULARE_TEST_2_PROCESATORNUMARCUVINTE_H
