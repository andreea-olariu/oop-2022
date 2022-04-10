//
// Created by Andreea Olariu on 06.04.2022.
//

#include "CountAsciiHash.h"

int CountAsciiHash::hashFunction(char * string) {
    int sum = 0;
    for(int i = 0; string[i] != '\0'; ++i) {
        sum += string[i];
    }
    return sum;
}
