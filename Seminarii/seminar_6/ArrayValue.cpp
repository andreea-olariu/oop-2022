#include "ArrayValue.h"

ArrayValue::ArrayValue() {
    size = 0;
}

bool ArrayValue::add(JsonValue *value) {
   if(size > 16) {
       return false;
   } else {
       values[size++] = value;
       return true;
   }
}

void ArrayValue::print(std::ostream &out) {
    out << '[';
    for(int i = 0; i < size; ++i) {
        values[i]->print(out);
        if(i != size-1)
            out << ",";
    }
    out << ']';
}

ArrayValue::~ArrayValue() {
    for(unsigned i = 0; i < size; i++)
      delete values[i];
}