#include <iostream>
#include <cstring>
#include "ListaParagrafe.h"

ListaParagrafe::ListaParagrafe() {
    for(unsigned i = 0; i < SIZE; ++i)
        paragraphs[i] = nullptr;
    counter = 0;
}

void ListaParagrafe::Add(const char *string) {
    paragraphs[counter] = new char[SIZE];
    strcpy(paragraphs[counter++], string);
}

char** ListaParagrafe::begin() {
    return paragraphs;
}

char** ListaParagrafe::end() {
    return paragraphs + counter;
}
