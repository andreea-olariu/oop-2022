#ifndef SEMINAR_6_JSONVALUE_H
#define SEMINAR_6_JSONVALUE_H

#include <ostream>

struct JsonValue {
    JsonValue() {};
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out) = 0;
};



#endif //SEMINAR_6_JSONVALUE_H
