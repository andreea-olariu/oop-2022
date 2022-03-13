#include <cstring>
#include <stdarg.h>
#include "Math.h"

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return a + b;
}

int Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return a * b;
}

int Math::Mul(double a, double b, double c) {
    return a * b * c;
}

int Math::Add(int count, ...) {
    va_list v;
    va_start(v, count);
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += va_arg(v, int);
    }
    va_end(v);
    return sum;
}

char *Math::Add(const char *s1, const char *s2) {
    if(s1 == nullptr || s2 == nullptr) {
        return nullptr;
    }
    else {
        char *result = new char[100];
        strcpy(result, s1);
        strcat(result, s2);
        return result;
    }
}

