#include <cstring>
#include "Catalog.h"

Catalog::Catalog() {
    for(int i = 0; i < SIZE; i++) {
        Students[i] = Student();
    }
    counter = 0;
}

int Catalog::GetCount() {
    return counter;
}

bool Catalog::operator+=(Student S) {
    Students[counter] = S;
    counter++;
}

Student &Catalog::operator[](const char * name) {
    for(int i = 0; i < counter; i++) {
        if(strcmp(Students[i].GetName(), name) == 0) {
            return Students[i];
        }
    }
}

Student Catalog::operator[](int index) {
    return Students[index];
}