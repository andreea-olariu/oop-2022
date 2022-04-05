#ifndef SEMINAR_6_STRINGVALUE_H
#define SEMINAR_6_STRINGVALUE_H

#include "JsonValue.h"

struct StringValue : JsonValue {
    char value[256];
    StringValue(const char* x);
    void print(std::ostream& out) override;
};

#endif //SEMINAR_6_STRINGVALUE_H
