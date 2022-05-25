#ifndef SEMINAR_10_TEMA_EXCEPTIONS_H
#define SEMINAR_10_TEMA_EXCEPTIONS_H
#include <iostream>
#include <stdio.h>

class Exception : public std::exception {
    std::string message;
public:
    Exception(std::string str) : message(str) {};
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class OutOfRangeException : public Exception{
public:
    OutOfRangeException(int index) : Exception(index + "is an index out of range!") {};
};

class InvalidIndexException : public Exception{
public:
    InvalidIndexException(int index) : Exception(index + "is an index is invalid") {};
};

class DeleteException : public Exception{
public:
    DeleteException(int index) : Exception("Can't delete the element from index " + index) {};
};

class NotFoundException : public Exception{
public:
    NotFoundException(int index) : Exception("Can't fint the element at index:  " + index) {};
};

#endif //SEMINAR_10_TEMA_EXCEPTIONS_H
