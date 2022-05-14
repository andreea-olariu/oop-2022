#include <iostream>
#include "Map.h"
int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    printf("\n");
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Delete(60);
    printf("\n");
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    const char* v;
    m.Get(10, v);
    printf("%s\n", v);

    printf("Este mapul empty?\n");
    m.Clear();
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}