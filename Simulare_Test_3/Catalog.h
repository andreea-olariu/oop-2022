#ifndef SIMULARE_TEST_3_CATALOG_H
#define SIMULARE_TEST_3_CATALOG_H

#include "Student.h"
#define SIZE 101

class Catalog {
    Student Students[SIZE];
    int counter;
public:
    Catalog();
    int GetCount();
    bool operator+=(Student);
    Student& operator[](const char*);
    Student operator[](int);
};


#endif //SIMULARE_TEST_3_CATALOG_H
