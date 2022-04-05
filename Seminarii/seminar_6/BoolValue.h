#ifndef SEMINAR_6_BOOLVALUE_H
#define SEMINAR_6_BOOLVALUE_H

#include "JsonValue.h"

struct BoolValue : JsonValue {
    bool value;
    BoolValue(bool x);
    void print(std::ostream& out) override;
};

#endif //SEMINAR_6_BOOLVALUE_H
