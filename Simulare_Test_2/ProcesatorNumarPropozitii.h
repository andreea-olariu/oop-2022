#ifndef SIMULARE_TEST_2_PROCESATORNUMARPROPOZITII_H
#define SIMULARE_TEST_2_PROCESATORNUMARPROPOZITII_H

#include "Procesator.h"
class ProcesatorNumarPropozitii : public Procesator{
    int numPhrases;
public:
    ProcesatorNumarPropozitii();
    void Proceseaza(char*) override;
    void Print() override;
    ~ProcesatorNumarPropozitii();
};

#endif //SIMULARE_TEST_2_PROCESATORNUMARPROPOZITII_H
