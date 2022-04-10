#include <iostream>
#include <cstring>
#include "ProcesatorNumarCuvinte.h"


ProcesatorNumarCuvinte::ProcesatorNumarCuvinte() {
    numWords = 0;
    freq = nullptr;
    for(int i = 0; i < SIZE; ++i) {
        words[i] = nullptr;
    }
}

void ProcesatorNumarCuvinte::Proceseaza(char * string) {
    char* stringCopy = new char[SIZE];
    strcpy(stringCopy, string);
    char* p = strtok(stringCopy, " ,.?!");
    bool flag;
    while(p) {
        flag = false;
        for(int i = 0; i < numWords; i++)  {
            if(strcmp(words[i], p) == 0)
                freq[i]++, flag = true;
        }
        if(!flag) {
            words[numWords] = new char[SIZE];
            strcpy(words[numWords], p);
            int* temp = new int[numWords];
            for(unsigned i = 0; i < numWords; ++i) {
                temp[i] = freq[i];
            }
            delete[] freq;
            freq = new int[numWords + 1];
            for(unsigned i = 0; i < numWords; ++i)
                freq[i] = temp[i];
            freq[numWords] = 1;
            numWords++;
            delete[] temp;
        }
        p = strtok(NULL, " ,.?!");
    }
}

void ProcesatorNumarCuvinte::Print() {
    for(unsigned i = 0; i < numWords; ++i) {
        std::cout << words[i] << ": " << freq[i] << '\n';
    }
}

ProcesatorNumarCuvinte::~ProcesatorNumarCuvinte() {
    delete[] freq;
    for(unsigned i = 0; i < numWords; ++i)
        delete words[i];
}