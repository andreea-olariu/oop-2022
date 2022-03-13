#include <cstdlib>
#include "allocator.h"

void *Allocator::alloc_raw(unsigned int size) {
    
}
Allocator::Allocator(unsigned int max_size) {
    buffer = (char*)  malloc(max_size);
    offset = 0;
    this->max_size = max_size;
}

Allocator::~Allocator() {
    free(buffer);
}

unsigned *Allocator::alloc(unsigned int x) {
    return nullptr;
}

int *Allocator::alloc(int x) {
    return nullptr;
}

float *Allocator::alloc(float x) {
    return nullptr;
}

double *Allocator::alloc(double x) {
    return nullptr;
}

char *Allocator::alloc(char x) {
    return nullptr;
}

char *Allocator::alloc(const char *string) {
    return nullptr;
}
