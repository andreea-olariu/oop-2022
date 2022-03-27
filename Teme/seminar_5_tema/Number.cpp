#include <iostream>
#include <cstring>
#include <cmath>
#include "Number.h"

int stringToNum(char * string, int stringBase) {
    int len = strlen(string) - 1;
    int ret = 0;
    int power = pow(stringBase, len);
    for(int i = 0; string[i] != '\0'; i++) {
        int digit = string[i] - '0';
        ret += digit * power;
        power /= stringBase;
    }
    return ret;
}

char* Num10ToString(int x, int base) {
    int size = log2(x) / log2(base);
    if(size != (int)size) {
        size++;
    }
    char* ret = new char[int(size)];
    int index = int(size);
    while(x) {
        int r = x % base;
        char ch = ' ';
        switch(r) {
            case 10:
                ch = 'A';
                break;
            case 11:
                ch = 'B';
                break;
            case 12:
                ch = 'C';
                break;
            case 13:
                ch = 'D';
                break;
            case 14:
                ch = 'E';
                break;
            case 15:
                ch = 'F';
                break;
            default:
                ch = r + '0';
                break;
        }
        ret[index--] = ch;
        x /= base;
    }
    return ret;
}

Number::Number(const char *_value, int _base) {
    base = _base;
    value = new char[strlen(_value) + 1];
    memcpy(value, _value, strlen(_value)  + 1);
    numericalValueBase10 = stringToNum(value, base);
}


Number::Number(char * string) {
    value = new char[strlen(string)];
    memcpy(value, string, strlen(string) + 1);
    base = 10;
    numericalValueBase10 = stringToNum(value, base);
}


Number::Number(int x) {
    base = 10;
    numericalValueBase10 = x;
    value = new char[log2(x) / log2(base)];
    char *res = Num10ToString(x, base);
    memcpy(value, res, strlen(res) + 1);
}


Number::Number(int x, int _base) {
    base = _base;
    numericalValueBase10 = x;
    value = new char[log2(x) / log2(_base)];
    char *res = Num10ToString(x, base);
    memcpy(value, res, strlen(res) + 1);
}


Number::Number(const Number &N) {
    base = N.base;
    value = new char[strlen(N.value) + 1];
    std::memcpy(value, N.value, strlen(N.value)  + 1);
    numericalValueBase10 = N.numericalValueBase10;
}


Number::~Number() {
    delete value;
}

void Number::SwitchBase(int newBase) {
    if(value != nullptr) {
        delete value;
    }
    base = newBase;
    value = new char[log2(numericalValueBase10) / log2(base)];
    char* res = Num10ToString(numericalValueBase10, newBase);
    memcpy(value, res, strlen(res) + 1);
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() {
    return strlen(value);
}

int Number::GetBase() {
    return base;
}

int Number::operator[](int index) {
    return value[index];
}

Number& Number::operator=(const Number&N) {
    delete value;
    value = new char[strlen(N.value) + 1];
    memcpy(value, N.value, strlen(N.value) + 1);
    base = N.base;
    numericalValueBase10 = N.numericalValueBase10;
    return *this;
}

Number operator+(Number N1, const Number &N2) {
    int maxBase = N1.base > N2.base ? N1.base : N2.base;
    return { N1.numericalValueBase10 + N2.numericalValueBase10, maxBase };
}

Number operator-(Number N1, const Number &N2) {
    int maxBase = N1.base > N2.base ? N1.base : N2.base;
    return { abs(N1.numericalValueBase10 - N2.numericalValueBase10), maxBase };
}

bool Number::operator>(const Number &N) {
    return numericalValueBase10 > N.numericalValueBase10;
}

bool operator*=(Number& N1, const Number &N2) {
    N1 = (N1 * N2);
    return true;
}

bool operator+=(Number& N1, const Number &N2) {
    N1 = (N1 + N2);
    return true;
}

bool Number::operator<(const Number &N) {
    return numericalValueBase10 < N.numericalValueBase10;
}

bool Number::operator>=(const Number &N) {
    return numericalValueBase10 >= N.numericalValueBase10;
}

bool Number::operator<=(const Number &N) {
    return numericalValueBase10 <= N.numericalValueBase10;
}

bool Number::operator==(const Number &N) {
    return numericalValueBase10 == N.numericalValueBase10;
}

bool operator-=(Number &N1, const Number &N2) {
    N1 = (N1 - N2);
    return true;
}

bool operator/=(Number &N1, const Number &N2) {
    N1 = (N1 / N2);
    return true;
}

Number operator*(Number N1, const Number &N2) {
    int maxBase = N1.base > N2.base ? N1.base : N2.base;
    return { N1.numericalValueBase10 * N2.numericalValueBase10, maxBase };
}

Number operator/(Number N1, const Number &N2) {
    int maxBase = N1.base > N2.base ? N1.base : N2.base;
    return { N1.numericalValueBase10 / N2.numericalValueBase10, maxBase };
}

int Number::operator--() {
    value[strlen(value) - 1] = '\0';
    return 1;
}

int Number::operator--(int) {
    strcpy(value, value + 1);
    return 1;
}

Number::Number(Number &&N) {
    base = N.base;
    numericalValueBase10 = N.numericalValueBase10;
    char *tmp = N.value;
    delete N.value;
    value = tmp;
    N.base = 0;
    N.numericalValueBase10 = 10;
    printf("Number");
}


