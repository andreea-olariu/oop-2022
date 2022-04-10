
#include "EasyHash.h"
#include <cstring>
int EasyHash::hashFunction(char * string) {
    char vowels[] = "aeiouAEIOU";
    int sum = 0;
    for(int i = 0; string[i] != '\0'; ++i) {
        if(strchr(vowels, string[i]))
           sum += (int)(string[i]) * 10;
        else {
            if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
                sum += (int)(string[i]) * 11;
            else
                sum += (int)(string[i]) * 12;
        }
    }
    return sum;
}
