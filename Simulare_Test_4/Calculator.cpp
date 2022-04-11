#include <cstring>
#include "Calculator.h"

Calculator::Calculator() {
    for(int i = 0; i < SIZE; i++)
        operatii[i] = nullptr;
    count = 0;
}

Calculator::operator int() {
    return count;
}

bool Calculator::found(Operatie *op) {
    for(int i = 0; i < count; i++)
        if(strcmp(op->GetName(), operatii[i]->GetName()) == 0)
            return true;
    return false;
}

bool Calculator::operator+=(Operatie* op) {
    if(!found(op)) {
        operatii[count++] = op;
        return true;
    } else {
        return false;
    }
}

bool Calculator::operator[](char * _name) {
    for(int i = 0; i < count; i++)
        if(strcmp(_name, operatii[i]->GetName()) == 0)
            return true;
    return false;
}

bool Calculator::operator-=(char* _name) {
    for(int i = 0; i < count; i++) {
        if(strcmp(_name, operatii[i]->GetName()) == 0) {
            for(int j = i; j < count - 1; j++)
                operatii[j] = operatii[j + 1];
            operatii[--count] = nullptr;
            return true;
        }
    }
    return false;
}

void Calculator::Compute(int x, int y) {
    for(int i = 0; i < count; i++)
        operatii[i]->printResult(x, y);
}

