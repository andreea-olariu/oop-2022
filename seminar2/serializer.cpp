#include "serializer.h"
#include <stdio.h>

bool Serializer::write_buffer(const void *buffer, unsigned int size) {
    return fwrite(buffer, 1, size, file) == size;
}

bool Serializer::write_movie(const Movie &movie) {
    unsigned year = movie.get_year();
    double score = movie.get_score();
    const char* name = movie.get_name();
    if(!write_buffer(&year, sizeof(year)))
        return false;
    if(!write_buffer(&year, sizeof(score)))
        return false;
    if(!write_buffer(&year, sizeof(char)*strlen(name)))
        return false;
}

bool Serializer::init(const char *file_name) {
    file = fopen(file_name, "wb");
    return file != nullptr;
}

void Serializer::close() {
    if(file) {
        fclose(file);
    }
}

bool Serializer::write(const MovieSeries &series) {
    return false;
}
