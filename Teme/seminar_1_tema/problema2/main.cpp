#include <iostream>
#include <stdio.h>

int convertStringToNum(const char *line) { //caractere constante dar nu pointerul
    int res = 0;
    for(int i = 0; line[i] != NULL; i++) {
        res = res * 10  + (line[i] - '0');
    }
    return res;
}

int ex2() {
    int sum = 0;
    char* line = (char*) calloc(100, sizeof(char));
    FILE* file = fopen("../in.txt", "r");
    if(!file) {
        perror("File doesn't exist");
    } else {
        while(!feof(file) && fscanf(file, "%s" ,line)) {
            int num = convertStringToNum(line);
            sum += num;
        }
    }
    fclose(file);
    free(line);
    return sum;
}

int main() {
    int res = ex2();
    printf("Suma numerelor din fisier este: %d\n", res);
    return 0;
}
