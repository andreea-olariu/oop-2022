#ifndef PROBLEMA_2_ALLOCATOR_H
#define PROBLEMA_2_ALLOCATOR_H

class Allocator {
    char* buffer;
    unsigned offset;
    unsigned max_size;

    void* alloc_raw(unsigned size);

public:
    Allocator(unsigned max_size);
    ~Allocator();

    unsigned* alloc(unsigned x);
    int* alloc(int x);
    float* alloc(float x);
    double* alloc(double x);
    char* alloc(char x);
    char* alloc(const char* string);
};


#endif //PROBLEMA_2_ALLOCATOR_H
