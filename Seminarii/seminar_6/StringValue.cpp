

#include "StringValue.h"
#include <cstring>
StringValue::StringValue(const char *x) {
    strcpy(value, x);
}

void StringValue::print(std::ostream &out) {
    out << "\"" << value << "\"";
}
