
#include "ObjectValue.h"
#include <cstring>

ObjectValue::ObjectValue() {
    size = 0;
}

void ObjectValue::add(const char *name, JsonValue *value) {
    strcpy(values[size].name, name);
    values[size].value = value;
    size++;
}

void ObjectValue::print(std::ostream &out) {
    out << '{';
    for(int  i = 0; i < size; i++) {
        out << '"' << values[i].name << "\": ";
        values[i].value->print(out);
        if(i != size-1)
            out << ", ";
    }
    out << "}";
}
