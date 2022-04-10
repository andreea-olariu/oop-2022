#include <iostream>
#include "ProcesatorNumarPropozitii.h"

ProcesatorNumarPropozitii::ProcesatorNumarPropozitii() {
    numPhrases = 0;
}

void ProcesatorNumarPropozitii::Proceseaza(char * paragraph) {
    int counter = 0;
    for(int i = 0; paragraph[i] != '\0'; ++i) {
        if(paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!')
            counter++;
    }
    numPhrases += counter;
}

void ProcesatorNumarPropozitii::Print() {
    std::cout << numPhrases << " propozitii\n";
}

ProcesatorNumarPropozitii::~ProcesatorNumarPropozitii() {

}