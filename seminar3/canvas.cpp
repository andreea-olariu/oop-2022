#include "canvas.h"
#include <iostream>
#include <cstring>
#include <stdarg.h>

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;

    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    picture[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    int* p = &count;
    int x, y;
    char value;
    va_list v;
    va_start(v, count);
    for(unsigned i = 0; i < count; i++) {
       x = va_arg(v, int);
       y = va_arg(v, int);
       value = va_arg(v, char);
       set_pixel(x, y, value);
    }
    va_end(v);
}

void Canvas::clear() {
    memset(picture, ' ', sizeof(picture));
}

void Canvas::print() const {
    for(unsigned i = 0; i < lines; i++, std::cout << '\n') {
        for(unsigned j = 0; j < columns; j++)
            std::cout << picture[i][j];
    }
}
