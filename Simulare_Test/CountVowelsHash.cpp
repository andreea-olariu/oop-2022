//
// Created by Andreea Olariu on 06.04.2022.
//

#include "CountVowelsHash.h"
#include <cstring>

int CountVowelsHash::hashFunction(char *string) {
    char vowels[] = "aeiouAEIOU";
    int counter = 0;
    for(int i = 0; string[i] != '\0'; ++i) {
        if(strchr(vowels, string[i]))
            counter++;
    }
    return counter;
}
