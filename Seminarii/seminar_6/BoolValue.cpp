
#include "BoolValue.h"

BoolValue::BoolValue(bool x) {
    value = x;
}

void BoolValue::print(std::ostream &out) {
    out << (value == 1 ? "true" : "false");
}
