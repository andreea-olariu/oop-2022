#include "mylibrary.h"
#include <stdarg.h>

MyLibrary::~MyLibrary() {
    delete[] books;
}


MyLibrary::MyLibrary(const MyLibrary & lib) : output_stream(lib.output_stream){
    books_count = lib.books_count;
    for(int i = 0; i < books_count; i++) {
        books[i] = lib.books[i];
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream) : output_stream(output_stream){
    books_count = 0;
    books = nullptr;
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int *books) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[books_count];
    for(unsigned i = 0; i < this->books_count; i++) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, int min, int max) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[books_count];
    for(unsigned i = 0; i < books_count; i++) {
        this->books[i] = rand() % (max - min + 1) + min;
    }
}

int counter(const char *string) {
    int c = 0;
    for(unsigned i = 0; string[i] != '\0'; i++) {
        if(string[i] == ';')
            c++;
    }
    return c;
}

MyLibrary::MyLibrary(std::ostream &output_stream, const char *books_values) : output_stream(output_stream){
    this->books_count = counter(books_values) + 1;
    this->books = new int[this->books_count];
    unsigned i = 0;
    int j = 0;
    while(i < this->books_count && books_values[j] != '\n') {
        if(books_values[j] != ';') {
            this->books[i] = this->books[i] * 10 + (books_values[j] - '0');
            j++;
        } else {
            i++;
            j++;
        }
    }
    while(books_values[j] != '\n') {
        this->books[i] = this->books[i] * 10 + (books_values[j] - '0');
        j++;
    }
}

MyLibrary::MyLibrary(std::ostream &output_stream, unsigned int books_count, ...) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[this->books_count];
    va_list books_ids;
    va_start(books_ids, this->books_count);
    for(int i = 0; i < this->books_count; i++) {
        int id = va_arg(books_ids, int);
        this->books[i] = id;
    }
    va_end(books_ids);
}

void MyLibrary::print_books() const {
    if(books_count == 0) {
        output_stream << -1 << '\n';
    } else {
        output_stream << "Numarul de carti este: " << books_count << "\n";
        for(unsigned i = 0; i < books_count; i++) {
            output_stream << books[i] << " ";
        }
        output_stream << '\n';
    }
}

void MyLibrary::update_book_id_by_index(unsigned int book_index, int book_id) {
    if(book_index >= 0 && book_index < books_count) {
        books[book_index] = book_id;
    }
}

unsigned MyLibrary::get_books_count() const {
    return books_count;
}

int MyLibrary::get_book_id_by_index(int index) const {
    if(index < 0 || index >= books_count) {
        return -1;
    } else {
        return books[index];
    }
}

