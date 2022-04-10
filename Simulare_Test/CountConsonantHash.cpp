//
// Created by Andreea Olariu on 06.04.2022.
//

#include "CountConsonantHash.h"
#include <cstring>
int CountConsonantHash::hashFunction(char * string) {
    char vowels[] = "aeiouAEIOU";
    int counter = 0;
    for(int i = 0; string[i] != '\0'; ++i) {
        if(((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) && !strchr(vowels, string[i]))
            counter++;
    }
    return counter;
}
