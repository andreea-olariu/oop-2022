#include <cmath>
#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}


Complex operator+(const Complex& l, const Complex& r) {
    double real = l.real() + r.real();
    double imag = l.imag() + r.imag();
    return {real, imag};
}

Complex operator+(const Complex& l, double r) {
    Complex temp = {r, 0};
    return l + temp;
}

Complex operator+(double l, const Complex& r) {
    Complex temp = {l, 0};
    return temp + r;
}

Complex operator-(const Complex& l, const Complex& r) {
    double real = l.real() - r.real();
    double imag = l.imag() - r.imag();
    return {real, imag};
}

Complex operator-(const Complex& l, double r) {
    Complex temp = {r, 0};
    return l - temp;
}

Complex operator-(double l, const Complex& r) {
    Complex temp = {l, 0};
    return temp - r;
}

Complex operator*(const Complex& l, const Complex& r) {
    double real = l.real() * r.real() - l.imag() * r.imag();
    double imag = l.real() * r.imag() + l.imag() * r.real();
    return {real, imag};
}

Complex operator*(const Complex& l, double r) {
    Complex temp = {r, 0};
    return l * temp;
}

Complex operator*(double l, const Complex& r) {
    Complex temp = {l, 0};
    return temp * r;
}

Complex operator-(const Complex& obj) {
    return {-obj.real(), -obj.imag()};
}

bool operator==(const Complex& l, const Complex& r) {
    return (l.real() == r.real()) && (l.imag() == l.imag());
}


bool operator!=(const Complex& l, const Complex& r) {
    return (l.real() != r.real()) || (l.imag() != r.imag());
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if(complex.imag() != 0 || complex.real() != 0) {
        if(complex.imag() == 0) {
            out << complex.real() << '\n';
        } else if(complex.real() == 0) {
            out << complex.imag() << "i\n";
        } else {
            out << complex.real();
            if(complex.imag() > 0)
                out << '+';
            out << complex.imag() << "i\n";
        }
    }
    return out;
}

Complex Complex::operator++(int) {
    Complex copy = *this;
    real_data++;
    return copy;
}

Complex& Complex::operator++() {
    real_data++;
    return *this;
}

Complex Complex::operator--(int) {
    Complex copy = *this;
    real_data--;
    return copy;
}

Complex& Complex::operator--() {
    real_data--;
    return *this;
}

Complex::Complex(const Complex &C) {
    real_data = C.real_data;
    imag_data = C.imag_data;
}

Complex Complex::operator()(double real, double imag) {
    return Complex(real, imag);
}
