#ifndef SEMINAR_6_NULLVALUE_H
#define SEMINAR_6_NULLVALUE_H

#include "JsonValue.h"

struct NullValue : JsonValue {
    NullValue();
    void print(std::ostream& out) override;
};


#endif //SEMINAR_6_NULLVALUE_H
