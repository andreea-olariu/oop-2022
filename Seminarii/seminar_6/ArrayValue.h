#ifndef SEMINAR_6_ARRAYVALUE_H
#define SEMINAR_6_ARRAYVALUE_H

#include "JsonValue.h"

struct ArrayValue : JsonValue {
    JsonValue* values[16];
    unsigned size;

    ArrayValue();

    bool add(JsonValue* value);
    void print(std::ostream& out) override;
    ~ArrayValue();
};

#endif //SEMINAR_6_ARRAYVALUE_H
