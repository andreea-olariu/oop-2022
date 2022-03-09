#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100], sep[] = " ", words[100][100];
    char *p;
    int counter = 0;
    scanf("%[^\n]s", sentence);
    p = strtok(sentence, sep);
    while(p) {
        strcpy(words[counter++], p);
        p = strtok(NULL, sep);
    }

    for(int i = 0; i < counter - 1; i++) {
        for(int j = i + 1; j < counter; j++) {
            if(strlen(words[i]) < strlen(words[j])) {
                std::swap(words[i], words[j]);
            }  else if(strlen(words[i]) == strlen(words[j])) {
                if(strcmp(words[i], words[j]) > 0) {
                    std::swap(words[i], words[j]);
                }
            }
        }
    }

    for(int i = 0; i < counter; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}
