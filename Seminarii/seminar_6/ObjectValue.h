#ifndef SEMINAR_6_OBJECTVALUE_H
#define SEMINAR_6_OBJECTVALUE_H

#include "JsonValue.h"

struct ObjectValue : JsonValue {
    struct Pair {
        char name[256];
        JsonValue* value;
    };
    Pair values[16];
    unsigned size;

    ObjectValue();

    void add(const char* name, JsonValue* value);
    void print(std::ostream& out) override;
};

#endif //SEMINAR_6_OBJECTVALUE_H
