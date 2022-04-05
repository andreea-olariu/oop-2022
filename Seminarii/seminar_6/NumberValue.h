#ifndef SEMINAR_6_NUMBERVALUE_H
#define SEMINAR_6_NUMBERVALUE_H

#include "JsonValue.h"

struct NumberValue : JsonValue {
    long long value;
    NumberValue(long long x) : value(x) {};
    void print(std::ostream& out) override;
    ~NumberValue() {};
};

#endif //SEMINAR_6_NUMBERVALUE_H
